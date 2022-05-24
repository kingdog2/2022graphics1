///week14_timer_auto
#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){
    printf("wake up,time is: %d\n", t);
    PlaySound("do.wav", NULL, SND_ASYNC);
    glutTimerFunc(1000, timer, t+1);
}
void display(){

}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14 timetr");

    ///1000代表1秒
    glutTimerFunc(5000, timer, 0); ///5秒後開始第0個timer
    glutDisplayFunc(display);
    glutMainLoop();
}
