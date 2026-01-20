#ifdef _WIN32
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#endif

#include <GL/glut.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

//#include <vector>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Define global constants for window size
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 600;

// --- Global variable for scene management ---
enum Scene {
    SCENE_CITY_SCENE
};

Scene currentScene = SCENE_CITY_SCENE;
void initCityScene();
void masterKeyboard(unsigned char key, int x, int y);

// ----------------- City Variables -----------------


float city_manX = 100; // current x position of the man
float city_manY = 120; // current y position of the man
float city_manSpeed = 1.0f; // speed of walking


float city_cloudX1 = 100;
float city_cloudX2 = 300;
float city_cloudX3 = 700;

float city_carX1 = 100;
float city_carX2 = 250;
float city_carX3 = 400;
float city_carX4 = 550;

float city_rainYOffset = 0;

bool city_rainSoundOn = false;
bool city_carSoundOn = false;

struct CityBuilding {
    float x;
    float y;
    float w;
    float h;
    bool dome;
    int colorIndex;
};

//std::vector<CityBuilding> city_buildings;

#define MAX_BUILDINGS 50
CityBuilding city_buildings[MAX_BUILDINGS];
int city_buildingCount = 0;

float city_buildingColors[5][3] = {
    {0.25f, 0.25f, 0.3f},
    {0.4f, 0.4f, 0.45f},
    {0.3f, 0.3f, 0.35f},
    {0.35f, 0.3f, 0.4f},
    {0.2f, 0.2f, 0.25f}
};


// --- Functions from City Scene (prefixed with 'city_') ---
void city_drawCloud(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glColor3f(0.85f, 0.88f, 0.95f);

    float ellipseData[6][3] = {
        {-60, 0, 40},
        {-30, 20, 50},
        {0, 10, 60},
        {30, 20, 50},
        {60, 0, 35},
        {0, -10, 45}
    };

    for (int e = 0; e < 6; e++) {
        glBegin(GL_POLYGON);
        for (int angle = 0; angle <= 360; angle += 10) {
            float rad = angle * M_PI / 180.0f;
            float dx = ellipseData[e][0] + ellipseData[e][2] * cos(rad);
            float dy = ellipseData[e][1] + (ellipseData[e][2] * 0.6f) * sin(rad);
            glVertex2f(dx, dy);
        }
        glEnd();
    }
    glPopMatrix();
}

void city_drawRain() {
    glColor3f(1.0f, 1.0f, 1.0f); // white rain for visibility
    for (int i = 0; i < 300; i++) {
        float x = rand() % WINDOW_WIDTH;
        float y = (rand() % WINDOW_HEIGHT) + city_rainYOffset;

        glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x + 2, y - 6);
        glEnd();

        glBegin(GL_LINES);
        glVertex2f(x + 1, y);
        glVertex2f(x + 3, y - 6);
        glEnd();
    }
}

void city_drawWindows(float x, float y, float w, float h) {
    glColor3f(0.8f, 0.9f, 1.0f);
    for (float i = y + 5; i < y + h - 10; i += 15) {
        for (float j = x + 5; j < x + w - 10; j += 12) {
            glBegin(GL_QUADS);
            glVertex2f(j, i);
            glVertex2f(j + 8, i);
            glVertex2f(j + 8, i + 10);
            glVertex2f(j, i + 10);
            glEnd();
        }
    }
}

void city_drawBuilding(float x, float y, float w, float h, bool dome, int colorIndex) {
    glPushMatrix();
    float r = city_buildingColors[colorIndex][0];
    float g = city_buildingColors[colorIndex][1];
    float b = city_buildingColors[colorIndex][2];

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();

    city_drawWindows(x, y, w, h);

    if (dome) {
        glColor3f(r * 0.7f, g * 0.7f, b * 0.7f);
        glBegin(GL_TRIANGLES);
        glVertex2f(x + w / 2, y + h + 20);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
        glEnd();
    }
    glPopMatrix();
}

void city_drawFence() {
    glPushMatrix();
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(0, 180);
    glVertex2f(WINDOW_WIDTH, 180);
    glVertex2f(WINDOW_WIDTH, 185);
    glVertex2f(0, 185);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0, 210);
    glVertex2f(WINDOW_WIDTH, 210);
    glVertex2f(WINDOW_WIDTH, 215);
    glVertex2f(0, 215);
    glEnd();

    for (int x = 0; x < WINDOW_WIDTH; x += 20) {
        glBegin(GL_QUADS);
        glVertex2f(x, 120);
        glVertex2f(x + 3, 120);
        glVertex2f(x + 3, 215);
        glVertex2f(x, 215);
        glEnd();
    }
    glPopMatrix();
}


    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    for (int angle = 0; angle <= 180; angle += 5) {
        float rad = angle * M_PI / 180.0f;
        glVertex2f(x + 20 + 60 * cos(rad), y + 200 + 30 * sin(rad));
    }
    glEnd();
}



void renderCityScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.7f, 0.8f, 1.0f, 1.0f);

    city_drawCloud(city_cloudX1, 500);
    city_drawCloud(city_cloudX2, 530);
    city_drawCloud(city_cloudX3, 510);

    for (size_t i = 0; i <city_buildingCount ; i++) {
        CityBuilding b = city_buildings[i];
        city_drawBuilding(b.x, b.y, b.w, b.h, b.dome, b.colorIndex);
    }

    city_drawFence();
    city_drawWalkway();
    city_drawRoad();



void initCityScene() {

    city_cloudX1 = 100;
    city_cloudX2 = 300;
    city_cloudX3 = 700;
    city_carX1 = 100;
    city_carX2 = 250;
    city_carX3 = 400;
    city_carX4 = 550;
    city_rainYOffset = 0;
    city_rainSoundOn = false;
    city_carSoundOn = false;

    glClearColor(0.7f, 0.8f, 1.0f, 1.0f); // Sky blue background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    srand((unsigned int)time(NULL));
    //city_buildings.clear();

    city_buildingCount = 0;

    float x = 0;
    while (x < WINDOW_WIDTH) {
        float w = 30 + rand() % 40;
        float h = 150 + rand() % 120;
        bool dome = ((int)(x) / 30) % 4 == 0;
        int colorIndex = rand() % 5;
        CityBuilding b;
        b.x = x;
        b.y = 120;
        b.w = w;
        b.h = h;
        b.dome = dome;
        b.colorIndex = colorIndex;
        //city_buildings.push_back(b);
        city_buildings[city_buildingCount++] = b;
        x += w - 5;
}
   glutTimerFunc(0, city_timer, 0);
    glutMouseFunc(NULL);
    glutPostRedisplay();
    #ifdef _WIN32
    sndPlaySound(NULL, SND_ASYNC); // Stop any previous sound
    #endif

// MAIN
  int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("City Scene");
    initCityScene();
    glutDisplayFunc(renderCityScene);
    glutMainLoop();
    return 0;
}
