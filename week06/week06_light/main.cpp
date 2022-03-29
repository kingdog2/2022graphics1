#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150, y=150, z=0, scale=1.0, angle=0.0;
int oldX=0, oldY=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�e�ϫe, ���M�e��


        glPushMatrix();///�ƥ��x�}
            glTranslatef((x-150)/150.0,-(y-150)/150.0,z);///����
            glRotatef(angle, 0, 1, 0);///��Y�b����
            glScalef(scale, scale, scale);///�Y��scale��+
            glColor3f(1,1,0);///����
            glutSolidTeapot(0.3);
        glPopMatrix();///�٭�x�}

    glutSwapBuffers();///�e�n��,�洫�X��
}
void mouse(int button, int state, int mouseX, int mouseY){
    ///���F�ѨM�������ʪ����D,��Ω���첾
    oldX=mouseX;
    oldY=mouseY;
}
void motion(int mouseX,int mouseY){
//    if(mouseX-oldX>0) scale *=1.01;///�Y��
//    if(mouseX-oldX<0) scale *=0.99;
    angle += (mouseX - oldX);///����
    /*x+=(mouseX-oldX);///����
    y+=(mouseY-oldY);*/
    oldX=mouseX;
    oldY=mouseY;
    display();///���e
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 Light");

    glutDisplayFunc(display);


    glEnable(GL_DEPTH_TEST);///3D�\��
    glDepthFunc(GL_LIGHT0);///�w�q�@���O


    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


    glutMouseFunc(mouse);///�Ĥ@�N�D��
    glutMotionFunc(motion);///�ĤG�N�D��
    glutMainLoop(); ///�D�n���{���j��
}
