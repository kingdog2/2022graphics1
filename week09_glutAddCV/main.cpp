#include <GL/glut.h> ///使用GLUT外掛,簡化程式
#include <opencv/highgui.h>

void myTextrue(){
    IplImage *img = cvLoadImage("OIP.png"); //讀檔
    cvShowImage("Week09", img);  //秀圖
    cvWaitKey( 0 ); //可以不用寫,因為有glutMainLoop()
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面
    glutSolidTeapot(0.3); ///實心的茶壼

    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第02週的程式哦!"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    myTextrue();
    glutMainLoop(); ///主要的程式迴圈
}
