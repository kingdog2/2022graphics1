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




### 2. 用程式做(freeglut記得載然後複製改檔名)

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

# ***git技能
## git commit -m "修改名稱" --date "2022-03-08 12:00:00"

### 3. 用glutMotionFunc()互動讓滑鼠往左右拖能改變angle

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




# ****重點glutMouseFunc() && glutMotionFunc()的差別****

## glutMouseFunc()用點的
## glutMotionFunc()用拖的

### 4. 旋轉記住oldx位址繼續轉用新x-oldx

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



### 5. 買上點買上畫部用向上次複製貼上
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







## week05
### 0. 移動、旋轉、縮放、矩陣

### 1.  學習如何用鍵盤

## ***輸入中文會被os擋住


```c++
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
```





2. 學會用keyboard跟mouse與motion結合


```c++
#include <GL/glut.h>

#include <stdio.h>

float x=150, y=150, z=0;///讓圖在中心

int oldX=0, oldY=0;



void display(){

     

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glPushMatrix();///備份矩陣

        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);

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

    x+=(mouseX-oldX);

    y+=(mouseY-oldY);

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
```






3. 滑鼠x左右放大縮小

```c++
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
    if(mouseX-oldX>0) scale *=1.01;///縮放
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
```




## ***gist(git的功能能分享程式碼)且blogger右上有html視略







## 把gist連結放在blogger的html視略下面




## 瘋狂無敵圖學死亡筆記 Week06
### 0. 打光Light Material

(左上)左鍵drag可旋轉

(左上)右鍵換模型

(左下)右鍵換material

glLightfv() ***float為浮點數 vector是陣列

GLfloat light_pos[]={-2.0,2.0,2.0,1.0};陣列

glLightfv(GL_LIGHT0,GL_POSITION,陣列)

光的性質(位置,Ambient,Diffuse,Specular)

                 第幾盞燈       設定它的位置


### 1.

## ***Ctrl-F找light偷下面程式

```c++
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };

const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };



const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };

const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };

const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };

const GLfloat high_shininess[] = { 100.0f };
```

```c++
 glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
```


### 1-1. 做有燈光茶壺

```c++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面
        glColor3f(1,1,0); ///設定色彩
        glutSolidTeapot(0.3); ///實心的茶壼
    glutSwapBuffers();///畫好後,交換出來
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 Light");

    glutDisplayFunc(display);


    glEnable(GL_DEPTH_TEST);///3D功能
    glDepthFunc(GL_LIGHT0);///定義第一盞燈


    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


    glutMainLoop(); ///主要的程式迴圈
}
```



### 1-2. 融合上週mouse放大小

```c++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150, y=150, z=0, scale=1.0;
int oldX=0, oldY=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面

00000000
        glPushMatrix();///備份矩陣
            glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
            glScalef(scale, scale, scale);///都縮放成scale倍+
            glColor3f(1,1,0);///黃色
            glutSolidTeapot(0.3);
        glPopMatrix();///還原矩陣

    glutSwapBuffers();///畫好後,交換出來
}
void mouse(int button, int state, int mouseX, int mouseY){
    ///為了解決瞬間移動的問題,改用延續拖移
    oldX=mouseX;
    oldY=mouseY;
}
void motion(int mouseX,int mouseY){
    if(mouseX-oldX>0) scale *=1.01;///縮放
    if(mouseX-oldX<0) scale *=0.99;
    /*x+=(mouseX-oldX);
    y+=(mouseY-oldY);*/
    oldX=mouseX;
    oldY=mouseY;
    display();///重畫
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 Light");

    glutDisplayFunc(display);


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LIGHT0);


    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


    glutMouseFunc(mouse);///第一代主角
    glutMotionFunc(motion);///第二代主角
    glutMainLoop(); ///主要的程式迴圈
}
```

### 1-3. 移動、旋轉、縮放

