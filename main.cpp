
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
    SCENE_PROJECT_FRONT_PAGE,
    SCENE_HOUSES,
    SCENE_CITY_SCENE,
    SCENE_OFFICE_LAYOUT,
    SCENE_FOURTH_WINDOW
};

Scene currentScene = SCENE_PROJECT_FRONT_PAGE;


void initProjectFrontPage();
void initHousesScene();
void initCityScene();
void initOfficeScene();
void initFourthWindow();


void masterKeyboard(unsigned char key, int x, int y);

////////////////1st page ///////

///// DRAW 1ST FRONT PAGE /////////////////

void proj_drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);          // Set text position
    while (*text) {               // Loop until end of text
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        text++;
    }
}


void proj_drawTable() {
    glColor3f(0.2f, 0.2f, 0.2f);

    // Horizontal lines (Header + 5 rows)
    for (int i = 0; i <= 6; i++) {
        glBegin(GL_LINES);
        glVertex2f(300, 350 - i * 40);
        glVertex2f(1000, 350 - i * 40);
        glEnd();
    }

    // Vertical lines (2 columns)
    float cols[] = {300, 650, 1000};
    for (int i = 0; i < 3; i++) {
        glBegin(GL_LINES);
        glVertex2f(cols[i], 350);
        glVertex2f(cols[i], 110);
        glEnd();
    }





    // Headers
    glColor3f(0.1f, 0.1f, 0.6f);
    proj_drawText(380, 320, "Student Name");
    proj_drawText(740, 320, "Student ID");

    // Student Data
    glColor3f(0.0f, 0.0f, 0.0f);

    proj_drawText(380, 280, "MD SANJIT ISLAM KAFIL");
    proj_drawText(740, 280, "23-50543-1");

    proj_drawText(380, 240, "NAFIUL ISLAM KHAN NAFI");
    proj_drawText(740, 240, "23-51154-1");

    proj_drawText(380, 200, "MAHOMUDA PATOWARY MIM");
    proj_drawText(740, 200, "23-51156-1");

    proj_drawText(380, 160, "SUMAIYA AKTER");
    proj_drawText(740, 160, "23-52362-2");

    proj_drawText(380, 120, "SANJANA SAYED NUHA");
    proj_drawText(740, 120, "23-53087-3");
}

void proj_drawProjectInfo() {
    glColor3f(0.0f, 0.2f, 0.6f);
    proj_drawText(500, 540, "American International University of Bangladesh");

    glColor3f(0.0f, 0.0f, 0.0f);
    proj_drawText(200, 480, "Faculty Name: ZISHAN AHMED ONIK");
    proj_drawText(200, 440, "Project Name: Daily Life of an Office-Going Person");
    proj_drawText(200, 400, "Subject: Computer Graphics");
}


void renderProjectFrontPage() {
    glClear(GL_COLOR_BUFFER_BIT);
    proj_drawProjectInfo();
    proj_drawTable();
    glutSwapBuffers();
}


void initProjectFrontPage() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


   #ifdef _WIN32
    sndPlaySound(NULL, SND_ASYNC);
    #endif


    glutMouseFunc(NULL);
    glutKeyboardFunc(masterKeyboard);
    glutTimerFunc(-1, NULL, 0);
}



////////////////2nd page ///////////


bool house_isNight = false;

void house_renderBitmapString(float x, float y, float z, void *font, const char *string) {
    glRasterPos3f(x, y, z);
    for (size_t c_idx = 0; string[c_idx] != '\0'; c_idx++) {
        glutBitmapCharacter(font, string[c_idx]);
    }
}

void house_House1() {

    glBegin(GL_QUADS);
    glColor3f(0.718f, 0.255f, 0.055f);
    glVertex2f(-0.2147917724929f, 0.27833078f);
    glVertex2f(0.2405078256459f, 0.27833078f);
    glVertex2f(0.2405078256459f, 0.0206676f);
    glVertex2f(-0.2147917724929f, 0.0206676f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.396f, 0.263f, 0.129f);
    glVertex2f(-0.241f, 0.275f);
    glVertex2f(-0.1f, 0.4f);
    glVertex2f(0.047f, 0.272f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.698f, 0.745f, 0.710f); // Light gray/white for trim
    glVertex2f(-0.1016f, 0.375f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.2f, 0.3f);
    glEnd();

    // Right Roof Slope
    glBegin(GL_QUADS);
    glColor3f(0.317f, 0.210f, 0.103f);
    glVertex2f(-0.0829f, 0.37757f);
    glVertex2f(-0.00701f, 0.4289f);
    glVertex2f(0.2651f, 0.27712f);
    glVertex2f(0.038533f, 0.27894f);
    glEnd();

    // Right Window
    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.06207254031f, 0.269223775f);
    glVertex2f(0.19278631124f, 0.269223775f);
    glVertex2f(0.19278631124f, 0.1528217f);
    glVertex2f(0.06207254031f, 0.1528217f);
    glEnd();

    // Front Window beside door
    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(-0.081282604f - 0.05f, 0.257442401f);
    glVertex2f(-0.017998733f - 0.05f, 0.257442401f);
    glVertex2f(-0.017998733f - 0.05f, 0.09877820f);
    glVertex2f(-0.081282604f - 0.05f, 0.09877820f);
    glEnd();

    // Front Window beside door (Glass)
    glBegin(GL_QUADS);
    glColor3f(0.753f, 0.910f, 0.976f); // Light blue for glass
    glVertex2f(-0.06738598f - 0.05f, 0.244232943f);
    glVertex2f(-0.03100510328f - 0.05f, 0.244232943f);
    glVertex2f(-0.03100510328f - 0.05f, 0.1343626866f);
    glVertex2f(-0.06738598f - 0.05f, 0.1343626866f);
    glEnd();

    // Right Window ( Glass Part 1)
    glBegin(GL_QUADS);
    glColor3f(0.753f, 0.910f, 0.976f);
    glVertex2f(0.1337600633f, 0.2547917f);
    glVertex2f(0.179585556f, 0.2547917f);
    glVertex2f(0.179585556f, 0.165150645f);
    glVertex2f(0.1337600633f, 0.165150645f);
    glEnd();

    // Right Window ( Glass Part 2)
    glBegin(GL_QUADS);
    glColor3f(0.753f, 0.910f, 0.976f);
    glVertex2f(0.07064951f, 0.25519372f);
    glVertex2f(0.12009281f, 0.25519372f);
    glVertex2f(0.12009281f, 0.1659546016f);
    glVertex2f(0.07064951f, 0.1659546016f);
    glEnd();

    // White Door Frame
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    float door_width = 0.08f;
    float door_height = 0.22f;
    float door_base_y = 0.0206676f;

    glVertex2f(-door_width / 2.0f, door_base_y);
    glVertex2f(door_width / 2.0f, door_base_y);
    glVertex2f(door_width / 2.0f, door_base_y + door_height);
    glVertex2f(-door_width / 2.0f, door_base_y + door_height);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.753f, 0.910f, 0.976f);
    float glass_inset = 0.01f;
    float glass_height = 0.19f;
    float glass_bottom_y = door_base_y + glass_inset;

    glVertex2f(-door_width / 2.0f + glass_inset, glass_bottom_y);
    glVertex2f(door_width / 2.0f - glass_inset, glass_bottom_y);
    glVertex2f(door_width / 2.0f - glass_inset, glass_bottom_y + glass_height);
    glVertex2f(-door_width / 2.0f + glass_inset, glass_bottom_y + glass_height);
    glEnd();
}

