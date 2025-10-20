        #include <GL/glut.h>
        #include <math.h>
        #include <stdio.h>
        #include <stdlib.h>

        int x1_, y1_, x2_, y2_;

        void display() {
            float x, y, dx, dy, step;
            dx = x2_ - x1_;
            dy = y2_ - y1_;
            if (fabs(dx) > fabs(dy))
                step = fabs(dx);
            else
                step = fabs(dy);
            dx = dx / step;
            dy = dy / step;
            x = x1_;
            y = y1_;
            glClear(GL_COLOR_BUFFER_BIT);
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_POINTS);
            for (int k = 0; k <= step; k++) {
                glVertex2i((int)x, (int)y);
                x += dx;
                y += dy;
            }
            glEnd();
            glFlush();
        }

        void myInit() {
            glClearColor(1.0, 1.0, 1.0, 1.0);
            glColor3f(1.0, 0.0, 0.0);
            gluOrtho2D(0.0, 500.0, 0.0, 500.0);
        }

        int main(int argc, char** argv) {
            printf("Enter (x1, y1, x2, y2): ");
            scanf("%d%d%d%d", &x1_, &y1_, &x2_, &y2_);
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutInitWindowSize(500, 500);
            glutInitWindowPosition(100, 100);
            glutCreateWindow("DDA Line Drawing");
            myInit();
            glutDisplayFunc(display);
            glutMainLoop();
            return 0;
        }
