    #include <GL/glut.h>
    float angle=0, oldx=0;
    void display(){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPushMatrix();///�ƥ��x�}
            glRotatef(angle, 0,0,1);
            glutSolidTeapot(0.3);
        glPopMatrix();///�٭�x�}
        glutSwapBuffers();

    }
    void motion(int x, int y){///�쪺�ɭԭn�]
        angle+=(x-oldx);
        oldx=x;///�쪺�]���y�ЦA�]
        display();///���e�e��

    }
    void mouse(int button, int state, int x, int y){///���B��n�]
        oldx=x;///�w��

    }
    int main(int argc, char** argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
        glutCreateWindow("Week04 Rotate");

        glutDisplayFunc(display);
        glutMotionFunc(motion);///mouse motion��
        glutMouseFunc(mouse);///���U�B��}
        glutMainLoop();


    }
