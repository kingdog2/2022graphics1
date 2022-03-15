# 2022graphics1
## 瘋狂無敵圖學死亡筆記 Week01
### 第一個 OpenGL 程式



0. CodeBlocks 17.12 mingw 裝好

1. File-New-Project, 選 OpenGL 專案


2. 在[點點點]的目錄,選桌面,Projectsje nir 01_OPENGL

3. 下一步下一步, 完成後, Build & Run

4. 可以看到彩色旋轉的三角形



### 第一個GLUT專案



1. Moodle 下載 freeglut ..zip
2. 解壓縮 桌面 freeglut目錄
3. 桌面freeglut 的 lib 裡面有 libfreeglut.a才能把她複製,改成 libglut32.a才能與我們的CodeBlocks的GLUT專案連結使用





4. CodeBlocks: File-New-Project. 選 GLUTˋ專案
5. 取名 week01 GLUT
6. 設定 GLUT 目錄 C:\Users\?????\Desktop\freegiut
7. Build & Run ,可以看到6個紅色的東西在旋轉



### GitHub



0.登入GitHub.com
1. New repo 新增傳案倉庫
1.1. 取名 2022graphics(昨天乙班用掉了)或2022graphics1
1.2. Public, Add README, Add .gitignore 用C++
1.3. 綠色確認ㄝ, 看到你的新的專案

2. 利用 Git指令
2.1. 安裝 Git for Windows

3. 開啟 Git Bash
3.1. cd desktop 進入桌面
3.2. git clone http://你的網址
3.3. cd 2022graphics1

3.4. 把我們的2個程式目錄,放到2022graphics1
3.5. git status 看狀態(紅色2個目錄)
3.6. git add . 把它加進去
3.7. git status 再看狀態(變綠色)


4. 要推送上雲端
4.1. 要先有 commit 的動作, 第一次使用時,需

git config --global user.email "jsyeh@mail.mcu.edu.tw"
git config --global user.name "jsyeh"


git commit -m "訊息"

4.2. git push 推送上雲端
(Chrome 要登入才行)

## 瘋狂無敵圖學死亡筆記 Week02
1.  下載範例 https://jsyeh.org/3dcg10

    data.zip windows.zip glut32.dll

2.  windows.zip =解壓=> 下載\windows\Shapes.exe

    data.zip =解壓=> 下載\windows\data\模型

    glut32.dll =複製=> 下載\windows\glut32.dll

3.  跑 Shapes.exe 看範例, 試試看

    左可按右鍵選單: 大頂點、很多顏色

    右可按右鍵選單: POINT....POLYGON 







### step01-1 跑別人的範例
1. 下載範例 https://jsyeh.org/3dcg10
   data.zip windows.zip glut32.dll
2. windows.zip =解壓=> 下載\windows\Shapes.exe
   data.zip =解壓=> 下載\windows\data\模型
   glut32.dll =複製=> 下載\windows\glut32.dll
3. 跑 Shapes.exe 看範例, 試試看
   左可按右鍵選單: 大頂點、很多顏色
   右可按右鍵選單: POINT....POLYGON 



### step01-2 跑你上週的程式
1. 上週的安裝 Git for Windows
2. 上週的 Git Bash: cd desktop, git clone 你的網址
   cd 2022graphics1
3. 上週的安裝 freeglut, 記得改檔名 lib\libglut32.a
4. 在 CodeBlocks File-Open week01_GLUT專案,跑!



### step02-1 親手打造 GLUT的程式 (5-10行)

有了上週的 week01_GLUT 的專案
我們要寫出今天的 week02_color 新專案
1. File-New-Project,選GLUT專案
2. 設好freeglut後
3. 確定有上週的進度後, 大膽的把上週的程式刪掉
4. 寫下今天的10行程式碼,會秀出黃色的茶壼
```c++
///step02-1 10行最精簡的 GLUT程式
///先全刪, 目標: 5-10行,寫完
#include <GL/glut.h> ///使用GLUT外掛,簡化程式

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面

    glColor3f(1,1,0); ///設定色彩
    glutSolidTeapot(0.3); ///實心的茶壼

    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第02週的程式哦!"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```





### step03-1 彩色三角形
接上一節的進度(黃色茶壼),我們想把今天的範例(彩色三角形)跑出來, 所以修改一下,將 glutSolidTeapot(0.3) 改成 glBegin(GL_POLYGON) ... glEnd() 在中間則用 glColor3f()及glVertex2()來標定色彩、頂點座標
```c++
///step02-1 10行最精簡的 GLUT程式
///先全刪, 目標: 5-10行,寫完
#include <GL/glut.h> ///使用GLUT外掛,簡化程式

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面

    glColor3f(1,1,0); ///設定色彩
    ///glutSolidTeapot(0.3); ///實心的茶壼
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);///紅色
        glVertex2f(-1, -1);

        glColor3f(0,1,0);///綠色
        glVertex2f(+1, -1);

        glColor3f(0,0,1);///藍色
        glVertex2f(0, +1);
    glEnd();

    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第02週的彩色三角形哦!"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```
## 瘋狂無敵圖學死亡筆記 Week03
### 0. 開啟 blogger

### 1. 範例 https://jsyeh.org/3dcg10/
### 1.1 下載 data, win32
   windows.zip => 下載\windows\Transformation.exe
   data.zip => 下載\windows\data\模型.obj
