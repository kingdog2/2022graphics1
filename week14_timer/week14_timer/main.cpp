///week14_glutTimeFunc()
#include <GL/glut.h>
#include <stdio.h>
void timer(int t){
    printf("wake up,time is: %d\n", t);
}
void display(){

}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14 timetr");

    glutTimerFunc(1000, timer, 1);///1000¥Nªí1¬í
    glutTimerFunc(2000, timer, 2);
    glutTimerFunc(3000, timer, 3);
    glutTimerFunc(4000, timer, 4);
    glutDisplayFunc(display);
    glutMainLoop();
}