```c++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150, y=150, z=0, scale=1.0, angle=0.0;
int oldX=0, oldY=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面


        glPushMatrix();///備份矩陣
            glTranslatef((x-150)/150.0,-(y-150)/150.0,z);///移動
            glRotatef(angle, 0, 1, 0);///對Y軸旋轉
            glScalef(scale, scale, scale);///縮放成scale倍+
            glColor3f(1,1,0);///黃色
            glutSolidTeapot(0.3);
        glPopMatrix();///還原矩陣

    glutSwapBuffers();///畫好後,交換出來
}
void mouse(int button, int state, int mouseX, int mouseY){
    ///為了解決瞬間移動的問題,改用延續拖移
    oldX=mouseX;
    oldY=mouseY;
}
void motion(int mouseX,int mouseY){
//    if(mouseX-oldX>0) scale *=1.01;///縮放
//    if(mouseX-oldX<0) scale *=0.99;
    angle += (mouseX - oldX);///旋轉
    /*x+=(mouseX-oldX);///移動
    y+=(mouseY-oldY);*/
    oldX=mouseX;
    oldY=mouseY;
    display();///重畫
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 Light");

    glutDisplayFunc(display);


    glEnable(GL_DEPTH_TEST);///3D功能
    glDepthFunc(GL_LIGHT0);///定義一盞燈


    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);


    glutMouseFunc(mouse);///第一代主角
    glutMotionFunc(motion);///第二代主角
    glutMainLoop(); ///主要的程式迴圈
}
```

### 2.all用移動mouse、keyboard、motion
用鍵盤輸入要控制移動、旋轉還是縮放

```c++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150, y=150, z=0, scale=1.0, angle=0.0;
int oldX=0, oldY=0, now=1;///1.移動 2.旋轉 3.縮放
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面


        glPushMatrix();///備份矩陣
            glTranslatef((x-150)/150.0,-(y-150)/150.0,z);///移動
            glRotatef(angle, 0, 1, 0);///對Y軸旋轉
            glScalef(scale, scale, scale);///縮放成scale倍+
            glColor3f(1,1,0);///黃色
            glutSolidTeapot(0.3);
        glPopMatrix();///還原矩陣

    glutSwapBuffers();///畫好後,交換出來
}
void keyboard(unsigned char key, int mouseX, int mouseY){///輸入中文會被os擋住

    if(key=='1' || key=='w' || key=='W')now=1;///移動
    if(key=='2' || key=='e' || key=='E')now=2;///旋轉
    if(key=='3' || key=='r' || key=='R')now=3;///縮放

}
void mouse(int button, int state, int mouseX, int mouseY){
    ///為了解決瞬間移動的問題,改用延續拖移
    oldX=mouseX;
    oldY=mouseY;
}
void motion(int mouseX,int mouseY){

    if(now==1){
        x+=(mouseX-oldX);///移動
        y+=(mouseY-oldY);
    }
    else if(now==2){
        angle += (mouseX - oldX);///旋轉
    }
    else if(now==3){
        if(mouseX-oldX>0) scale *=1.01;///縮放
        if(mouseX-oldX<0) scale *=0.99;
    }

    oldX=mouseX;
    oldY=mouseY;
    display();///重畫
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 Light");

    glutDisplayFunc(display);


    glEnable(GL_DEPTH_TEST);///3D功能
    glDepthFunc(GL_LIGHT0);///定義一盞燈


    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutKeyboardFunc(keyboard);///第0代主角
    glutMouseFunc(mouse);///第一代主角
    glutMotionFunc(motion);///第二代主角
    glutMainLoop(); ///主要的程式迴圈
}
```
## 瘋狂無敵圖學死亡筆記 Week08

### 了解OBJ模型檔 (v vt vn f)、介紹glm.h glm.cpp (c)與.cbp專案 .obj物件 .mtl材質 



### 0.  jsyeh.org/3dcg10 下載

windows.zip => 下載\windows\Light Material.exe

data.zip    => 下載\windows\data\ 3D模型

source.zip 

執行 Light Material.exe 今天的主角(打光/模型)



### 0-1. freeglut Moodle下載/安裝, lib\libglut32.a

File-New-Project, GLUT專案, 偷它的程式 放 Notepad++

GLUT callback 像是 display() mouse() motion() keyboard(), 有期中考題,像是 glPushMatrix()等, 重點是打光的陣列、打光的函式.zip





#include <GL/glut.h>



GLUT callback ? 會被 GLUT 呼叫的函式

我們寫的那些display() keyboard() mouse() motion()函式





### 0-2. 從 GitHub 拿出上週的程式!!! week06_light 

git 下載你上週的程式

git clone 下來 或在你的專案資料夾裡 git pull

把 week06_light\main.cpp 用 Notepad++ 開起來, copy

paste 到 week08_model 的 main.cpp

執行,會看到打光的黃色茶壼





### 0-3. 把 source.zip 看裡面的3個程式 glm.h glm.c lightmaterial.cpp, 拿裡面的程式來用,便能讀入3D模型