void house_triAngle() { //grass
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.39f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.895f, 0.13255f);
    glVertex2f(1.0f, 0.0f);

    glVertex2f(0.1014f, 0.0f);
    glVertex2f(0.197f, 0.13255f);
    glVertex2f(0.328f, 0.0f);
    glEnd();
}

void house_sky() {
    glBegin(GL_QUADS);
    if (house_isNight)
        glColor3f(0.05f, 0.05f, 0.2f);
    else
        glColor3f(0.529f, 0.808f, 0.922f);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.03f);
    glVertex2f(-1.0f, 0.03f);
    glEnd();
}

void house_road() {
    glBegin(GL_QUADS);
    glColor3f(0.247f, 0.247f, 0.247f);
    glVertex2f(-1.0f, -0.5f);
    glVertex2f(1.0f, -0.5f);
    glVertex2f(1.0f, -0.18228f);
    glVertex2f(-1.0f, -0.18228f);
    glEnd();
}

void house_grass() {
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(-1.0f, 0.03f);
    glVertex2f(-1.0f, -0.113f);
    glVertex2f(1.0f, -0.1131f);
    glVertex2f(1.0f, 0.03f);
    glEnd();
}

void house_drawChimney() {
    glColor3f(0.4f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(0.135f, 0.35f);
    glVertex2f(0.135f, 0.49f);
    glVertex2f(0.1f, 0.49f);
    glEnd();

    glColor3f(0.3f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
    glVertex2f(0.095f, 0.49f);
    glVertex2f(0.14f, 0.49f);
    glVertex2f(0.14f, 0.52f);
    glVertex2f(0.095f, 0.52f);
    glEnd();
}


void house_drawHouseSteps() {
    glColor3f(1.0f, 1.0f, 1.0f);

    float step_base_width = 0.18f;
    float step_height = 0.035f;
    float step_depth_offset = 0.015f;
    int num_stairs = 3;
    float house_base_y = 0.0206676f;

    for (int i = 0; i < num_stairs; ++i) {
        float current_width = step_base_width - (i * step_depth_offset * 2);
        float left_x = -current_width / 2.0f;
        float right_x = current_width / 2.0f;

        float bottom_y = house_base_y - step_height * (num_stairs - i);
        float top_y = bottom_y + step_height;

        glBegin(GL_QUADS);
        glVertex2f(left_x, bottom_y);
        glVertex2f(right_x, bottom_y);
        glVertex2f(right_x, top_y);
        glVertex2f(left_x, top_y);
        glEnd();
    }
}


void house_drawRamp() {
    glColor3f(0.247f, 0.247f, 0.247f);
    float ramp_width_bottom = 0.35f;
    float ramp_width_top = 0.25f;
    float road_top_y = -0.18228f;
    float house_base_y = 0.0206676f;

    glBegin(GL_QUADS);
    glVertex2f(-ramp_width_bottom / 2.0f, road_top_y);
    glVertex2f(ramp_width_bottom / 2.0f, road_top_y);
    glVertex2f(ramp_width_top / 2.0f, house_base_y);
    glVertex2f(-ramp_width_top / 2.0f, house_base_y);
    glEnd();
}

void house_drawSimpleTree(float x_offset, float y_offset) {
    glPushMatrix();
    glTranslatef(x_offset, y_offset, 0.0f);

    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.025f, -0.113f);
    glVertex2f(0.025f, -0.113f);
    glVertex2f(0.025f, 0.45f);
    glVertex2f(-0.025f, 0.45f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.65f);
    glVertex2f(-0.22f, 0.45f);
    glVertex2f(0.22f, 0.45f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.85f);
    glVertex2f(-0.16f, 0.62f);
    glVertex2f(0.16f, 0.62f);
    glEnd();

    // Foliage Layer 3 (top)
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(-0.12f, 0.78f);
    glVertex2f(0.12f, 0.78f);
    glEnd();

    glPopMatrix();
}

void house_drawCurb() {
    glColor3f(0.35f, 0.35f, 0.35f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.18228f);
    glVertex2f(1.0f, -0.18228f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(-1.0f, -0.15f);
    glEnd();
}

void house_drawCloud(float x, float y, float scale) {
    if (house_isNight)
        glColor3f(0.7f, 0.7f, 0.8f);
    else
        glColor3f(1.0f, 1.0f, 1.0f);
    int segments = 100;

    float offsets[][2] = {
        {-0.06f,  0.00f}, {-0.03f,  0.02f}, { 0.00f,  0.00f},
        { 0.03f,  0.02f}, { 0.06f,  0.00f}, { 0.00f, -0.02f}
    };

    float radii[] = {0.045f, 0.05f, 0.06f, 0.05f, 0.045f, 0.04f};

    for (int c = 0; c < 6; ++c) {
        float cx = x + offsets[c][0] * scale;
        float cy = y + offsets[c][1] * scale;
        float radius = radii[c] * scale;

        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);
        for (int i = 0; i <= segments; ++i) {
            float angle = 2.0f * M_PI * i / segments;
            float dx = cosf(angle) * radius;
            float dy = sinf(angle) * radius;
            glVertex2f(cx + dx, cy + dy);
        }
        glEnd();
    }
}

void house_BackgroundHouse() {
    glBegin(GL_QUADS);
    glColor3f(0.45f, 0.15f, 0.05f);
    glVertex2f(-0.2147f, 0.2783f);
    glVertex2f(0.2405f, 0.2783f);
    glVertex2f(0.2405f, 0.0206f);
    glVertex2f(-0.2147f, 0.0206f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.25f, 0.14f, 0.07f);
    glVertex2f(-0.25f, 0.28f);
    glVertex2f(0.0f, 0.42f);
    glVertex2f(0.25f, 0.28f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.45f, 0.4f);
    glVertex2f(0.06f, 0.23f);
    glVertex2f(0.19f, 0.23f);
    glVertex2f(0.19f, 0.12f);
    glVertex2f(0.06f, 0.12f);
    glEnd();

    glColor3f(0.2f, 0.25f, 0.2f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
    glVertex2f(0.125f, 0.12f);
    glVertex2f(0.125f, 0.23f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0.06f, 0.175f);
    glVertex2f(0.19f, 0.175f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.35f, 0.45f, 0.6f);
    glVertex2f(0.07f, 0.22f);
    glVertex2f(0.18f, 0.22f);
    glVertex2f(0.18f, 0.13f);
    glVertex2f(0.07f, 0.13f);
    glEnd();
}

void house_drawSidewalk() {
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.15f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(-1.0f, -0.1f);
    glEnd();
}

void house_drawPath() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-0.07f, -0.1f);
    glVertex2f(0.07f, -0.1f);
    glVertex2f(0.05f, 0.0206676f);
    glVertex2f(-0.05f, 0.0206676f);
    glEnd();
}

