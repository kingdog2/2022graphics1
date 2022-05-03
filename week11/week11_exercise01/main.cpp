#include <opencv/highgui.h>
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>///�o�O�q���̭n�]�winclude
#include "glm.h"///�o�O�ɤJ�M�ץؿ��̪�
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
    if(pmodel == NULL){///�p�G�O�ū��СA��ܼҫ��S���ǳƦn
        pmodel=glmReadOBJ("data/Gundam.obj");///�NŪ�ҫ�
        glmUnitize(pmodel);///���⦨Unit���j�p -1........1
        glmFacetNormals(pmodel);///���s�p�⭱���k�V�q
        glmVertexNormals(pmodel,90);///���s�p�⪺���I���k�V�q
    }

    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel, GLM_TEXTURE);///���ҫ���,�e��,�n�O�o�e�K��
    glPushMatrix();

    glutSwapBuffers();
    angle+=0.00001;
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("��11�g���{���@!");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);///3D

    glutMainLoop();
}
