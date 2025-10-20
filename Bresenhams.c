#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x_0, y_0, x_1, y_1;  // Changed variable names

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawLineBresenham(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    int dx = abs(x_1 - x_0);
    int dy = abs(y_1 - y_0);
    int sx = (x_0 < x_1) ? 1 : -1;
    int sy = (y_0 < y_1) ? 1 : -1;
    int err = dx - dy;
    int x = x_0;
    int y = y_0;
    
    glBegin(GL_POINTS);
    
    while (1) {
        glVertex2i(x, y);
        
        if (x == x_1 && y == y_1) break;
        
        int e2 = 2 * err;
        
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter values of x0, y0, x1, y1: ");
    fflush(stdout);
    if (scanf("%d%d%d%d", &x_0, &y_0, &x_1, &y_1) != 4) {
        printf("Invalid input!\n");
        return 1;
    }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");
    myInit();
    glutDisplayFunc(drawLineBresenham);
    glutMainLoop();
    return 0;
}