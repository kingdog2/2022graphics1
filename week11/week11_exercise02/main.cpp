#include <GL/glut.h> ///�ϥ�GLUT�~��,²�Ƶ{��
void hand(){
    glColor3f(0,1,0);
    glutSolidTeapot(0.2);
}
void body(){
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
}
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�e�ϫe, ���M�e��
    body();
    glPushMatrix();
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
    glPopMatrix();
    glutSwapBuffers();///�e�n��,�洫�X��
    angle+=0.05;
}

int main(int argc, char** argv) ///main()�D�禡 �i����
{
    glutInit( &argc, argv); ///��Ѽ�,�e�� glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///���w�Ű� + 3D�`�ץ\��
    glutCreateWindow("week11 �ո��Y���������"); ///�} GLUT ����

    glutIdleFunc(display);
    glutDisplayFunc(display); ///�Ψ���ܪ��禡

    glutMainLoop(); ///�D�n���{���j��
}
