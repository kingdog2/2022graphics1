#include <GL/glut.h>
#include <stdio.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();


}
void keyboard(unsigned char key, int x, int y){///輸入中文會被os擋住
    printf("你按下了%c滑鼠在%d%d座標\n",key,x,y);
}
int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("week05 keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///今天主角
    glutMainLoop(); ///主要的程式迴圈
}