float house_cloud1X = -0.65f;
float house_cloud2X = 0.1f;
float house_cloud3X = 0.55f;

float house_cloudSpeed1 = 0.0015f;
float house_cloudSpeed2 = 0.0009f;
float house_cloudSpeed3 = 0.0012f;

void house_updateClouds(int value) {
    // Only update clouds if the houses scene is active
    if (currentScene == SCENE_HOUSES) {
        house_cloud1X += house_cloudSpeed1;
        house_cloud2X += house_cloudSpeed2;
        house_cloud3X += house_cloudSpeed3;

        if (house_cloud1X > 1.2f) house_cloud1X = -1.2f;
        if (house_cloud2X > 1.2f) house_cloud2X = -1.2f;
        if (house_cloud3X > 1.2f) house_cloud3X = -1.2f;

        glutPostRedisplay();
        glutTimerFunc(16, house_updateClouds, 0); // Reschedule timer
    }
}

void house_handleMouse(int button, int state, int x, int y) {
    if (currentScene == SCENE_HOUSES && state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            house_cloudSpeed1 += 0.0005f;
            house_cloudSpeed2 += 0.0003f;
            house_cloudSpeed3 += 0.0004f;
        } else if (button == GLUT_RIGHT_BUTTON) {
            house_cloudSpeed1 = fmax(0.0001f, house_cloudSpeed1 - 0.0005f);
            house_cloudSpeed2 = fmax(0.0001f, house_cloudSpeed2 - 0.0003f);
            house_cloudSpeed3 = fmax(0.0001f, house_cloudSpeed3 - 0.0004f);
        }
        glutPostRedisplay();
    }
}

void house_handleKeyboard(unsigned char key, int x, int y) {
    if (currentScene == SCENE_HOUSES) {
        if (key == 'n' || key == 'N') {
            house_isNight = true;
        } else if (key == 'd' || key == 'D') {
            house_isNight = false;
        }
        glutPostRedisplay();
    }
}

void renderHousesScene() {
    glClear(GL_COLOR_BUFFER_BIT);

    house_sky();

    glPushMatrix();
    glTranslatef(-0.32f, -0.05f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    house_BackgroundHouse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.32f, -0.05f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    house_BackgroundHouse();
    glPopMatrix();


    house_drawCloud(house_cloud1X, 0.78f, 1.0f);
    house_drawCloud(house_cloud2X, 0.82f, 1.2f);
    house_drawCloud(house_cloud3X, 0.76f, 0.9f);

    house_grass();
    house_road();
    house_drawCurb();
    house_drawSidewalk();

    glPushMatrix();
    glTranslatef(-0.65f, 0.0f, 0.0f);
    house_House1();
    house_drawChimney();
    house_drawHouseSteps();
    house_drawPath();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    house_House1();
    house_drawChimney();
    house_drawHouseSteps();
    house_drawPath();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.65f, 0.0f, 0.0f);
    house_House1();
    house_drawChimney();
    house_drawRamp();
    house_drawPath();
    glPopMatrix();

    house_drawSimpleTree(-0.85f, 0.0f);
    house_triAngle();

    glutSwapBuffers();
}


void initHousesScene() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    house_cloud1X = -0.65f;
    house_cloud2X = 0.1f;
    house_cloud3X = 0.55f;
    house_cloudSpeed1 = 0.0015f;
    house_cloudSpeed2 = 0.0009f;
    house_cloudSpeed3 = 0.0012f;
    house_isNight = false;


    glutTimerFunc(0, house_updateClouds, 0);

    glutMouseFunc(house_handleMouse);

    glutKeyboardFunc(masterKeyboard);

    #ifdef _WIN32
    // Play sound only when entering this scene
    sndPlaySound(TEXT("a.wav"), SND_ASYNC | SND_LOOP); // Assuming "a.wav" is the sound file
    #endif
}