### 0-4. 把 source.zip 看裡面的3個程式 glm.h glm.c 研究 lightmaterial.cpp, 拿裡面的程式來用,便能讀入3D模型, 要include 雙引號的 glm.h 要把 glm.c改檔名成glm.cpp 並加入專案, 再用 Notepad++研究學習lightmaterial.c的程式內容 .zip



1. glm.h 我們要 include 它

2. glm.c 改檔名 glm.cpp 要加入專案

3. lightmaterial.cpp 用 Notepad++ 偷


```c++
#include <GL/glut.h> //角括號,是系統的include裡 的檔案

#include "glm.h" //雙引號,同目錄裡 的檔案





GLMmodel* pmodel = NULL; //指到GLMmodel模型的指標,NULL代表還沒好





void drawmodel(void)

{

    if (!pmodel) {

	pmodel = glmReadOBJ("data/soccerball.obj");

	if (!pmodel) exit(0);

	glmUnitize(pmodel);

	glmFacetNormals(pmodel);

	glmVertexNormals(pmodel, 90.0);

    }



    glmDraw(pmodel, GLM_SMOOTH);

}///用來畫3D模型的程式碼, "學習它"
```




### 2. 畫 3D 模型檔

把 glutSolidTeapot()改成畫 drawmodel(), 要在CodeBlocks下方 藍色Build Log 找你的 working dir 工作目錄:(in C:\Users\...\Desktop\freeglut\bin\)目錄, 在裡面放 data資料夾, 以便讀取 data裡的模型, 再把glm.cpp 及 glm.h 放在 week08_model 目錄中, 再 Add files 把 glm.cpp 加到專案中





### 2-1. 各種模形都可以放在專案 week08_model (記得File-Save Project存檔, 放到 GitHub 裡)



### 2-2. 介紹3D模型相關資料

1. Wavefront OBJ 檔 https://zh.wikipedia.org/wiki/Wavefront_.obj%E6%96%87%E4%BB%B6

2. Wavefront OBJ 英文介紹較詳細https://en.wikipedia.org/wiki/Wavefront_.obj_file

3. OBJ vs. MTL 檔

4. v 是 vertex, vn 是 vertex normal, vt 是 vertex texture貼圖 coordinate, f 是 face 面



### 3. 期中考 OpenGL 必背10函式
```c++
  glPushMatrix(); //備份矩陣

   glTranslatef(x,y,z);//移動

    glRotatef(角度, x,y,z);//轉動

    glScalef(x,y,z);//縮放

   glBegin(GL_POLYGON);//開始畫

     glColor3f(r,g,b);//色彩

      glTexCoord2f(tx, ty);//貼圖座標

      glNormal3f( nx,ny,nz);//打光法向量

      glVertex3f(x,y,z);//頂點

  glEnd();//結束畫
  
glPopMatrix(); //還原矩陣
```
## 瘋狂無敵圖學死亡筆記 Week09
### 0.貼圖座標glTexCoord2f(tx,ty)


glTexCoord2f(0.0,0.0)由左下開始(逆時針跑)
(0.0,1.0)    <---    (1.0,1.0)
			^
                        ^
			^
(0.0,0.0)     --->   (1.0,0.0)

### 1.OpenCV讀圖、秀圖 OpenCV 2.1.0 vs2008 版

安裝時注意事項

(1)選第二個 add PATH(程式執行會去找exe或dll的目錄路徑)

(2)預設目錄

# ***bin include lib

bin二進位執行檔

include外掛

### 2.存成week09_opencv.cpp

```c++

#include <opencv/highgui.h>//使用opencv外掛

int main(){

///Ipl:Intel perfromance library

    IplImage *img =cvLoadImage("檔名.png"); //讀檔

    cvShowImage("Week09", img);  //秀圖

    cvWaitKey( 0 ); //等待任意鍵繼續

}

```






### 2-1.設定Setting-Comiler設定 Include 目錄

### 2-2.設定Setting-Comiler設定 Lib 目錄

Search Directories

  (Compiler) 對應Include目錄 c:\opencv2.1\include

  (Linker) 對應Lib目錄 c:\opencv2.1\lib

### 2-3.設定Setting-Comiler設定 咒語 Linker Settings加入 cv210、cxcore210、highgui210




