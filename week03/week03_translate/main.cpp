#include <GL/glut.h> ///使用GLUT外掛,簡化程式
void myTeapot(float x, float y){
    glPushMatrix();///備份矩陣(備份舊的位置)
        ///移動會累積,因為它會修改矩陣
        glTranslatef(x,y,0);///右上角
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面
    myTeapot(0.5, 0.5);
    myTeapot(0.5, -0.5);
    myTeapot(-0.5, -0.5);
    myTeapot(-0.5, 0.5);
    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第03週的程式:移動)"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