///////////////////////3rd page/////////////////////////


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
    /*glPushMatrix();
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
    glPopMatrix();*/
}

void city_drawWalkway() {
    glPushMatrix();
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_QUADS);
    glVertex2f(0, 115);
    glVertex2f(WINDOW_WIDTH, 115);
    glVertex2f(WINDOW_WIDTH, 120);
    glVertex2f(0, 120);
    glEnd();
    glPopMatrix();
}

void city_drawUmbrella(float x, float y) {
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_LINES);
    glVertex2f(x + 20, y + 125);
    glVertex2f(x + 20, y + 200);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    for (int angle = 0; angle <= 180; angle += 5) {
        float rad = angle * M_PI / 180.0f;
        glVertex2f(x + 20 + 60 * cos(rad), y + 200 + 30 * sin(rad));
    }
    glEnd();
}

void city_drawMan(float x, float y) {
    glPushMatrix();

    city_drawUmbrella(x, y);

    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    // Left shoe
    glVertex2f(x - 4, y);
    glVertex2f(x + 18, y);
    glVertex2f(x + 18, y + 5);
    glVertex2f(x - 4, y + 5);
    // Right shoe
    glVertex2f(x + 22, y);
    glVertex2f(x + 44, y);
    glVertex2f(x + 44, y + 5);
    glVertex2f(x + 22, y + 5);
    glEnd();

    glBegin(GL_QUADS);
    // Left leg
    glVertex2f(x, y + 5);
    glVertex2f(x + 16, y + 5);
    glVertex2f(x + 16, y + 45);
    glVertex2f(x, y + 45);
    // Right leg
    glVertex2f(x + 24, y + 5);
    glVertex2f(x + 40, y + 5);
    glVertex2f(x + 40, y + 45);
    glVertex2f(x + 24, y + 45);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x, y + 45);
    glVertex2f(x + 40, y + 45);
    glVertex2f(x + 40, y + 125);
    glVertex2f(x, y + 125);
    glEnd();

    glBegin(GL_QUADS);
    // Left arm
    glVertex2f(x - 10, y + 55);
    glVertex2f(x, y + 55);
    glVertex2f(x, y + 105);
    glVertex2f(x - 10, y + 105);
    // Right arm
    glVertex2f(x + 40, y + 55);
    glVertex2f(x + 50, y + 55);
    glVertex2f(x + 50, y + 105);
    glVertex2f(x + 40, y + 105);
    glEnd();

    glColor3f(0.9f, 0.8f, 0.7f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float rad = i * M_PI / 180.0f;
        glVertex2f(x + 20 + 18 * cos(rad), y + 138 + 14 * sin(rad));
    }
    glEnd();

    glPopMatrix();
}

void city_drawCar(float x, float y, float r, float g, float b) {
    glPushMatrix();
    glTranslatef(x, y, 0);

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(40, 0);
    glVertex2f(40, 20);
    glVertex2f(0, 20);
    glEnd();

    glColor3f(0.7f, 0.8f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(5, 10);
    glVertex2f(15, 10);
    glVertex2f(15, 18);
    glVertex2f(5, 18);
    glVertex2f(25, 10);
    glVertex2f(35, 10);
    glVertex2f(35, 18);
    glVertex2f(25, 18);
    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f);
    for (int centerX = 10; centerX <= 30; centerX += 20) {
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i += 10) {
            float rad = i * M_PI / 180.0f;
            glVertex2f(centerX + 5 * cos(rad), -5 + 5 * sin(rad));
        }
        glEnd();
    }
    glPopMatrix();
}

void city_drawRoad() {
    glPushMatrix();
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(WINDOW_WIDTH, 0);
    glVertex2f(WINDOW_WIDTH, 120);
    glVertex2f(0, 120);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    for (int i = 0; i < WINDOW_WIDTH; i += 40) {
        glBegin(GL_QUADS);
        glVertex2f(i, 58);
        glVertex2f(i + 20, 58);
        glVertex2f(i + 20, 62);
        glVertex2f(i, 62);
        glEnd();
    }
    glPopMatrix();
}

void city_timer(int value) {

    if (currentScene == SCENE_CITY_SCENE) {
        city_cloudX1 += 0.2f;
        city_cloudX2 += 0.3f;
        city_cloudX3 += 0.25f;
        if (city_cloudX1 > WINDOW_WIDTH + 100) city_cloudX1 = -100;
        if (city_cloudX2 > WINDOW_WIDTH + 100) city_cloudX2 = -100;
        if (city_cloudX3 > WINDOW_WIDTH + 100) city_cloudX3 = -100;

        city_carX1 += 1.2f;
        city_carX2 += 1.0f;
        city_carX3 += 1.4f;
        city_carX4 += 0.9f;
        if (city_carX1 > WINDOW_WIDTH + 50) city_carX1 = -50;
        if (city_carX2 > WINDOW_WIDTH + 50) city_carX2 = -50;
        if (city_carX3 > WINDOW_WIDTH + 50) city_carX3 = -50;
        if (city_carX4 > WINDOW_WIDTH + 50) city_carX4 = -50;

        // Move the man
        //city_manX += city_manSpeed;

// If man goes beyond the window, wrap around
       // if (city_manX > WINDOW_WIDTH) {
       // city_manX = -50; // start from left again
       // }


        city_rainYOffset -= 3.0f;
        if (city_rainYOffset < -WINDOW_HEIGHT) city_rainYOffset = 0;

        glutPostRedisplay();
        glutTimerFunc(16, city_timer, 0);
    }
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

    city_drawCar(city_carX1, 80, 1.0f, 0.0f, 0.0f);
    city_drawCar(city_carX2, 30, 0.0f, 1.0f, 0.0f);
    city_drawCar(city_carX3, 80, 0.0f, 0.0f, 1.0f);
    city_drawCar(city_carX4, 30, 1.0f, 1.0f, 0.0f);

    //city_drawMan(100, 120);
    city_drawMan(city_manX, city_manY);


    city_drawRain();

    glutSwapBuffers();
}






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
    glutKeyboardFunc(masterKeyboard);
    #ifdef _WIN32
    sndPlaySound(NULL, SND_ASYNC); // Stop any previous sound
    #endif
}

