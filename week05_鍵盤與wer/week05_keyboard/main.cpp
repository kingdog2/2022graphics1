#include <GL/glut.h>
#include <stdio.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();


}
void keyboard(unsigned char key, int x, int y){///��J����|�Qos�צ�
    printf("�A���U�F%c�ƹ��b%d%d�y��\n",key,x,y);
}
int main(int argc, char** argv) ///main()�D�禡 �i����
{
    glutInit( &argc, argv); ///��Ѽ�,�e�� glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///���w�Ű� + 3D�`�ץ\��
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///���ѥD��
    glutMainLoop(); ///�D�n���{���j��
}
