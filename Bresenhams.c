#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x_0, y_0, x_1, y_1;

void myInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawLineBresenhamSlopeLessThan1(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    int dx = x_1 - x_0;
    int dy = y_1 - y_0;
    int sx = (dx >= 0) ? 1 : -1;
    int sy = (dy >= 0) ? 1 : -1;

    dx = abs(dx);
    dy = abs(dy);

    // Only works for slope < 1
    if (dx < dy) {
        printf("This version only handles slope < 1.\n");
        return;
    }

    int d = 2 * dy - dx;  // initial decision parameter
    int y = y_0;

    glBegin(GL_POINTS);
    for (int x = x_0; x != x_1 + sx; x += sx) { // move x from x0 to x1
        glVertex2i(x, y);
        if (d > 0) {
            y += sy;     // step in y
            d -= 2 * dx; // adjust decision parameter
        }
        d += 2 * dy;     // increment decision parameter
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter values of x0, y0, x1, y1 (slope < 1): ");
    fflush(stdout);
    if (scanf("%d%d%d%d", &x_0, &y_0, &x_1, &y_1) != 4) {
        printf("Invalid input!\n");
        return 1;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing (Slope < 1)");
    myInit();
    glutDisplayFunc(drawLineBresenhamSlopeLessThan1);
    glutMainLoop();
    return 0;
}
