#include <GL/glut.h>
#include <stdio.h>

GLint LARGURA = 600,
ALTURA = 600;

void initGlut(int* argc, char** argv) {
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(LARGURA, ALTURA);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Casa");
}

void inicializacao(GLvoid) {
    
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    
    gluOrtho2D(0, LARGURA, ALTURA, 0);
}

void desenharCasa(GLvoid) {
    glLineWidth(3.0);
//---------------------------- FRENTE DA CASA -----------------------------
    glBegin(GL_QUADS);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2i(100, 560);
    glVertex2i(500, 560);
    glVertex2i(100, 250);
    glVertex2i(500, 250);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.9f, 0.9f, 0.9f);
    glVertex2i(290, 400);
    glVertex2i(500, 560);
    glVertex2i(500, 250);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(100, 250);
    glVertex2i(100, 560);
    glVertex2i(500, 560);
    glVertex2i(500, 250);
    glEnd();
//------------------------------------------------------------------------

//----------------------------- TELHADO ----------------------------------
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.3f, 0.0f);
    glVertex2i(40, 250);
    glVertex2i(300, 90);
    glVertex2i(560, 250);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(40, 250);
    glVertex2i(300, 90);
    glVertex2i(560, 250);
    glVertex2i(40, 250);
    glEnd();
//------------------------------------------------------------------------

//---------------------------- PORTA -------------------------------------
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.0f, 0.0f);
    glVertex2i(210, 560);
    glVertex2i(290, 560);
    glVertex2i(210, 320);
    glVertex2i(290, 320);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.2f, 0.0f, 0.0f);    
    glVertex2i(240, 440);
    glVertex2i(290, 320);
    glVertex2i(290, 560);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(210, 560);
    glVertex2i(290, 560);
    glVertex2i(290, 320);
    glVertex2i(210, 320);
    glVertex2i(210, 560);
    glEnd();
//------------------------------------------------------------------------

//---------------------------- JANELA ------------------------------------
    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex2i(360, 405);
    glVertex2i(450, 405);
    glVertex2i(360, 315);
    glVertex2i(450, 315);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex2i(395, 360);
    glVertex2i(450, 405);
    glVertex2i(450, 315);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(360, 360);
    glVertex2i(450, 360);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(405, 405);
    glVertex2i(405, 315);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(360, 405);
    glVertex2i(450, 405);
    glVertex2i(450, 315);
    glVertex2i(360, 315);
    glVertex2i(360, 405);
    glEnd();
//-------------------------------------------------------------------------
}

void desenha(GLvoid) {
    glClear(GL_COLOR_BUFFER_BIT);
    desenharCasa();

    glFlush();
}

void keyboardFunc(unsigned char key, GLint x, GLint y) {

    int Espaco = { 32 };
    int mod = glutGetModifiers();

    //Muda a cor do fundo para preto se pressionar CTRL + Espaço.
    if ((mod & GLUT_ACTIVE_CTRL) && (key == Espaco)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }
    //Muda a cor do fundo para branco caso outra tecla que não seja especial seja pressionada.
    else {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }
    glutPostRedisplay();
}

void keyboardfuncSpec(GLint key, GLint x, GLint y) {

    int mod = glutGetModifiers();

    //Faz com que o CTRL só possa ser usado junto com o espaço para mudar a cor do fundo para preto.
    if (mod & GLUT_ACTIVE_CTRL) {
        glutPostRedisplay();
    } else { 
    //Muda a cor do fundo para cinza caso alguma tecla especial seja pressionada.
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    }

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    initGlut(&argc, argv);
    inicializacao();
    glutKeyboardFunc(keyboardFunc);
    glutSpecialFunc(keyboardfuncSpec);
    glutDisplayFunc(desenha);
    glutMainLoop();
    return 0;
}
