#include <GL/glut.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Window size
const int WINDOW_WIDTH = 1400;
const int WINDOW_HEIGHT = 600;

// Movement variables
float manX = 0;
float manY = 120;
float manSpeed = 1.0f;

float carX = 0;
float carY = 50;
float carSpeed = 2.0f;

// ---------------- Umbrella ----------------
void drawUmbrella(float x, float y) {
    glColor3f(0.2f, 0.2f, 0.2f);

    // Handle
    glBegin(GL_LINES);
    glVertex2f(x + 20, y + 120);
    glVertex2f(x + 20, y + 190);
    glEnd();

    // Top
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 180; i += 5) {
        float rad = i * M_PI / 180.0f;
        glVertex2f(x + 20 + 60 * cos(rad),
                   y + 190 + 30 * sin(rad));
    }
    glEnd();
}

// ---------------- Man ----------------
void drawMan(float x, float y) {
    drawUmbrella(x, y);

    // Body
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 40, y);
    glVertex2f(x + 40, y + 100);
    glVertex2f(x, y + 100);
    glEnd();

    // Head
    glColor3f(0.9f, 0.8f, 0.7f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 360; i += 10) {
        float rad = i * M_PI / 180.0f;
        glVertex2f(x + 20 + 15 * cos(rad),
                   y + 120 + 15 * sin(rad));
    }
    glEnd();
}

// ---------------- Car ----------------
void drawCar(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);

    // Body
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(60, 0);
    glVertex2f(60, 25);
    glVertex2f(0, 25);
    glEnd();

    // Wheels
    glColor3f(0.1f, 0.1f, 0.1f);
    for (int cx = 15; cx <= 45; cx += 30) {
        glBegin(GL_POLYGON);
        for (int i = 0; i <= 360; i += 10) {
            float rad = i * M_PI / 180.0f;
            glVertex2f(cx + 6 * cos(rad),
                       -5 + 6 * sin(rad));
        }
        glEnd();
    }

    glPopMatrix();
}

// ---------------- Display ----------------
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawMan(manX, manY);
    drawCar(carX, carY);

    glutSwapBuffers();
}

// ---------------- Timer (Movement) ----------------
void timer(int) {
    // Move man
    manX += manSpeed;
    if (manX > WINDOW_WIDTH)
        manX = -50;

    // Move car
    carX += carSpeed;
    if (carX > WINDOW_WIDTH)
        carX = -60;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// ---------------- Init ----------------
void init() {
    glClearColor(0.7f, 0.8f, 1.0f, 1.0f); // sky
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

// ---------------- Main ----------------
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Man with Umbrella and Car");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