### 3. 結合OpenCV 和 OpenGL 把10行茶壺glut+3-5行opnecv讀圖秀圖
```c++
#include <GL/glut.h> ///使用GLUT外掛,簡化程式
#include <opencv/highgui.h>

void myTextrue(){
     Iplmage *img = cvLoadImage("檔案.png"); //讀檔

    cvShowImage("Week09", img);  //秀圖

    ///cvWaitKey( 0 ); //需要按任意見才能讓茶壺到glutMainLoop(),可以不用寫,因為有glutMainLoop()
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
    myTextrue();///執行這視窗

    glutMainLoop(); ///主要的程式迴圈
}
```


### 3-1圖檔放在 工作目錄 (in C:\Users\User\Desktop\freeglut\bin)

## 瘋狂無敵圖學死亡筆記 Week10
### 0.用上週改為圖在茶壺上 
```c++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>

int myTexture(char * filename)
{

    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖

    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)

    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能

    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID

    glGenTextures(1, &id); /// 產生Generate 貼圖ID

    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);

    return id;

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glutSolidTeapot( 0.3 );

    glutSwapBuffers();

}

int main(int argc, char**argv){

    glutInit( &argc, argv );

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);

    myTexture("OIP.png");

    glutMainLoop();

}
```
### 1.背景
```c++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)

{

    IplImage * img = cvLoadImage(filename);

    cvCvtColor(img,img, CV_BGR2RGB); 

    glEnable(GL_TEXTURE_2D); 

    GLuint id; 

    glGenTextures(1, &id); 

    glBindTexture(GL_TEXTURE_2D, id); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);

    return id;

}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ///glutSolidTeapot( 0.3 );

    glBegin(GL_POLYGON);

        glTexCoord2f(0,1); glVertex2f(-1,-1);

        glTexCoord2f(1,1); glVertex2f(+1,-1);

        glTexCoord2f(1,0); glVertex2f(+1,+1);

        glTexCoord2f(0,0); glVertex2f(-1,+1);

    glEnd();

    glutSwapBuffers();

}

int main(int argc, char**argv){

    glutInit( &argc, argv );

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);

    myTexture("OIP.png");

    glutMainLoop();

}
```

### 2.地球

球

gluSphere( sphere, 1, 30, 30 );

參數是(指標,r半徑,slices柳丁切經縣,stack堆疊緯)


```c++
#include <opencv/highgui.h> 
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere =NULL; ///指標只到二次曲面
int myTexture(char * filename)
{

    IplImage * img = cvLoadImage(filename); 
    cvCvtColor(img,img, CV_BGR2RGB); 
    glEnable(GL_TEXTURE_2D); 
    GLuint id; 
    glGenTextures(1, &id); 
    glBindTexture(GL_TEXTURE_2D, id); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluQuadricTexture(sphere, 1); ///設好貼圖
    gluSphere(sphere, 1, 30, 30); ///畫圓球
    glutSwapBuffers();

}

int main(int argc, char**argv){

    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");


    glutDisplayFunc(display);
    myTexture("OIP.png"); ///地球的地圖，圖等一下準備好
    sphere=gluNewQuadric(); ///準備好二次曲面


    glutMainLoop();

}
```
### 2-1能轉動的地球
```c++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere =NULL; ///指標只到二次曲面
int myTexture(char * filename)
{

    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB); 
    glEnable(GL_TEXTURE_2D);
    GLuint id; 
    glGenTextures(1, &id); 
    glBindTexture(GL_TEXTURE_2D, id); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///旋轉角度
void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        gluQuadricTexture(sphere, 1); ///設好貼圖
        gluSphere(sphere, 1, 30, 30); ///畫圓球
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01; ///每次執行dispaly()時angle+1(看電腦好的轉少點)
}

int main(int argc, char**argv){

    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutIdleFunc(display); ///有空idle 呼叫display()
    glutDisplayFunc(display);
    myTexture("OIP.png"); ///地球的地圖，圖等一下準備好
    sphere=gluNewQuadric(); ///準備好二次曲面


    glutMainLoop();

}
```
```c++
#include <opencv/highgui.h> 
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere =NULL; ///指標只到二次曲面
int myTexture(char * filename)
{

    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB); 
    glEnable(GL_TEXTURE_2D);
    GLuint id; 
    glGenTextures(1, &id); 
    glBindTexture(GL_TEXTURE_2D, id); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;///旋轉角度
void display(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(90, 1, 0, 0);///把地球轉正，而非由上往下看
        glRotatef(angle, 0, 0, 1);
        gluQuadricTexture(sphere, 1); ///設好貼圖
        gluSphere(sphere, 1, 30, 30); ///畫圓球
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01; ///每次執行dispaly()時angle+1(看電腦好的轉少點)
}

int main(int argc, char**argv){

    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");
   
    glEnable(GL_DEPTH_TEST);///開3D深度測試,才會有3D效果(解決破圖)
    glutIdleFunc(display); ///有空idle 呼叫display()
    glutDisplayFunc(display);
    myTexture("OIP.png"); ///地球的地圖，圖等一下準備好
    sphere=gluNewQuadric(); ///準備好二次曲面

    glutMainLoop();

}
```
### 3. 貼圖+模型(!做鋼彈咯!!!!!)
    1.下載https://jsyeh.org/3dcg10的window.zip data.zip source.zip(glm.h glm.cpp放在專案目錄)
    2.下載老師買的模型 myGundam 3D模型
    3.工作目錄在 (in C:\Users\User\Desktop\freeglut\bin)
    4.glm.h glm.cpp放在專案main.cpp旁邊
    5.利用上面地球模型改
    
