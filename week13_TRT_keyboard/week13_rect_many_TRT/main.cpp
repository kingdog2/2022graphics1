///TRT-TRT
#include <GL/glut.h>
float angle[20]={0}, oldX=0;///�}�C�b�~�w�q�|�۰ʳ]��0
int angleID=0;///�X�����`
void keyboard(unsigned char key,int x, int y){
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}
void mouse(int button, int state, int x,int y){
    oldX=x;
}
void motion(int x, int y){
    angle[angleID]+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///��glut���e�e��
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();///�k�b
        glTranslatef(0.3,0.4,0);///(3)����u���^������T
        glRotatef(angle[0],0,0,1);///(2)�VZ�b����R
        glTranslatef(-0.3,-0.4,0);///(1)����u�����त�ߡA��@�ɤ���(0,0)T
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();///��b
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///���b
        glTranslatef(-0.3,0.4,0);///(3)����u���^������T
        glRotatef(angle[2],0,0,1);///(2)�VZ�b����R
        glTranslatef(0.3,-0.4,0);///(1)����u�����त�ߡA��@�ɤ���(0,0)T
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();///��b
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(0.7,-0.4,0);
            glColor3f(0,1,0);
            glRectf(-0.7,0.5,-1.0,0.3);
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
