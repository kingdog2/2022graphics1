#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0, scale=1.0;
int oldX=0, oldY=0;

void display(){
    glClearColor(0.5, 0.5, 0.5, 1);///RGBA(A���z��)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///�ƥ��x�}
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale, scale, scale);///���Y��scale��
        glColor3f(1,1,0);///����
        glutSolidTeapot(0.3);

    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
}

void keyboard(unsigned char key, int mouseX, int mouseY){///��J����|�Qos�צ�
    printf("�A���U�F%c�ƹ��b%d%d�y��\n", key, mouseX, mouseY);
}

void mouse(int button, int state, int mouseX, int mouseY){
    ///���F�ѨM�������ʪ����D,��Ω���첾
    oldX=mouseX;
    oldY=mouseY;
}

void motion(int mouseX,int mouseY){
    if(mouseX-oldX>0) scale *=1.01;
    if(mouseX-oldX<0) scale *=0.99;
    /*x+=(mouseX-oldX);
    y+=(mouseY-oldY);*/
    oldX=mouseX;
    oldY=mouseY;
    display();///���e
}

int main(int argc, char** argv) ///main()�D�禡 �i����
{
    glutInit( &argc, argv); ///��Ѽ�,�e�� glutInit ��l��
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///���w�Ű� + 3D�`�ץ\��
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///���ѥD��
    glutMouseFunc(mouse);///�Ĥ@�N�D��
    glutMotionFunc(motion);///�ĤG�N�D��
    glutMainLoop(); ///�D�n���{���j��
}
