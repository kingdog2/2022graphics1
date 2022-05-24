///week14_angle_fprintf_fscanf動畫按r回放
#include <GL/glut.h>
#include <stdio.h>
float angle[20]={0},
oldX=0;///陣列在外定義會自動設為0
int angleID=0;///幾號關節
///檔案功能
FILE *fout = NULL, *fin = NULL;
void myWrite(){
    if(fout == NULL)
        fout = fopen("file.txt", "w");
    for(int i=0;i<20;i++){
        printf("%.1f", angle[i]); ///小黑印出來
        fprintf(fout ,"%.1f", angle[i]); ///檔案印出來
    }
    printf("\n");
    fprintf(fout, "\n");
}
void myRead(){
    if(fout != NULL){
        fclose(fout);
        fout = NULL;
    }
    if(fin == NULL)
            fin = fopen("file.txt","r");
    for(int i=0;i<20;i++){
        fscanf(fin , "%f", &angle[i]);
    }
    glutPostRedisplay(); ///重劃畫面
}
void keyboard(unsigned char key,int x, int y){
    if(key=='r')myRead();
    if(key=='0')angleID=0;
    if(key=='1')angleID=1;
    if(key=='2')angleID=2;
    if(key=='3')angleID=3;
}
void mouse(int button, int state, int x,int y){
    oldX=x;
}
void motion(int x, int y){
    angle[angleID]+=(x-oldX);
    myWrite();
    oldX=x;
    glutPostRedisplay();///請glut重畫畫面
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();///右半
        glTranslatef(0.3,0.4,0);///(3)把手臂掛回身體原位T
        glRotatef(angle[0],0,0,1);///(2)向Z軸旋轉R
        glTranslatef(-0.3,-0.4,0);///(1)把手臂的旋轉中心，放世界中心(0,0)T
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();///手軸
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半
        glTranslatef(-0.3,0.4,0);///(3)把手臂掛回身體原位T
        glRotatef(angle[2],0,0,1);///(2)向Z軸旋轉R
        glTranslatef(0.3,-0.4,0);///(1)把手臂的旋轉中心，放世界中心(0,0)T
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();///手軸
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(0.7,-0.4,0);
            glColor3f(0,1,0);
            glRectf(-0.7,0.5,-1.0,0.3);
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

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
