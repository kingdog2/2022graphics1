///TRT-TRT
#include <GL/glut.h>
float angle=0, oldX=0;
void mouse(int button, int state, int x,int y){
    oldX=x;
}
void motion(int x, int y){
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();///請glut重畫畫面
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///(3)把手臂掛回身體原位T
        glRotatef(angle,0,0,1);///(2)向Z軸旋轉R
        glTranslatef(-0.3,-0.4,0);///(1)把手臂的旋轉中心，放世界中心(0,0)T
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();///手軸
            glTranslatef(0.7,0.4,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);
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

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
