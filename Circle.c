#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int xc, yc, r;

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);  // Add this!
}

void drawCirclePoints(int x, int y) {
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

void drawCircle(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    int x = 0, y = r;
    int p = 1 - r;
    
    glBegin(GL_POINTS);  // Move outside the loop for efficiency
    drawCirclePoints(x, y);
    
    while (x < y) {
        x++;
        if (p < 0) {
            p = p + 2 * x + 1;
        } else {
            y--;
            p = p + 2 * x + 1 - 2 * y;
        }
        drawCirclePoints(x, y);
    }
    glEnd();  // Close GL_POINTS here
    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter center (xc, yc) and radius r: ");
    fflush(stdout);
    if (scanf("%d%d%d", &xc, &yc, &r) != 3) {
        printf("Invalid input!\n");
        return 1;
    }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
    myInit();
    glutDisplayFunc(drawCircle);
    glutMainLoop();
    return 0;
}