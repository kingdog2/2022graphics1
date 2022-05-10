#include <GL/glut.h>
float angle=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白色
    glutSolidTeapot(0.3);///茶壺當身體
    ///*右手*
    glPushMatrix();
        glTranslatef(0.2,0,0);  ///掛到身體上
        glRotatef(angle,0,0,1); ///旋轉
        glTranslatef(0.2,0,0);  ///找軸點移到中心(0,0)
        glColor3f(1,0,0);       ///紅色
        glutSolidTeapot(0.2);   ///手臂

        glPushMatrix();///上面的手臂為初點(上面會影響到下面)
            glTranslatef(0.2,0,0);  ///掛到身體上
            glRotatef(angle,0,0,1); ///旋轉
            glTranslatef(0.2,0,0);  ///找軸點移到中心(0,0)
            glColor3f(1,0,0);       ///紅色
            glutSolidTeapot(0.2);   ///手肘
        glPopMatrix();
    glPopMatrix();

    ///*左手*
    glPushMatrix();
        glTranslatef(-0.2,0,0);  ///掛到身體上
        glRotatef(angle,0,0,1); ///旋轉
        glTranslatef(-0.2,0,0);  ///找軸點移到中心(0,0)
        glColor3f(1,0,0);       ///紅色
        glutSolidTeapot(0.2);   ///手臂

        glPushMatrix();///上面的手臂為初點(上面會影響到下面)
            glTranslatef(-0.2,0,0);  ///掛到身體上
            glRotatef(angle,0,0,1); ///旋轉
            glTranslatef(-0.2,0,0);  ///找軸點移到中心(0,0)
            glColor3f(1,0,0);       ///紅色
            glutSolidTeapot(0.2);   ///手肘
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
