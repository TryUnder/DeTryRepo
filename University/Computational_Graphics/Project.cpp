#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include "biblioteka.h"
using namespace std;

static int slices = 100;
static int stacks = 100;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_diffuse[]  = { 0.5f, 0.5f, 0.5f, 0.5f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.0f, 0.0f, 0.0f, 0.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


float zmienna = 0.8f;
GLfloat fPozycja_swiatla[4] = {15.0f, 15.0f, 15.0f, 45.0f};
GLfloat fSlabe_swiatlo[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat fMocne_swiatlo[] = {zmienna, zmienna, zmienna, zmienna};

GLfloat fPozycja_swiatla_2[4] = {50.0f, 50.0f, 45.0f, 0.5f};
GLfloat fSlabe_swiatlo_2[] = {0.325f, 0.325f, 0.325f, 0.5f};
GLfloat fMocne_swiatlo_2[] = {0.5f, 0.5f, 0.5f, 0.5f};

GLfloat fPozycja_reflektora[4] = {0.0f, 10.0f, -2.5f, 1.0f};
GLfloat fKierunek_reflektora[4] = {0.0f, -2.0f, 0.0f, 1.0f};

GLfloat ambient_materials[] = {0.329412, 0.223529, 0.027451, 1.0};
GLfloat diffuse_materials[] = {0.780392, 0.568627, 0.113725, 1.0};
GLfloat specular_materials[] = {0.992157, 0.941176, 0.807843, 1.0};
GLfloat shininess_materials = 27.8974;

double gx=-12, gy=5, gz=-18;

GLfloat PI = 3.14;
GLfloat alfa = -PI / 2;
GLfloat skok_point = 300.0f; ///odleglosc punktu obserwowania
GLfloat skok_eye = 10.0f; ///do pozycji oka
GLfloat eyex = 0; ///wspolrzedne pozycji oka
GLfloat eyey = 0;
GLfloat eyez = -1;
GLfloat pointx = skok_point * cos (alfa); ///wspolrzedne punktu, w ktory
GLfloat pointy = 0.0;
GLfloat pointz = skok_point * sin (alfa);

enum
{
    EXIT,
    FULL_WINDOW,
    ASPECT_1_1,
    ORTO,
    FRUST,
    PERSP
};

GLint skala=FULL_WINDOW;
GLint rzut=ORTO;
GLdouble fovy = 90;

GLdouble aspect = 1;
GLfloat zakres = 10.0f;
GLfloat blisko = 1.0f;
GLfloat daleko = 10.0f;

#define LICZBA_OB_TEXTUR 4
GLuint obiektyTextur [LICZBA_OB_TEXTUR];
char *plikiTextur[] = {
                "C:/Users/Hubert/Desktop/Projekt_Grafika/Projekt_Grafika/Ocean.tga",
                "C:/Users/Hubert/Desktop/Projekt_Grafika/Projekt_Grafika/Wood.tga",
                "C:/Users/Hubert/Desktop/Projekt_Grafika/Projekt_Grafika/Zima.tga",
                "C:/Users/Hubert/Desktop/Projekt_Grafika/Projekt_Grafika/Ziemia.tga"};

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    if (rzut==ORTO)
    {
        if (skala==ASPECT_1_1)
        {
            if (width < height && width > 0)
                glOrtho (-zakres,zakres,-zakres*height/width,zakres*height/width,-zakres,zakres);
            else if (width >= height && height > 0)
                glOrtho (-zakres*width/height,zakres*width/height,-zakres,zakres,-zakres,zakres);
        }
        else
            glOrtho (-zakres,zakres,-zakres,zakres,-zakres,zakres);
    }

    if (rzut==FRUST)
    {
        if (skala==ASPECT_1_1)
        {
            if (width < height && width > 0)
                glFrustum (-zakres,zakres,-zakres*height/width,zakres*height/width,blisko,daleko);
            else if (width >= height && height > 0)
                glFrustum (-zakres*width/height,zakres*width/height,-zakres,zakres,blisko,daleko);
        }
        else
            glFrustum (-zakres,zakres,-zakres,zakres,blisko,daleko);
    }

    if (rzut==PERSP)
    {
        if (height > 0)
            aspect = width/(GLdouble)height;
        gluPerspective (fovy,aspect,blisko,daleko);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    glLoadIdentity();
    gluLookAt (eyex, eyey, eyez, pointx, pointy, pointz, 0.0, 1.0, 0.0);
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*40.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,1,1);

    glPushMatrix();
        glTranslated(0,0,-1); // -25
        //glRotated(60,1,0,0);
        glRotated(a,0,0.8,0); // ROTACJA
        glTranslated(5,0,10); // PRZESUNIECIE

        glBindTexture(GL_TEXTURE_2D, obiektyTextur[1]);

        glBegin(GL_QUADS); // przednia œciana - 1
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1.0 ,0);
            glVertex3f(-4, 3, 0);
            glTexCoord2d(0, 0);
            glVertex3f(-4, 2, 0);
            glTexCoord2d(0, 1.0);
            glVertex3f(4, 2, 0);
            glTexCoord2d(1.0 ,1.0);
            glVertex3f(4, 3, 0);
        glEnd();

        glBegin(GL_QUADS); // przednia œciana - 2
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-5, 3, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-5, -3, 0);
            glTexCoord2d(0,1);
            glVertex3f(-4, -3, 0);
            glTexCoord2d(1,1);
            glVertex3f(-4, 3, 0);
        glEnd();

        glBegin(GL_QUADS); // przednia œciana - 3
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(4, 3, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(4, -3, 0);
            glTexCoord2d(0,1);
            glVertex3f(5, -3, 0);
            glTexCoord2d(1,1);
            glVertex3f(5, 3, 0);
        glEnd();

        glBegin(GL_QUADS); // przednia œciana - 6
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-2, 2, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-2, 0, 0);
            glTexCoord2d(0,1);
            glVertex3f(2, 0, 0);
            glTexCoord2d(1,1);
            glVertex3f(2, 2, 0);
        glEnd();

        glBegin(GL_QUADS); // przednia œciana - 4
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-4, 0, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-4, -3, 0);
            glTexCoord2d(0,1);
            glVertex3f(-1, -3, 0);
            glTexCoord2d(1,1);
            glVertex3f(-1, 0, 0);
        glEnd();

        glBegin(GL_QUADS); // przednia œciana - 5
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(1, 0, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(1, -3, 0);
            glTexCoord2d(0,1);
            glVertex3f(4, -3, 0);
            glTexCoord2d(1,1);
            glVertex3f(4, 0, 0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, obiektyTextur[3]);
        glBegin(GL_QUADS); // przednia œciana - drzwi
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-1, 0, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-1, -3, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(1, -3, 0);
            glTexCoord2d(1 ,1);
            glVertex3f(1, 0, 0);
        glEnd();

    glBindTexture(GL_TEXTURE_2D, obiektyTextur[2]);
        glBegin(GL_QUADS); // przednia sciana - lewe okno - wglebienie 1 (lewy bok)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-4, 2, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-4, 0, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(-4, 0, -1);
            glTexCoord2d(1 ,1);
            glVertex3f(-4, 2, -1);
        glEnd();

        glBegin(GL_QUADS); // przednia sciana - lewe okno - wglebienie 2 (dolne bok)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-4, 0, -1);
            glTexCoord2d(0 ,0);
            glVertex3f(-4, 0, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(-2, 0, 0);
            glTexCoord2d(1 ,1);
            glVertex3f(-2, 0, -1);
        glEnd();

        glBegin(GL_QUADS); // przednia sciana - lewe okno - wglebienie 3 (prawy bok)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-2, 2, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-2, 0, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(-2, 0, -1);
            glTexCoord2d(1 ,1);
            glVertex3f(-2, 2, -1);
        glEnd();

        glBegin(GL_QUADS); // przednia sciana - lewe okno - wglebienie 4 (gorny bok)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-4, 2, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-4, 2, -1);
            glTexCoord2d(0 ,1);
            glVertex3f(-2, 2, -1);
            glTexCoord2d(1 ,1);
            glVertex3f(-2, 2, 0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, obiektyTextur[0]);
        glBegin(GL_QUADS); // okno lewe
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-4, 2, -1);
            glTexCoord2d(0 ,0);
            glVertex3f(-4, 0, -1);
            glTexCoord2d(0 ,1);
            glVertex3f(-2, 0, -1);
            glTexCoord2d(1 ,1);
            glVertex3f(-2, 2, -1);
        glEnd();

 ///////
         glBindTexture(GL_TEXTURE_2D, obiektyTextur[2]);
         glBegin(GL_QUADS); // przednia sciana - prawe okno - wglebienie 1 (lewy bok)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(2, 2, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(2, 0, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(2, 0, -1);
            glTexCoord2d(1 ,1);
            glVertex3f(2, 2, -1);
        glEnd();

        glBegin(GL_QUADS); // przednia sciana - prawe okno - wglebienie 2 (dolne bok)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(2, 0, -1);
            glTexCoord2d(0 ,0);
            glVertex3f(2, 0, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(4, 0, 0);
            glTexCoord2d(1 ,1);
            glVertex3f(4, 0, -1);
        glEnd();

        glBegin(GL_QUADS); // przednia sciana - prawe okno - wglebienie 3 (prawy bok)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(4, 2, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(4, 0, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(4, 0, -1);
            glTexCoord2d(1 ,1);
            glVertex3f(4, 2, -1);
        glEnd();

        glBegin(GL_QUADS); // przednia sciana - prawe okno - wglebienie 4 (gorny bok)
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(2, 2, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(2, 2, -1);
            glTexCoord2d(0 ,1);
            glVertex3f(4, 2, -1);
            glTexCoord2d(1 ,1);
            glVertex3f(4, 2, 0);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, obiektyTextur[0]);

        glBegin(GL_QUADS); // prawe okno
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(2, 2, -1);
            glTexCoord2d(0 ,0);
            glVertex3f(2, 0, -1);
            glTexCoord2d(0 ,1);
            glVertex3f(4, 0, -1);
            glTexCoord2d(1 ,1);
            glVertex3f(4, 2, -1);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, obiektyTextur[1]);
        glBegin(GL_QUADS); // prawy bok
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(5, 3, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(5, -3, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(5, -3, -6);
            glTexCoord2d(1 ,1);
            glVertex3f(5, 3, -6);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, obiektyTextur[1]);
        glBegin(GL_QUADS); // lewy bok
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-5, 3, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-5, -3, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(-5, -3, -6);
            glTexCoord2d(1 ,1);
            glVertex3f(-5, 3, -6);
        glEnd();

       glBegin(GL_QUADS); // spód
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-5, -3, 0);
            glTexCoord2d(0 ,0);
            glVertex3f(-5, -3, -6);
            glTexCoord2d(0 ,1);
            glVertex3f(5, -3, -6);
            glTexCoord2d(1 ,1);
            glVertex3f(5, -3, 0);
       glEnd();

       glBegin(GL_QUADS); // tyl
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(-5, 3, -6);
            glTexCoord2d(0 ,0);
            glVertex3f(-5, -3, -6);
            glTexCoord2d(0 ,1);
            glVertex3f(5, -3, -6);
            glTexCoord2d(1 ,1);
            glVertex3f(5, 3, -6);
       glEnd();

       glBindTexture(GL_TEXTURE_2D, obiektyTextur[2]);
       glNormal3f(0.0f, 1.0f, 0.0f);
       glBegin(GL_TRIANGLES); // dach bok nr 1
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(0, 6, -3);
            glTexCoord2d(0 ,0);
            glVertex3f(-5, 3, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(5, 3, 0);
       glEnd();

       glBegin(GL_TRIANGLES); //dach bok nr 2
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(0, 6, -3);
            glTexCoord2d(0 ,0);
            glVertex3f(5, 3, 0);
            glTexCoord2d(0 ,1);
            glVertex3f(5, 3, -6);
       glEnd();

       glBegin(GL_TRIANGLES); //dach bok nr 3
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(0, 6, -3);
            glTexCoord2d(0 ,0);
            glVertex3f(5, 3, -6);
            glTexCoord2d(0 ,1);
            glVertex3f(-5, 3, -6);
       glEnd();

       glBegin(GL_TRIANGLES); //dach bok nr 4
            glNormal3f(0.0f, 1.0f, 0.0f);
            glTexCoord2d(1 ,0);
            glVertex3f(0, 6, -3);
            glTexCoord2d(0 ,0);
            glVertex3f(-5, 3, -6);
            glTexCoord2d(0 ,1);
            glVertex3f(-5, 3, 0);
       glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void Menu (int value)
{
switch (value)
    {
        case EXIT:
            exit (0);
        case FULL_WINDOW:
            skala=FULL_WINDOW;
            resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
            break;
        case ASPECT_1_1:
            skala=ASPECT_1_1;
            resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
            break;
        case ORTO:
            rzut=ORTO;
            resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
            break;
        case FRUST:
            rzut=FRUST;
            resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
            break;
        case PERSP:
            rzut=PERSP;
            resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
            break;
    }
}

void klawisze_specjalne(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        alfa -= PI / 32;
        pointx = skok_point * cos (alfa) + eyex;
        pointz = skok_point * sin (alfa) + eyez;
        break;
    case GLUT_KEY_RIGHT:
        alfa += PI / 32;
        pointx = skok_point * cos (alfa) + eyex;
        pointz = skok_point * sin (alfa) + eyez;
        break;
    case GLUT_KEY_UP:
        skok_eye += 10.0f;
        eyex = skok_eye * cos (alfa) + eyex;
        eyez = skok_eye * sin (alfa) + eyez;
        pointx = skok_point * cos (alfa) + eyex;
        pointz = skok_point * sin (alfa) + eyez;
        skok_eye = 0.0f;
        break;
    case GLUT_KEY_DOWN:
        skok_eye -= 10.0f;
        eyex = skok_eye * cos (alfa) + eyex;
        eyez = skok_eye * sin (alfa) + eyez;
        pointx = skok_point * cos (alfa) + eyex;
        pointz = skok_point * sin (alfa) + eyez;
        skok_eye = 0.0f;
        break;
    }
    resize(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

static void key(unsigned char key, int x, int y)
{
    static int back;
    GLfloat colors[][3] = { { 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f, 0.0f } }; //BLACK/WHITE BACKGROUND
    switch (key)
    {
        case 27 :
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;

         //case 'e':
            //glEnable(GL_LIGHTING); // WŁĄCZENIE OŚWIETLENIA
            //break;

         //case 'd':
            //glDisable(GL_LIGHTING); // WYŁĄCZENIE OŚWIETLENIA
            //break;

        case '1':
            glEnable(GL_LIGHT0); // WŁĄCZENIE ŚWIATŁA OGÓLNEGO
            break;

        case '2':
            glDisable(GL_LIGHT0); // WYŁĄCZENIE ŚWIATŁA OGÓLNEGO

        case '3':
            glEnable(GL_LIGHT1); // WŁĄCZENIE ŚWIATŁA KIERUNKOWEGO
            break;

        case '4':
            glDisable(GL_LIGHT1); // WYŁĄCZENIE ŚWIATŁA KIERUNKOWEGO
            break;

        case '5':
            glEnable(GL_COLOR_MATERIAL); // WŁĄCZENIE WŁAŚCIWOŚCI MATERIAŁU
            break;

        case '6':
            glDisable(GL_COLOR_MATERIAL);// WYŁĄCZENIE WŁAŚCIWOŚCI MATERIAŁU
            break;

        case '0': // STEROWANIE KOLOREM TŁA - CZARNO/BIAŁE
            back ^= 1;
            glClearColor(colors[back][0], colors[back][1], colors[back][2], 1.0f);
        break;

        case 'j':
            alfa -= PI / 32;
            pointx = skok_point * cos (alfa) + eyex;
            pointz = skok_point * sin (alfa) + eyez;
            break;

        case 'k':
            alfa += PI / 32;
            pointx = skok_point * cos (alfa) + eyex;
            pointz = skok_point * sin (alfa) + eyez;
            break;

        case 'n':
            skok_eye += 10.0f;
            eyex = skok_eye * cos (alfa) + eyex;
            eyez = skok_eye * sin (alfa) + eyez;
            pointx = skok_point * cos (alfa) + eyex;
            pointz = skok_point * sin (alfa) + eyez;
            skok_eye = 0.0f;
            break;

        case 'm':
            skok_eye -= 10.0f;
            eyex = skok_eye * cos (alfa) + eyex;
            eyez = skok_eye * sin (alfa) + eyez;
            pointx = skok_point * cos (alfa) + eyex;
            pointz = skok_point * sin (alfa) + eyez;
            skok_eye = 0.0f;
            break;

        case 'v':
            for(int i=0; i<4; ++i){
                fMocne_swiatlo[i] -= 0.05f;
                fSlabe_swiatlo[i] -= 0.05f;
            }
                glLightfv(GL_LIGHT0, GL_AMBIENT, fSlabe_swiatlo);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, fMocne_swiatlo);
                glLightfv(GL_LIGHT0, GL_SPECULAR, fMocne_swiatlo);
                glLightfv(GL_LIGHT1, GL_AMBIENT, fSlabe_swiatlo);
                glLightfv(GL_LIGHT1, GL_DIFFUSE, fMocne_swiatlo);
                glLightfv(GL_LIGHT1, GL_SPECULAR, fMocne_swiatlo);
            break;

        case 'c':
            for(int i=0; i<4; ++i){
                fMocne_swiatlo[i] += 0.05f;
                fSlabe_swiatlo[i] += 0.05f;
            }
                glLightfv(GL_LIGHT0, GL_AMBIENT, fSlabe_swiatlo);
                glLightfv(GL_LIGHT0, GL_DIFFUSE, fMocne_swiatlo);
                glLightfv(GL_LIGHT0, GL_SPECULAR, fMocne_swiatlo);
                glLightfv(GL_LIGHT1, GL_AMBIENT, fSlabe_swiatlo);
                glLightfv(GL_LIGHT1, GL_DIFFUSE, fMocne_swiatlo);
                glLightfv(GL_LIGHT1, GL_SPECULAR, fMocne_swiatlo);
            break;

        case 'f':
                fPozycja_reflektora[1] += 0.1f;
            glLightfv(GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
            break;

        case 'd':
                fPozycja_reflektora[1] -= 0.1f;
            glLightfv(GL_LIGHT1, GL_POSITION, fPozycja_reflektora);
            break;
    }

}

static void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Projekt Grafika");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glutCreateMenu (Menu); // utworzenie menu podręcznego dodadnie pozycji do menu podręcznego
    glutSpecialFunc(klawisze_specjalne);
    glutAddMenuEntry ("Rodzaj skalowania - całe okno", FULL_WINDOW);
    glutAddMenuEntry ("Rodzaj skalowania - skala 1:1", ASPECT_1_1);
    glutAddMenuEntry ("Rzutowanie ortogonalne", ORTO);
    glutAddMenuEntry ("Rzutowanie frustum", FRUST);
    glutAddMenuEntry ("Rzutowanie perspective", PERSP);
    glutAddMenuEntry ("Wyjście",EXIT);
    glutAttachMenu (GLUT_RIGHT_BUTTON); // określenie przycisku myszki obsługującej menu podręczne

    glEnable(GL_TEXTURE_2D); // w³¹czenie teksturowania
    glGenTextures(LICZBA_OB_TEXTUR, obiektyTextur); // wygenerowanie obiektów tekstur
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); // ustalenie trybu œrodowiska !!!
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    for (int i = 0; i < LICZBA_OB_TEXTUR; i++)
    {
        GLubyte *pBytes;
        GLint iWidth, iHeight, iComponents;
        GLenum eFormat;
        glBindTexture(GL_TEXTURE_2D, obiektyTextur[i]); // dowi¹zanie obiektów tekstur
        pBytes = glploadtga(plikiTextur[i], &iWidth, &iHeight, &iComponents, &eFormat); // Za³adowanie tekstur
        //utworzenie mipmap
        gluBuild2DMipmaps(GL_TEXTURE_2D, iComponents, iWidth, iHeight, eFormat, GL_UNSIGNED_BYTE, pBytes);
        free(pBytes); // zwolnienie pamiêci
    }
    glEnable(GL_LIGHTING);
    glClearColor(1,1,1,1);
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_NORMALIZE);
    //glNormal3f(0.5f, 0.25f, 25.0f);

            // swiatlo ogolne
            glLightfv(GL_LIGHT0, GL_AMBIENT, fSlabe_swiatlo);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, fMocne_swiatlo);
            glLightfv(GL_LIGHT0, GL_SPECULAR, fMocne_swiatlo);
            glLightfv(GL_LIGHT0, GL_POSITION, fPozycja_swiatla);

            // swiatlo kierunkowe
            glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0f);
            glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0f);

            glLightfv(GL_LIGHT1, GL_AMBIENT, fSlabe_swiatlo_2);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, fMocne_swiatlo_2);
            glLightfv(GL_LIGHT1, GL_SPECULAR, fMocne_swiatlo_2);
            glLightfv(GL_LIGHT1, GL_POSITION, fPozycja_reflektora); // REFLEKTOR - ŚWIATŁO KIERUNKOWE
            glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, fKierunek_reflektora);

            //glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_materials);
            //glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_materials);
            //glMaterialfv(GL_FRONT, GL_SPECULAR, specular_materials);
            //glMateriali(GL_FRONT, GL_SHININESS, shininess_materials);
    glutMainLoop();
    glDeleteTextures (LICZBA_OB_TEXTUR, obiektyTextur);
    return EXIT_SUCCESS;
}
