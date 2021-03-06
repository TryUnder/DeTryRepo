#ifdef __APPLE_
#include <GLUT/gl.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int w = 1400;
const int k = 2000;
const int ps = 1;

int R_b[w][k];
int G_b[w][k];
int B_b[w][k];

int R_n[w][k];
int G_n[w][k];
int B_n[w][k];

int Maska[3][3] = { -1, 1, 1,
		    -1, -1, 1,
		    -1, 1, 1 };

vector<int> box;
vector<int>::iterator iter;

int rows,columns;
static int slices = 16;
static int stacks = 16;

static void resize(int width, int height){
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, k, 0, w, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display(void){
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t * 90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
	glTranslated(0,0,-6);
	glBegin(GL_POINTS);
	for(int i=0; i<rows; ++i){
	    for(int j=0; j<columns; ++j){
		glColor3f(
		R_n[i][j]/255.,
		G_n[i][j]/255.,
		B_n[i][j]/255.);
		glVertex3f(j,i,0);
	    }
	}
	glEnd();
	glPopMatrix();
    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y){
	glutPostRedisplay();
	switch(key){

	case 'r':
	    for(int i=0; i<rows; ++i){
		for(int j=0; j<columns; ++j){
		    R_n[i][j] = R_b[i][j];
		    G_n[i][j] = 0.0f;
		    B_n[i][j] = 0.0f;
		}
	    }
	break;

	case 'b':
	    for(int i=0; i<rows; ++i){
		for(int j=0; j<columns; ++j){
		    R_n[i][j] = R_b[i][j];
		    G_n[i][j] = G_b[i][j];
		    B_n[i][j] = B_b[i][j];
		}
	    }
	break;

	case '1':
	    for(int i=0; i<rows; ++i){
		for(int j=0; j<columns; ++j){
		    if((R_b[i][j] >= 127.0 && R_b[i][j] <= 255.0) ||
		       (G_b[i][j] >= 127.0 && G_b[i][j] <= 255.0) ||
		       (B_b[i][j] >= 127.0 && B_b[i][j] <= 255.0))
			{R_n[i][j] = 0; G_n[i][j] = 0; B_n[i][j] = 0;}
			else { R_n[i][j] = 255.0; G_n[i][j] = 255.0; B_n[i][j] = 255.0; }
		}
	    }
	break;
	case '2':
	    for(int i=0; i<rows; ++i){
		for(int j=0; j<columns; ++j){
		    R_n[i][j] = 255.0 * pow((R_b[i][j]/255.0),1.0/1.5);
		    G_n[i][j] = 255.0 * pow((G_b[i][j]/255.0),1.0/1.5);
		    B_n[i][j] = 255.0 * pow((B_b[i][j]/255.0),1.0/1.5);
		}
	    }
	break;
	case '3':
	    for(int i=0; i<rows; ++i){
		for(int j=0; j<columns; ++j){
		    R_n[i][j] = (R_b[i][j]+G_b[i][j]+B_b[i][j])/3;
		    G_n[i][j] = (R_b[i][j]+G_b[i][j]+B_b[i][j])/3;
		    B_b[i][j] = (R_b[i][j]+G_b[i][j]+B_b[i][j])/3;
		}
	    }
	break;
	case '5':
	    for(int i=0; i<rows; ++i){
		for(int j=0; j<columns; ++j){
		    R_n[i][j]= (Maska[0][0]*R_b[i-1][j-1]+
                           Maska[0][1]*R_b[i-1][j]+
                           Maska[0][2]*R_b[i-1][j+1]+
                           Maska[1][0]*R_b[i][j-1]+
                           Maska[1][1]*R_b[i][j]+
                           Maska[1][2]*R_b[i][j+1]+
                           Maska[2][0]*R_b[i+1][j-1]+
                           Maska[2][1]*R_b[i+1][j]+
                           Maska[2][2]*R_b[i+1][j+1])/
                           (Maska[0][0]+Maska[0][1]+Maska[0][2]+
                            Maska[1][0]+Maska[1][1]+Maska[1][2]+
                            Maska[2][0]+Maska[2][1]+Maska[2][2]);

		    G_n[i][j]= (Maska[0][0]*G_b[i-1][j-1]+
                           Maska[0][1]*G_b[i-1][j]+
                           Maska[0][2]*G_b[i-1][j+1]+
                           Maska[1][0]*G_b[i][j-1]+
                           Maska[1][1]*G_b[i][j]+
                           Maska[1][2]*G_b[i][j+1]+
                           Maska[2][0]*G_b[i+1][j-1]+
                           Maska[2][1]*G_b[i+1][j]+
                           Maska[2][2]*G_b[i+1][j+1])/
                           (Maska[0][0]+Maska[0][1]+Maska[0][2]+
                            Maska[1][0]+Maska[1][1]+Maska[1][2]+
                            Maska[2][0]+Maska[2][1]+Maska[2][2]);

		    B_n[i][j]= (Maska[0][0]*B_b[i-1][j-1]+
                           Maska[0][1]*B_b[i-1][j]+
                           Maska[0][2]*B_b[i-1][j+1]+
                           Maska[1][0]*B_b[i][j-1]+
                           Maska[1][1]*B_b[i][j]+
                           Maska[1][2]*B_b[i][j+1]+
                           Maska[2][0]*B_b[i+1][j-1]+
                           Maska[2][1]*B_b[i+1][j]+
                           Maska[2][2]*B_b[i+1][j+1])/
                           (Maska[0][0]+Maska[0][1]+Maska[0][2]+
                            Maska[1][0]+Maska[1][1]+Maska[1][2]+
                            Maska[2][0]+Maska[2][1]+Maska[2][2]);

		}
	    }
	break;
	case '6':
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j){
                box.push_back(R_b[i-1][j-1]);
                box.push_back(R_b[i-1][j]);
                box.push_back(R_b[i-1][j+1]);
                box.push_back(R_b[i][j-1]);
                box.push_back(R_b[i][j]);
                box.push_back(R_b[i][j+1]);
                box.push_back(R_b[i+1][j-1]);
                box.push_back(R_b[i+1][j]);
                box.push_back(R_b[i+1][j+1]);
                iter = max_element(box.begin(), box.end());
                R_n[i][j] = box.at(distance(box.begin(), iter));
		box.clear();

		box.push_back(G_b[i-1][j-1]);
                box.push_back(G_b[i-1][j]);
                box.push_back(G_b[i-1][j+1]);
                box.push_back(G_b[i][j-1]);
                box.push_back(G_b[i][j]);
                box.push_back(G_b[i][j+1]);
                box.push_back(G_b[i+1][j-1]);
                box.push_back(G_b[i+1][j]);
                box.push_back(G_b[i+1][j+1]);
                iter = max_element(box.begin(), box.end());
                G_n[i][j] = box.at(distance(box.begin(), iter));
		box.clear();

		box.push_back(B_b[i-1][j-1]);
                box.push_back(B_b[i-1][j]);
                box.push_back(B_b[i-1][j+1]);
                box.push_back(B_b[i][j-1]);
                box.push_back(B_b[i][j]);
                box.push_back(B_b[i][j+1]);
                box.push_back(B_b[i+1][j-1]);
                box.push_back(B_b[i+1][j]);
                box.push_back(B_b[i+1][j+1]);
                iter = max_element(box.begin(), box.end());
                B_n[i][j] = box.at(distance(box.begin(), iter));
		box.clear();
    
    }
}
break;
    case '7':
        for(int i=0; i<rows; ++i){
            for(int j=0; j<columns; ++j){
                box.push_back(R_b[i-1][j-1]);
                box.push_back(R_b[i-1][j]);
                box.push_back(R_b[i-1][j+1]);
                box.push_back(R_b[i][j-1]);
                box.push_back(R_b[i][j]);
                box.push_back(R_b[i][j+1]);
                box.push_back(R_b[i+1][j-1]);
                box.push_back(R_b[i+1][j]);
                box.push_back(R_b[i+1][j+1]);
                iter = min_element(box.begin(), box.end());
                R_n[i][j] = box.at(distance(box.begin(), iter));
		box.clear();

		box.push_back(G_b[i-1][j-1]);
                box.push_back(G_b[i-1][j]);
                box.push_back(G_b[i-1][j+1]);
                box.push_back(G_b[i][j-1]);
                box.push_back(G_b[i][j]);
                box.push_back(G_b[i][j+1]);
                box.push_back(G_b[i+1][j-1]);
                box.push_back(G_b[i+1][j]);
                box.push_back(G_b[i+1][j+1]);
                iter = min_element(box.begin(), box.end());
                G_n[i][j] = box.at(distance(box.begin(), iter));
		box.clear();

		box.push_back(B_b[i-1][j-1]);
                box.push_back(B_b[i-1][j]);
                box.push_back(B_b[i-1][j+1]);
                box.push_back(B_b[i][j-1]);
                box.push_back(B_b[i][j]);
                box.push_back(B_b[i][j+1]);
                box.push_back(B_b[i+1][j-1]);
                box.push_back(B_b[i+1][j]);
                box.push_back(B_b[i+1][j+1]);
                iter = min_element(box.begin(), box.end());
                B_n[i][j] = box.at(distance(box.begin(), iter));
		box.clear();
    
    }
}
break;
}}
static void idle(void){
    glutPostRedisplay();
}

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 0.7f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char* argv[]){
    ifstream file("D:/P.R.I.V/Uczelnia/Semestr_IV/Grafika_Komputerowa_I_Wizualizacja/Sprawozdanie_I_Filtry/zd5/zd5.txt");
    file >> rows >> columns;
    for(int i=0; i<rows; ++i){
	for(int j=0; j<columns; ++j){
	    file >> R_b[i][j];
	    file >> G_b[i][j];
	    file >> B_b[i][j];
	}
    }
    file.close();

    for(int i=0; i<rows; ++i){
	for(int j=0; j<columns; ++j){
	    R_n[i][j] = R_b[i][j];
	    G_n[i][j] = G_b[i][j];
	    B_n[i][j] = B_b[i][j];
	}
    }

    glutInit(&argc, argv);
    glutInitWindowSize(1920,1080);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
