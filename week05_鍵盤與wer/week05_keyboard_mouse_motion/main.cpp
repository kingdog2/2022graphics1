#include <GL/glut.h>
#include <stdio.h>
float x=150, y=150, z=0, scale=1.0;
int oldX=0, oldY=0;

void display(){
    glClearColor(0.5, 0.5, 0.5, 1);///RGBA(A為透明)
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///備份矩陣
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale, scale, scale);///都縮放成scale倍
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);

    glPopMatrix();///還原矩陣
    glutSwapBuffers();
}

void keyboard(unsigned char key, int mouseX, int mouseY){///輸入中文會被os擋住
    printf("你按下了%c滑鼠在%d%d座標\n", key, mouseX, mouseY);
}

void mouse(int button, int state, int mouseX, int mouseY){
    ///為了解決瞬間移動的問題,改用延續拖移
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
    display();///重畫
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天主角
    glutMouseFunc(mouse);///第一代主角
    glutMotionFunc(motion);///第二代主角
    glutMainLoop(); ///主要的程式迴圈
}
