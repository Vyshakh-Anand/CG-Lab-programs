#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int x1_r, y1_r, x2_r, y2_r, x3_r, y3_r, x4_r, y4_r;
float shx = 0, shy = 0;

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);  // Add this!
}

void drawRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    glBegin(GL_LINE_LOOP);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
        glVertex2i(x3, y3);
        glVertex2i(x4, y4);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw original rectangle in black
    glColor3f(0.0, 0.0, 0.0);
    drawRectangle(x1_r, y1_r, x2_r, y2_r, x3_r, y3_r, x4_r, y4_r);
    
    // Apply shear transformation
    int x1_new = x1_r + (int)(shx * y1_r);
    int y1_new = y1_r + (int)(shy * x1_r);
    int x2_new = x2_r + (int)(shx * y2_r);
    int y2_new = y2_r + (int)(shy * x2_r);
    int x3_new = x3_r + (int)(shx * y3_r);
    int y3_new = y3_r + (int)(shy * x3_r);
    int x4_new = x4_r + (int)(shx * y4_r);
    int y4_new = y4_r + (int)(shy * x4_r);
    
    // Draw sheared rectangle in red
    glColor3f(1.0, 0.0, 0.0);
    drawRectangle(x1_new, y1_new, x2_new, y2_new, x3_new, y3_new, x4_new, y4_new);
    
    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter rectangle coordinates (x1 y1 x2 y2 x3 y3 x4 y4): ");
    fflush(stdout);
    scanf("%d %d %d %d %d %d %d %d", &x1_r, &y1_r, &x2_r, &y2_r, &x3_r, &y3_r, &x4_r, &y4_r);
    
    int choice;
    printf("\n--- Shear Menu ---\n");
    printf("1. X-Shear\n");
    printf("2. Y-Shear\n");
    printf("3. XY-Shear\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter shear factor shx: ");
            scanf("%f", &shx);
            shy = 0;
            break;
        case 2:
            printf("Enter shear factor shy: ");
            scanf("%f", &shy);
            shx = 0;
            break;
        case 3:
            printf("Enter shear factors (shx shy): ");
            scanf("%f %f", &shx, &shy);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Shear Transformation on Rectangle");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}