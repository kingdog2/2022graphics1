#include <GL/glut.h> ///�ϥ�GLUT�~��,²�Ƶ{��
#include <opencv/highgui.h>

void myTextrue(){
    IplImage *img = cvLoadImage("OIP.png"); //Ū��
    cvShowImage("Week09", img);  //�q��
    cvWaitKey( 0 ); //�i�H���μg,�]����glutMainLoop()
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�e�ϫe, ���M�e��
    glutSolidTeapot(0.3); ///��ߪ�����

    glutSwapBuffers();///�e�n��,�洫�X��
}

int main(int argc, char** argv) ///main()�D�禡 �i����
{
    glutInit( &argc, argv); ///��Ѽ�,�e�� glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///���w�Ű� + 3D�`�ץ\��
    glutCreateWindow("��02�g���{���@!"); ///�} GLUT ����

    glutDisplayFunc(display); ///�Ψ���ܪ��禡

    myTextrue();
    glutMainLoop(); ///�D�n���{���j��
}
