#include <GL/glut.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(90, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();

}
void mouse(int button, int state, int x, int y){///���B��n�]
        oldx=x;///�w��

    }
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMainLoop();


}