///////////////4th page ///////////////

bool office_isLightOn = true;

enum OfficeManState { OFFICE_WALKING, OFFICE_SITTING_DOWN, OFFICE_SEATED };
OfficeManState office_manState = OFFICE_WALKING;

float office_manGlobalX = -1.5f;
float office_manGlobalY = -0.7f;
float office_manScale = 0.003f;

float office_secondChairBoothX = -0.4f;  //1st chair->0.85,2nd->-0.40 |3rd(0.05)|4th(0.50)   office_secondChairBoothX
float office_secondChairOffsetX = 0.09f;
float office_secondChairWidth = 0.22f;

float office_targetWalkX = office_secondChairBoothX + office_secondChairOffsetX + (office_secondChairWidth / 2.0f) - (20.0f * office_manScale);
float office_targetSeatedY = -0.58f;

float office_walkSpeed = 0.003f;
float office_sitSpeed = 0.002f;


void office_drawRoundedCeilingPanel(float x, float y, float width, float height) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; ++i) {
        float angle = 2.0f * M_PI * i / 100;
        float dx = (width / 2) * cos(angle);
        float dy = (height / 2) * sin(angle);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void office_drawCeilingLights(float x, float y, float width, float height) {
    //glColor3f(0.863f, 0.863f, 0.863f);
    glColor3f(0.1f,1.0f,0.0f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    if (office_isLightOn) {
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x + width * 0.1f, y + height * 0.1f);
        glVertex2f(x + width * 0.9f, y + height * 0.1f);
        glVertex2f(x + width * 0.9f, y + height * 0.9f);
        glVertex2f(x + width * 0.1f, y + height * 0.9f);
        glEnd();
    } else {
        glColor3f(0.392f, 0.392f, 0.392f);
        //glColor3f(0.392f, 0.392f, 0.0f);

        glBegin(GL_QUADS);
        glVertex2f(x + width * 0.1f, y + height * 0.1f);
        glVertex2f(x + width * 0.9f, y + height * 0.1f);
        glVertex2f(x + width * 0.9f, y + height * 0.9f);
        glVertex2f(x + width * 0.1f, y + height * 0.9f);
        glEnd();
    }
}

void office_drawCeilingBase() {
    glColor3f(0.235f, 0.235f, 0.235f);


    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void office_drawWallFrame() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, 0.58f);
    glVertex2f(1.0f, 0.58f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(-1.0f, 0.6f);

    glVertex2f(-1.0f, -0.7f);
    glVertex2f(-0.95f, -0.7f);
    glVertex2f(-0.95f, 0.6f);
    glVertex2f(-1.0f, 0.6f);

    glVertex2f(0.95f, -0.7f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(0.95f, 0.6f);

    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, -0.15f);
    glVertex2f(-1.0f, -0.15f);
    glEnd();
}

void office_drawBackground() {
    glColor3f(1.0f, 0.475f, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(-0.95f, -0.15f);
    glVertex2f(0.95f, -0.15f);
    glVertex2f(0.95f, 0.58f);
    glVertex2f(-0.95f, 0.58f);
    glEnd();
}

void office_drawFloor() {
   glColor3f(0.729f, 0.659f, 0.561f);

    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, -0.7f);
    glVertex2f(-1.0f, -0.7f);
    glEnd();
}

void office_drawDeskPanel(float x, float y, float width, float height) {
    glColor3f(0.941f, 0.941f, 0.941f);

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void office_drawDesk(float x) {
    office_drawDeskPanel(x, -0.7f, 0.05f, 0.55f);

    glColor3f(0.565f, 0.486f, 0.357f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.05f, -0.15f);
    glVertex2f(x + 0.35f, -0.15f);
    glVertex2f(x + 0.35f, -0.10f);
    glVertex2f(x + 0.05f, -0.10f);
    glEnd();

    office_drawDeskPanel(x + 0.35f, -0.7f, 0.05f, 0.55f);
}

void office_drawMonitor(float x) {
    glColor3f(0.118f, 0.118f, 0.118f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.13f, -0.05f);
    glVertex2f(x + 0.28f, -0.05f);
    glVertex2f(x + 0.28f, 0.1f);
    glVertex2f(x + 0.13f, 0.1f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.14f, -0.04f);
    glVertex2f(x + 0.27f, -0.04f);
    glVertex2f(x + 0.27f, 0.09f);
    glVertex2f(x + 0.14f, 0.09f);
    glEnd();

    glColor3f(0.196f, 0.196f, 0.196f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.19f, -0.05f);
    glVertex2f(x + 0.21f, -0.05f);
    glVertex2f(x + 0.21f, -0.10f);
    glVertex2f(x + 0.19f, -0.10f);
    glEnd();
}

void office_drawPrinter(float x) {
    glColor3f(0.157f, 0.157f, 0.157f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.06f, -0.10f);
    glVertex2f(x + 0.12f, -0.10f);
    glVertex2f(x + 0.12f, -0.06f);
    glVertex2f(x + 0.06f, -0.06f);
    glEnd();


    glColor3f(0.235f, 0.235f, 0.235f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.065f, -0.06f);
    glVertex2f(x + 0.115f, -0.06f);
    glVertex2f(x + 0.115f, -0.05f);
    glVertex2f(x + 0.065f, -0.05f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.07f, -0.095f);
    glVertex2f(x + 0.11f, -0.095f);
    glVertex2f(x + 0.11f, -0.09f);
    glVertex2f(x + 0.07f, -0.09f);
    glEnd();
}

void office_drawChair(float x) {
    float chair_base_y = -0.75f;
    float chair_color_black =0.078f ;
    float chair_color_dark_grey =0.157f ;
    float chair_color_chrome =0.706f ;

    float seat_bottom_y = -0.58f;
    float seat_height = 0.10f;
    float seat_width = 0.22f;
    float seat_x_offset = 0.09f;
    glColor3f(chair_color_black, chair_color_black, chair_color_black);
    glBegin(GL_QUADS);
    glVertex2f(x + seat_x_offset, seat_bottom_y);
    glVertex2f(x + seat_x_offset + seat_width, seat_bottom_y);
    glVertex2f(x + seat_x_offset + seat_width, seat_bottom_y + seat_height);
    glVertex2f(x + seat_x_offset, seat_bottom_y + seat_height);
    glEnd();

    float back_bottom_y = seat_bottom_y + seat_height;
    float back_height = 0.25f;
    float back_width = 0.03f;
    float back_mesh_width = seat_width - 0.02f;
    float back_x_offset = seat_x_offset + 0.01f;
    glColor3f(chair_color_black, chair_color_black, chair_color_black);
    glBegin(GL_QUADS);
    glVertex2f(x + back_x_offset, back_bottom_y);
    glVertex2f(x + back_x_offset + back_width, back_bottom_y);
    glVertex2f(x + back_x_offset + back_width, back_bottom_y + back_height);
    glVertex2f(x + back_x_offset, back_bottom_y + back_height);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x + back_x_offset + back_mesh_width, back_bottom_y);
    glVertex2f(x + back_x_offset + back_mesh_width + back_width, back_bottom_y);
    glVertex2f(x + back_x_offset + back_mesh_width + back_width, back_bottom_y + back_height);
    glVertex2f(x + back_x_offset + back_mesh_width, back_bottom_y + back_height);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x + back_x_offset, back_bottom_y + back_height - 0.02f);
    glVertex2f(x + back_x_offset + back_mesh_width + back_width, back_bottom_y + back_height - 0.02f);
    glVertex2f(x + back_x_offset + back_mesh_width + back_width, back_bottom_y + back_height);
    glVertex2f(x + back_x_offset, back_bottom_y + back_height);
    glEnd();

    glColor3f(chair_color_dark_grey, chair_color_dark_grey, chair_color_dark_grey);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    float mesh_start_y = back_bottom_y + 0.02f;
    float mesh_end_x = x + back_x_offset + back_mesh_width + back_width - 0.01f;
    float mesh_start_x_line = x + back_x_offset + back_width + 0.01f;
    for (int i = 0; i < 7; ++i) {
        glVertex2f(mesh_start_x_line, mesh_start_y + i * 0.035f);
        glVertex2f(mesh_end_x, mesh_start_y + i * 0.035f);
    }
    glEnd();
    glLineWidth(1.0f);

    glColor3f(chair_color_dark_grey, chair_color_dark_grey, chair_color_dark_grey);
    float arm_y_top = seat_bottom_y + seat_height + 0.05f;
    float arm_length = 0.15f;
    float arm_height = 0.03f;

    glBegin(GL_QUADS);
    glVertex2f(x + seat_x_offset - 0.02f, arm_y_top);
    glVertex2f(x + seat_x_offset - 0.02f + arm_length, arm_y_top);
    glVertex2f(x + seat_x_offset - 0.02f + arm_length, arm_y_top + arm_height);
    glVertex2f(x + seat_x_offset - 0.02f, arm_y_top + arm_height);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x + seat_x_offset - 0.02f, seat_bottom_y + seat_height - 0.01f);
    glVertex2f(x + seat_x_offset, seat_bottom_y + seat_height - 0.01f);
    glVertex2f(x + seat_x_offset, arm_y_top);
    glVertex2f(x + seat_x_offset - 0.02f, arm_y_top);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x + seat_x_offset + seat_width - arm_length + 0.02f, arm_y_top);
    glVertex2f(x + seat_x_offset + seat_width + 0.02f, arm_y_top);
    glVertex2f(x + seat_x_offset + seat_width + 0.02f, arm_y_top + arm_height);
    glVertex2f(x + seat_x_offset + seat_width - arm_length + 0.02f, arm_y_top + arm_height);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(x + seat_x_offset + seat_width, seat_bottom_y + seat_height - 0.01f);
    glVertex2f(x + seat_x_offset + seat_width + 0.02f, seat_bottom_y + seat_height - 0.01f);
    glVertex2f(x + seat_x_offset + seat_width + 0.02f, arm_y_top);
    glVertex2f(x + seat_x_offset + seat_width, arm_y_top);
    glEnd();

    float lift_y_bottom = chair_base_y + 0.05f;
    float lift_height = seat_bottom_y - lift_y_bottom;
    float lift_width = 0.01f;
    float lift_x_center = x + seat_x_offset + seat_width / 2.0f;
    glColor3f(chair_color_chrome, chair_color_chrome, chair_color_chrome);
    glBegin(GL_QUADS);
    glVertex2f(lift_x_center - lift_width / 2, lift_y_bottom);
    glVertex2f(lift_x_center + lift_width / 2, lift_y_bottom);
    glVertex2f(lift_x_center + lift_width / 2, lift_y_bottom + lift_height);
    glVertex2f(lift_x_center - lift_width / 2, lift_y_bottom + lift_height);
    glEnd();

    glColor3f(chair_color_chrome, chair_color_chrome, chair_color_chrome);
    float base_center_x = lift_x_center;
    float base_center_y = lift_y_bottom;
    float spoke_length = 0.1f;
    float spoke_width_vert = 0.015f;

    glBegin(GL_POLYGON);
    float hub_radius = 0.015f;
    for (int i = 0; i < 360; ++i) {
        float angle = i * M_PI / 180.0f;
        glVertex2f(base_center_x + hub_radius * cos(angle), base_center_y + hub_radius * sin(angle));
    }
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(base_center_x - spoke_width_vert/2, base_center_y);
    glVertex2f(base_center_x + spoke_width_vert/2, base_center_y);
    glVertex2f(base_center_x + spoke_width_vert/2, base_center_y - spoke_length);
    glVertex2f(base_center_x - spoke_width_vert/2, base_center_y - spoke_length);
    glEnd();

    glPushMatrix();
    glTranslatef(base_center_x, base_center_y, 0.0f);
    glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-spoke_width_vert/2, 0.0f);
    glVertex2f(spoke_width_vert/2, 0.0f);
    glVertex2f(spoke_width_vert/2, -spoke_length * 0.9f);
    glVertex2f(-spoke_width_vert/2, -spoke_length * 0.9f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(base_center_x, base_center_y, 0.0f);
    glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-spoke_width_vert/2, 0.0f);
    glVertex2f(spoke_width_vert/2, 0.0f);
    glVertex2f(spoke_width_vert/2, -spoke_length * 0.9f);
    glVertex2f(-spoke_width_vert/2, -spoke_length * 0.9f);
    glEnd();
    glPopMatrix();

    glColor3f(chair_color_black, chair_color_black, chair_color_black);
    float wheel_radius = 0.008f;
    int num_segments = 15;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(base_center_x, base_center_y - spoke_length);
    for (int i = 0; i <= num_segments; ++i) {
        float angle = i * 2.0f * M_PI / num_segments;
        glVertex2f(base_center_x + wheel_radius * cos(angle), base_center_y - spoke_length + wheel_radius * sin(angle));
    }
    glEnd();

    glBegin(GL_POLYGON);
    float angle_lf = 30.0f * M_PI / 180.0f;
    float x_lf_wheel = base_center_x + (-spoke_length * 0.9f) * sin(angle_lf);
    float y_lf_wheel = base_center_y + (-spoke_length * 0.9f) * cos(angle_lf);
    glVertex2f(x_lf_wheel, y_lf_wheel);
    for (int i = 0; i <= num_segments; ++i) {
        float angle = i * 2.0f * M_PI / num_segments;
        glVertex2f(x_lf_wheel + wheel_radius * cos(angle), y_lf_wheel + wheel_radius * sin(angle));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    float angle_rf = -30.0f * M_PI / 180.0f;
    float x_rf_wheel = base_center_x + (-spoke_length * 0.9f) * sin(angle_rf);
    float y_rf_wheel = base_center_y + (-spoke_length * 0.9f) * cos(angle_rf);
    glVertex2f(x_rf_wheel, y_rf_wheel);
    for (int i = 0; i <= num_segments; ++i) {
        float angle = i * 2.0f * M_PI / num_segments;
        glVertex2f(x_rf_wheel + wheel_radius * cos(angle), y_rf_wheel + wheel_radius * sin(angle));
    }
    glEnd();
}

