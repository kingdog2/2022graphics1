#include <GL/glut.h>
float angle=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ�
    glutSolidTeapot(0.3);///��������
    ///*�k��*
    glPushMatrix();
        glTranslatef(0.2,0,0);  ///���쨭��W
        glRotatef(angle,0,0,1); ///����
        glTranslatef(0.2,0,0);  ///��b�I���줤��(0,0)
        glColor3f(1,0,0);       ///����
        glutSolidTeapot(0.2);   ///���u

        glPushMatrix();///�W�������u�����I(�W���|�v�T��U��)
            glTranslatef(0.2,0,0);  ///���쨭��W
            glRotatef(angle,0,0,1); ///����
            glTranslatef(0.2,0,0);  ///��b�I���줤��(0,0)
            glColor3f(1,0,0);       ///����
            glutSolidTeapot(0.2);   ///��y
        glPopMatrix();
    glPopMatrix();

    ///*����*
    glPushMatrix();
        glTranslatef(-0.2,0,0);  ///���쨭��W
        glRotatef(angle,0,0,1); ///����
        glTranslatef(-0.2,0,0);  ///��b�I���줤��(0,0)
        glColor3f(1,0,0);       ///����
        glutSolidTeapot(0.2);   ///���u

        glPushMatrix();///�W�������u�����I(�W���|�v�T��U��)
            glTranslatef(-0.2,0,0);  ///���쨭��W
            glRotatef(angle,0,0,1); ///����
            glTranslatef(-0.2,0,0);  ///��b�I���줤��(0,0)
            glColor3f(1,0,0);       ///����
            glutSolidTeapot(0.2);   ///��y
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.05;
}
int main(int argc, char**argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