### 1.2 執行 Transformation.exe
    (右上)右鍵:換模型
    (下)拖曳綠色的數值





### 2. 學習如何移動
```c++
#include <GL/glut.h> ///使用GLUT外掛,簡化程式
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面

    glPushMatrix();///備份矩陣(備份舊的位置)
        ///移動會累積,因為它會修改矩陣
        glTranslatef(0.5,0.5,0);///右上角
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣

    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第02週的程式"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```





### 3.1 利用自己寫的myTeapot函式讓人利用x,y為位置座標
```c++
void myTeapot(float x, float y){
    glPushMatrix();///備份矩陣(備份舊的位置)
        ///移動會累積,因為它會修改矩陣
        glTranslatef(x,y,0);///右上角
        glColor3f(1,1,0);///黃色
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();///還原矩陣
}
```

### 3.2 然後讓人呼叫
```c++
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面
    myTeapot(0.5, 0.5);
    myTeapot(0.5, -0.5);
    myTeapot(-0.5, -0.5);
    myTeapot(-0.5, 0.5);
    glutSwapBuffers();///畫好後,交換出來
}
```

### 3.3 最後顯示畫面
```c++
int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第03週的程式:移動)"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```





### 4. 利用glutMouseFunc()函示讓我們接收滑鼠移動的位置然後用 
myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0) ;接收茶壺要移動多少

```c++
#include <GL/glut.h> ///使用GLUT外掛,簡化程式
float mouseX=0, mouseY=0;
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
    myTeapot((mouseX-150)/150.0,-(mouseY-150)/150.0) ;
    glutSwapBuffers();///畫好後,交換出來
}
void mouse(int button, int state, int x, int y){
    mouseX=x; mouseY=y;
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("第03週的程式:利用滑鼠移動)"); ///開 GLUT 視窗

    glutDisplayFunc(display); ///用來顯示的函式
    glutMouseFunc(mouse);
    glutMainLoop(); ///主要的程式迴圈
}
```





### 5. 小黑視窗右下為最大(300,300)

```c++
void mouse(int button, int state, int x, int y){
    printf("%d %d %d %d", button, state, x, y);
    mouseX=x; mouseY=y;
}
```


### 6. 可以利用小畫家得知座標位置或是顏色喔!!!只是顏色要/255.0
ex:
```c++
glColor3f(255/255.0,100/255.0,243/255.0);
```

## 瘋狂無敵圖學死亡筆記 Week04
### 1. 今天教旋轉

    glRotatef()

    第一個為旋轉角度有正負(看軸轉)

    二三四為旋轉軸分別代表xyz(自己定義軸)




###2. 用程式做(freeglut記得載然後複製改檔名)

```c++
#include <GL/glut.h>
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(90, 0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();

}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

#***git技能
##git commit -m "修改名稱" --date "2022-03-08 12:00:00"

###3. 用glutMotionFunc()互動讓滑鼠往左右拖能改變angle

```c++
    #include <GL/glut.h>
    float angle=0;
    void display(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();///備份矩陣
            glRotatef(angle, 0,0,1);
            glutSolidTeapot(0.3);
        glPopMatrix();///還原矩陣
        glutSwapBuffers();

    }
    void motion(int x, int y){
        angle=x;
        display();///重畫畫面

    }
    int main(int argc, char** argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("Week04 Rotate");

        glutDisplayFunc(display);
        glutMotionFunc(motion);///mouse motion動
        glutMainLoop();

    }
```




#****重點glutMouseFunc() && glutMotionFunc()的差別****

##glutMouseFunc()用點的
##glutMotionFunc()用拖的

###4. 旋轉記住oldx位址繼續轉用新x-oldx

```c++
    #include <GL/glut.h>
    float angle=0, oldx=0;
    void display(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();///備份矩陣
            glRotatef(angle, 0,0,1);
            glutSolidTeapot(0.3);
        glPopMatrix();///還原矩陣
        glutSwapBuffers();

    }
    void motion(int x, int y){///拖的時候要跑
        angle+=(x-oldx);
        oldx=x;///拖的也有座標再跑
        display();///重畫畫面

    }
    void mouse(int button, int state, int x, int y){///按、放要跑
        oldx=x;///定錨

    }
    int main(int argc, char** argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("Week04 Rotate");

        glutDisplayFunc(display);
        glutMotionFunc(motion);///mouse motion動
        glutMouseFunc(mouse);///按下、放開
        glutMainLoop();


    }
```



###5. 買上點買上畫部用向上次複製貼上
複習上週教的「用滑鼠寫程式」,,利用mx[]及my[]把座標備份在裡面,配合N記錄有幾個座標。再於display()裡面,利用for迴圈,把這些座標利用GL_LINE_LOOP畫出來看。

```c++
///上週的複習
#include <GL/glut.h>
#include <stdio.h>
int mx[1000],my[1000];///用來備份你的mouse的座標
int N=0;///有幾個點按好了?
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){
        glVertex2f( (mx[i]-150)/150.0, -(my[i]-150)/150.0 );
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{//  printf("%d %d %d %d\n", button, state, x, y);
    if(state==GLUT_DOWN){///如果state是按下去0,才印程式碼
        printf("    glVertex2f( (%d-150)/150.0, -(%d-150)/150.0 );\n", x, y);
        N++;
        mx[N-1]=x; my[N-1]=y;
    }
    display();///重畫
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week04 Rotate");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///上週教: mouse按下去、放開來
    glutMainLoop();
}
```