void office_drawWallmate(float x, float y, float width, float height) {
    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

    glColor3f(0.078f, 0.078f, 0.078f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.005f, y + 0.005f);
    glVertex2f(x + width - 0.005f, y + 0.005f);
    glVertex2f(x + width - 0.005f, y + height - 0.005f);
    glVertex2f(x + 0.005f, y + height - 0.005f);
    glEnd();

    glColor3f(0.275f, 0.275f, 0.275f);

    glBegin(GL_QUADS);
    glVertex2f(x + 0.02f, y + 0.02f);
    glVertex2f(x + width - 0.02f, y + 0.02f);
    glVertex2f(x + width - 0.02f, y + height - 0.02f);
    glVertex2f(x + 0.02f, y + height - 0.02f);
    glEnd();
}

void office_drawBooth(float x) {
    office_drawDesk(x);
    office_drawMonitor(x);
    office_drawPrinter(x);
    office_drawChair(x);
}

void office_drawMan(float x, float y) {
    glColor3f(0.1f, 0.1f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(x - 4, y);
    glVertex2f(x + 18, y);
    glVertex2f(x + 18, y + 5);
    glVertex2f(x - 4, y + 5);

    glVertex2f(x + 22, y);
    glVertex2f(x + 44, y);
    glVertex2f(x + 44, y + 5);
    glVertex2f(x + 22, y + 5);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x, y + 5);
    glVertex2f(x + 16, y + 5);
    glVertex2f(x + 16, y + 45);
    glVertex2f(x, y + 45);

    glVertex2f(x + 24, y + 5);
    glVertex2f(x + 40, y + 5);
    glVertex2f(x + 40, y + 45);
    glVertex2f(x + 24, y + 45);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x, y + 45);
    glVertex2f(x + 40, y + 45);
    glVertex2f(x + 40, y + 125);
    glVertex2f(x, y + 125);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(x - 10, y + 55);
    glVertex2f(x, y + 55);
    glVertex2f(x, y + 105);
    glVertex2f(x - 10, y + 105);

    glVertex2f(x + 40, y + 55);
    glVertex2f(x + 50, y + 55);
    glVertex2f(x + 50, y + 105);
    glVertex2f(x + 40, y + 105);
    glEnd();

    glColor3f(0.9f, 0.8f, 0.7f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i += 10) {
        float rad = i * M_PI / 180.0f;
        glVertex2f(x + 20 + 18 * cos(rad), y + 138 + 14 * sin(rad));
    }
    glEnd();
}


void renderOfficeScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    office_drawCeilingBase();
    office_drawWallFrame();
    office_drawBackground();
    office_drawFloor();

    float panelStartX = -0.75f;
    for (int i = 0; i < 5; i++) {
        office_drawRoundedCeilingPanel(panelStartX + i * 0.37f, 0.85f, 0.3f, 0.1f);
    }

    float lightStartX = -0.7f;
    float lightHeight = 0.05f;
    float lightWidth = 0.25f;
    float lightY = 0.7f;
    for (int i = 0; i < 4; i++) {
        office_drawCeilingLights(lightStartX + i * 0.35f, lightY, lightWidth, lightHeight);
    }

    float wallmateY = 0.3f;
    float wallmateWidth = 0.28f;
    float wallmateHeight = 0.15f;
    office_drawWallmate(-0.45f, wallmateY, wallmateWidth, wallmateHeight);
    office_drawWallmate(-0.1f, wallmateY, wallmateWidth, wallmateHeight);
    office_drawWallmate(0.25f, wallmateY, wallmateWidth, wallmateHeight);

    float boothStartX = -0.85f;
    for (int i = 0; i < 4; i++) {
        office_drawBooth(boothStartX + i * 0.45f);
    }

    glPushMatrix();
    glTranslatef(office_manGlobalX, office_manGlobalY, 0.0f);
    glScalef(office_manScale, office_manScale, 1.0f);
    office_drawMan(0, 0);
    glPopMatrix();

    glutSwapBuffers();
}

