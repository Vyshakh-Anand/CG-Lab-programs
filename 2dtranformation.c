#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x1_line, y1_line, x2_line, y2_line;
int choice;
float tx, ty, sx, sy, angle;

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
    glMatrixMode(GL_MODELVIEW);  // Add this!
}

void drawLine(int x1, int y1, int x2, int y2) {
    glBegin(GL_LINES);
        glVertex2i(x1, y1);
        glVertex2i(x2, y2);
    glEnd();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw original line in black
    glColor3f(0.0, 0.0, 0.0);
    drawLine(x1_line, y1_line, x2_line, y2_line);
    
    int x1 = x1_line, y1 = y1_line, x2 = x2_line, y2 = y2_line;
    
    if (choice == 1) {  // Translation
        x1 += tx; 
        y1 += ty;
        x2 += tx; 
        y2 += ty;
    }
    else if (choice == 2) {  // Scaling
        x1 = (int)(x1 * sx); 
        y1 = (int)(y1 * sy);
        x2 = (int)(x2 * sx); 
        y2 = (int)(y2 * sy);
    }
    else if (choice == 3) {  // Rotation
        float rad = angle * 3.14159 / 180.0;
        int x1_new = (int)(x1 * cos(rad) - y1 * sin(rad));
        int y1_new = (int)(x1 * sin(rad) + y1 * cos(rad));
        int x2_new = (int)(x2 * cos(rad) - y2 * sin(rad));
        int y2_new = (int)(x2 * sin(rad) + y2 * cos(rad));
        x1 = x1_new; 
        y1 = y1_new;
        x2 = x2_new; 
        y2 = y2_new;
    }
    
    // Draw transformed line in red
    glColor3f(1.0, 0.0, 0.0);
    drawLine(x1, y1, x2, y2);
    
    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter line coordinates (x1, y1, x2, y2): ");
    fflush(stdout);
    scanf("%d %d %d %d", &x1_line, &y1_line, &x2_line, &y2_line);
    
    printf("\n1. Translation\n2. Scaling\n3. Rotation\nEnter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter tx, ty: ");
        scanf("%f %f", &tx, &ty);
    } 
    else if (choice == 2) {
        printf("Enter sx, sy: ");
        scanf("%f %f", &sx, &sy);
    } 
    else if (choice == 3) {
        printf("Enter rotation angle: ");
        scanf("%f", &angle);
    }
    else {
        printf("Invalid choice!\n");
        return 1;
    }
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Line Transformation");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}