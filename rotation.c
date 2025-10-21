#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x1_t, y1_t, x2_t, y2_t, x3_t, y3_t;
float angle;

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);  // Add this!
}

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    glBegin(GL_LINE_LOOP);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glVertex2i(x3, y3);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw original triangle in black
    glColor3f(0.0, 0.0, 0.0);
    drawTriangle(x1_t, y1_t, x2_t, y2_t, x3_t, y3_t);
    
    // Convert angle to radians
    float rad = angle * 3.14159 / 180.0;
    
    // Apply rotation transformation
    int x1_new = (int)(x1_t * cos(rad) - y1_t * sin(rad));
    int y1_new = (int)(x1_t * sin(rad) + y1_t * cos(rad));
    
    int x2_new = (int)(x2_t * cos(rad) - y2_t * sin(rad));
    int y2_new = (int)(x2_t * sin(rad) + y2_t * cos(rad));
    
    int x3_new = (int)(x3_t * cos(rad) - y3_t * sin(rad));
    int y3_new = (int)(x3_t * sin(rad) + y3_t * cos(rad));
    
    // Draw rotated triangle in red
    glColor3f(1.0, 0.0, 0.0);
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);
    
    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    fflush(stdout);
    scanf("%d %d %d %d %d %d", &x1_t, &y1_t, &x2_t, &y2_t, &x3_t, &y3_t);
    
    printf("Enter rotation angle (in degrees): ");
    scanf("%f", &angle);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Rotation of Triangle");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}