void office_blinkLights(int value) {
    if (currentScene == SCENE_OFFICE_LAYOUT) {
        office_isLightOn = !office_isLightOn;
        glutPostRedisplay();
        glutTimerFunc(1000, office_blinkLights, 0);
    }
}

void office_animateMan(int value) {
    if (currentScene == SCENE_OFFICE_LAYOUT) {
        switch (office_manState) {
            case OFFICE_WALKING:
                if (office_manGlobalX < office_targetWalkX) {
                    office_manGlobalX += office_walkSpeed;
                } else {
                    office_manState = OFFICE_SITTING_DOWN;
                }
                break;
            case OFFICE_SITTING_DOWN:
                if (office_manGlobalY > office_targetSeatedY) {
                    office_manGlobalY -= office_sitSpeed;
                } else {
                    office_manGlobalY = office_targetSeatedY;
                    office_manState = OFFICE_SEATED;
                }
                break;
            case OFFICE_SEATED:
                break;
        }
        glutPostRedisplay();
        if (office_manState != OFFICE_SEATED) {
            glutTimerFunc(16, office_animateMan, 0);
        }
    }
}



void initOfficeScene() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    office_isLightOn = true;
    office_manState = OFFICE_WALKING;
    office_manGlobalX = -1.5f;
    office_manGlobalY = -0.7f;

    glutMouseFunc(NULL);
    glutKeyboardFunc(masterKeyboard);

    // Start scene-specific timers
    glutTimerFunc(1000, office_blinkLights, 0);
    glutTimerFunc(16, office_animateMan, 0);

    #ifdef _WIN32
    sndPlaySound(NULL, SND_ASYNC); // Stop any previous sound
    #endif
}



void renderFourthWindow() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.8f, 0.8f, 0.2f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 0.7f);
        glVertex2f(-0.7f, -0.7f);
        glVertex2f(0.7f, -0.7f);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    house_renderBitmapString(-0.4f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "This is the 4th Window!");
    glutSwapBuffers();
}

void initFourthWindow() {
    glClearColor(0.2f, 0.8f, 0.8f, 1.0f); // Cyan background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    #ifdef _WIN32
    sndPlaySound(NULL, SND_ASYNC);
    #endif
    glutMouseFunc(NULL);
    glutKeyboardFunc(masterKeyboard);
    glutTimerFunc(-1, NULL, 0);
}


void masterDisplay() {
    switch (currentScene) {
        case SCENE_PROJECT_FRONT_PAGE:
            renderProjectFrontPage();
            break;
        case SCENE_HOUSES:
            renderHousesScene();
            break;
        case SCENE_CITY_SCENE:
            renderCityScene();
            break;
        case SCENE_OFFICE_LAYOUT:
            renderOfficeScene();
            break;
        case SCENE_FOURTH_WINDOW:
            renderFourthWindow();
            break;
        default:

            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(1.0f, 0.0f, 0.0f);
            house_renderBitmapString(-0.8f, 0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "ERROR: Unknown Scene!");
            glutSwapBuffers();
            break;
    }
}

void masterKeyboard(unsigned char key, int x, int y) {
    if (currentScene == SCENE_HOUSES) {
        house_handleKeyboard(key, x, y);
    } else if (currentScene == SCENE_CITY_SCENE) {
        // Handle 'r' and 'c' for city scene sounds
        if (key == 'r' || key == 'R') {
            city_rainSoundOn = !city_rainSoundOn;
            #ifdef _WIN32
            if (city_rainSoundOn) {
                PlaySound(TEXT("rain.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
            } else {
                PlaySound(NULL, 0, 0);
            }
            #endif
        } else if (key == 'a' || key == 'A') {
            city_manX -= 5; // move left
            if (city_manX < 0) city_manX = 0;
        }
        else if (key == 'd' || key == 'D') {
            city_manX += 5; // move right
            if (city_manX > WINDOW_WIDTH - 40) city_manX = WINDOW_WIDTH - 40;
        }

        else if (key == 'c' || key == 'C') {
            city_carSoundOn = !city_carSoundOn;
            #ifdef _WIN32
            if (city_carSoundOn) {
                PlaySound(TEXT("car.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
            } else {
                PlaySound(NULL, 0, 0);
            }
            #endif
        }
    }


    switch (key) {
        case '1':

            if (currentScene != SCENE_HOUSES) {
                currentScene = SCENE_HOUSES;
                initHousesScene();
            }
            break;
        case '2':

            if (currentScene != SCENE_CITY_SCENE) {
                currentScene = SCENE_CITY_SCENE;
                initCityScene();
            }
            break;
        case '3':

            if (currentScene != SCENE_OFFICE_LAYOUT) {
                currentScene = SCENE_OFFICE_LAYOUT;
                initOfficeScene();
            }
            break;
        case 27:

            #ifdef _WIN32
            sndPlaySound(NULL, SND_ASYNC);
            #endif
            exit(0);
            break;

        case '0':

            if (currentScene != SCENE_PROJECT_FRONT_PAGE) {
                currentScene = SCENE_PROJECT_FRONT_PAGE;
                initProjectFrontPage();
            }
            break;

        case '4':
            if (currentScene != SCENE_FOURTH_WINDOW) {
                currentScene = SCENE_FOURTH_WINDOW;
                initFourthWindow();
            }
            break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Combined OpenGL Scenes");
    initProjectFrontPage();


    glutDisplayFunc(masterDisplay);
    glutKeyboardFunc(masterKeyboard);


    glutMainLoop();

    return 0;
}