## 瘋狂無敵圖學死亡筆記 Week11
### 0.做鋼彈 

### 0-1. 把鋼彈資料夾裡的data放在工作目錄裡，即可用鋼彈貼圖




### 0-1. 讀完圖試把圖貼在茶壺上
```c++
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("第11週的程式哦!");

    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    glutMainLoop();
}
```


### 1. glm模型練型:把模型讀進來，畫出來
### 1-1. source.zip的一些檔案傳入專案


### 1-2. 把glm.c改成.cpp



### 1-3. 讀鋼彈模型與鋼彈貼圖並套用
```c++
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>///這是電腦裡要設定include
#include "glm.h"///這是導入專案目錄裡的
GLMmodel * pmodel =NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(pmodel == NULL){///如果是空指標，表示模型沒有準備好
        pmodel=glmReadOBJ("data/Gundam.obj");///就讀模型
        glmUnitize(pmodel);///換算成Unit單位大小 -1........1
        glmFacetNormals(pmodel);///重新計算面的法向量
        glmVertexNormals(pmodel,90);///重新計算的頂點的法向量
    }
    glmDraw(pmodel, GLM_TEXTURE);///有模型後,畫面,要記得畫貼圖
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("第11週的程式哦!");

    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    glutMainLoop();
}
```
### 1-4. 上圖鋼彈模型有點前後壓扁
### 1.便3d
### 2.轉動它
```c++
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>///這是電腦裡要設定include
#include "glm.h"///這是導入專案目錄裡的
GLMmodel * pmodel =NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(pmodel == NULL){///如果是空指標，表示模型沒有準備好
        pmodel=glmReadOBJ("data/Gundam.obj");///就讀模型
        glmUnitize(pmodel);///換算成Unit單位大小 -1........1
        glmFacetNormals(pmodel);///重新計算面的法向量
        glmVertexNormals(pmodel,90);///重新計算的頂點的法向量
    }

    glPushMatrix();
        glRotatef(angle,0,1,0);///全身一起轉
        glmDraw(pmodel, GLM_TEXTURE);///有模型後,畫面,要記得畫貼圖
    glPushMatrix();

    glutSwapBuffers();
    angle+=0.00001;
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("第11週的程式哦!");

    glutIdleFunc(display);///有空呼叫display
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);///3D

    glutMainLoop();
}
```
### 2.可用maya切模型讓個別部位做旋轉
### 2-1.把各部位接起來
### 2-2 茶壺當手腳，並讓手轉動
```c++
#include <GL/glut.h> ///使用GLUT外掛,簡化程式
void hand(){
    glColor3f(0,1,0);
    glutSolidTeapot(0.2);
}
void body(){
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
}
float angle=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///畫圖前, 先清畫面
    body();
    glPushMatrix();
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
    glPopMatrix();
    glutSwapBuffers();///畫好後,交換出來
    angle+=0.05;
}

int main(int argc, char** argv) ///main()主函式 進階版
{
    glutInit( &argc, argv); ///把參數,送給 glutInit 初始化
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH ); ///雙緩衡區 + 3D深度功能
    glutCreateWindow("week11 組裝頭手讓手轉動"); ///開 GLUT 視窗

    glutIdleFunc(display);
    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主要的程式迴圈
}
```


