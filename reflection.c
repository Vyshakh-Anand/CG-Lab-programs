#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int x1_t, y1_t, x2_t, y2_t, x3_t, y3_t;
int choice;

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
    
    int x1_new = x1_t, y1_new = y1_t;
    int x2_new = x2_t, y2_new = y2_t;
    int x3_new = x3_t, y3_new = y3_t;
    
    // Apply reflection based on choice
    if (choice == 1) {  // Reflection about X-axis
        y1_new = -y1_t;
        y2_new = -y2_t;
        y3_new = -y3_t;
    } 
    else if (choice == 2) {  // Reflection about Y-axis
        x1_new = -x1_t;
        x2_new = -x2_t;
        x3_new = -x3_t;
    } 
    else if (choice == 3) {  // Reflection about origin
        x1_new = -x1_t;
        y1_new = -y1_t;
        x2_new = -x2_t;
        y2_new = -y2_t;
        x3_new = -x3_t;
        y3_new = -y3_t;
    }
    
    // Draw reflected triangle in red
    glColor3f(1.0, 0.0, 0.0);
    drawTriangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new);
    
    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter coordinates of triangle (x1 y1 x2 y2 x3 y3): ");
    fflush(stdout);
    scanf("%d %d %d %d %d %d", &x1_t, &y1_t, &x2_t, &y2_t, &x3_t, &y3_t);
    
    printf("\nReflection options:\n");
    printf("1. X-axis\n");
    printf("2. Y-axis\n");
    printf("3. Origin\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > 3) {
        printf("Invalid choice!\n");
        return 1;
    }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Reflection of Triangle");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}