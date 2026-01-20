
#ifdef _WIN32
#include <windows.h>
#endif
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 600;


enum Scene {
   
    SCENE_HOUSES
    
};
Scene currentScene = SCENE_HOUSES;

void initHousesScene();



void masterKeyboard(unsigned char key, int x, int y);


float house_cloud1X = -0.65f;
float house_cloud2X = 0.1f;
float house_cloud3X = 0.55f;

float house_cloudSpeed1 = 0.0015f;
float house_cloudSpeed2 = 0.0009f;
float house_cloudSpeed3 = 0.0012f;

bool house_isNight = false;

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
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(-0.1016f, 0.375f);
    glVertex2f(0.0f, 0.3f);
    glVertex2f(-0.2f, 0.3f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.317f, 0.210f, 0.103f);
    // this vertex is making right roof slope
    glVertex2f(-0.0829f, 0.37757f);
    glVertex2f(-0.00701f, 0.4289f);
    glVertex2f(0.2651f, 0.27712f);
    glVertex2f(0.038533f, 0.27894f);
    glEnd();

    //this vertex is making right Window
    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(0.06207254031f, 0.269223775f);
    glVertex2f(0.19278631124f, 0.269223775f);
    glVertex2f(0.19278631124f, 0.1528217f);
    glVertex2f(0.06207254031f, 0.1528217f);
    glEnd();

    // front window beside door
    glBegin(GL_QUADS);
    glColor3f(0.698f, 0.745f, 0.710f);
    glVertex2f(-0.081282604f - 0.05f, 0.257442401f);
    glVertex2f(-0.017998733f - 0.05f, 0.257442401f);
    glVertex2f(-0.017998733f - 0.05f, 0.09877820f);
    glVertex2f(-0.081282604f - 0.05f, 0.09877820f);
    glEnd();

    // special case for this front Window beside door (Glass)
    glBegin(GL_QUADS);
    glColor3f(0.753f, 0.910f, 0.976f);
    glVertex2f(-0.06738598f - 0.05f, 0.244232943f);
    glVertex2f(-0.03100510328f - 0.05f, 0.244232943f);
    glVertex2f(-0.03100510328f - 0.05f, 0.1343626866f);
    glVertex2f(-0.06738598f - 0.05f, 0.1343626866f);
    glEnd();

    // Right Window ( 1)
    glBegin(GL_QUADS);
    glColor3f(0.753f, 0.910f, 0.976f);
    glVertex2f(0.1337600633f, 0.2547917f);
    glVertex2f(0.179585556f, 0.2547917f);
    glVertex2f(0.179585556f, 0.165150645f);
    glVertex2f(0.1337600633f, 0.165150645f);
    glEnd();

    // Right Window (2)
    glBegin(GL_QUADS);
    glColor3f(0.753f, 0.910f, 0.976f);
    glVertex2f(0.07064951f, 0.25519372f);
    glVertex2f(0.12009281f, 0.25519372f);
    glVertex2f(0.12009281f, 0.1659546016f);
    glVertex2f(0.07064951f, 0.1659546016f);
    glEnd();

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





void house_triAngle() {
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
    if (house_isNight){
        glColor3f(0.05f, 0.05f, 0.2f);
    }
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
        glutTimerFunc(16, house_updateClouds, 0); // Reschedule timer 60 fps
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


}

void masterKeyboard(unsigned char key, int x, int y) {
    switch (currentScene) {
        case SCENE_HOUSES:
            house_handleKeyboard(key, x, y);
            break;

        default:
            break;
    }
}


void display() {
    switch (currentScene) {
        case SCENE_HOUSES:
            renderHousesScene();
            break;
        default:
            break;
    }
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Combined OpenGL Scenes");
    initHousesScene();


    glClearColor(0.5f, 0.8f, 0.95f, 1.0f); // color taken from ->gpt to get closer output
    glutDisplayFunc(display);


    glutMainLoop();

    return 0;
}
