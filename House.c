#include <GL/glut.h>

void myInit(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();  // Add this for clean matrix
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glMatrixMode(GL_MODELVIEW);  // Switch back to modelview
}

void drawHouse(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Roof (Triangle)
    glColor3f(0.8, 0.4, 0.2);  // Orange-brown roof color
    glBegin(GL_TRIANGLES);
        glVertex2i(200, 350);
        glVertex2i(70, 200);
        glVertex2i(330, 200);
    glEnd();
    
    // Main house body
    glColor3f(0.7, 0.7, 0.7);  // Gray walls
    glBegin(GL_POLYGON);
        glVertex2i(100, 200);
        glVertex2i(300, 200);
        glVertex2i(300, 50);
        glVertex2i(100, 50);
    glEnd();
    
    // Door
    glColor3f(0.4, 0.2, 0.0);  // Dark brown door
    glBegin(GL_POLYGON);
        glVertex2i(180, 150);
        glVertex2i(220, 150);
        glVertex2i(220, 50);
        glVertex2i(180, 50);
    glEnd();
    
    // Left window
    glColor3f(0.0, 0.5, 0.5);  // Teal/cyan window
    glBegin(GL_POLYGON);
        glVertex2i(120, 180);
        glVertex2i(160, 180);
        glVertex2i(160, 140);
        glVertex2i(120, 140);
    glEnd();
    
    // Right window
    glColor3f(0.0, 0.5, 0.5);  // Teal/cyan window
    glBegin(GL_POLYGON);
        glVertex2i(240, 180);
        glVertex2i(280, 180);
        glVertex2i(280, 140);
        glVertex2i(240, 140);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 100);
    glutCreateWindow("Simple House");
    myInit();
    glutDisplayFunc(drawHouse);
    glutMainLoop();
    return 0;
}