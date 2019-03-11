//Semestre 2019 - 2
 /*
 García Callejas Ricardo
 Grupo 2
 Visual Studio 2017
 Reporte 5
 Manual
  Usamos rotate para poder realizar el correcto movimiento a las articulaciones del brazo y demas partes de esta extremidad
 cuidando siempre los ejes sobre los que se realizara, con o y p movemos los hombros con i y u movemos los codos
 con y y t movemos las palmas, con q y e los pulgares y con c y v los demas dedos.
 */

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
float angleHombro = 0.0;
float angleCodo = 0.0;
float anglePalma = 0.0;
float angleDedo = 0.0;
float angleInd = 0.0;




void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(float x,float y, float z)
{
	GLfloat vertice [8][3] = {
				{x/2 ,-y/2, z/2},    //Coordenadas Vértice 0 V0
				{-x/2 ,-y/2, z/2},    //Coordenadas Vértice 1 V1
				{-x/2 ,-y/2, -z/2},    //Coordenadas Vértice 2 V2
				{x/2 ,-y/2, -z/2},    //Coordenadas Vértice 3 V3
				{x/2 ,y/2, z/2},    //Coordenadas Vértice 4 V4
				{x/2 ,y/2, -z/2},    //Coordenadas Vértice 5 V5
				{-x/2 ,y/2, -z/2},    //Coordenadas Vértice 6 V6
				{-x/2 ,y/2, z/2},    //Coordenadas Vértice 7 V7
				};


		glBegin(GL_POLYGON);	//Front
			
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Poner Código Aquí.

	glTranslatef(transX, transY, transZ);
	glRotatef(angleX, 0.0, 1.0, 0.0);
	//cabeza
	glColor3f(1.0, 0.0, 0.0);
	prisma(1, 1, 1);
	//cuello
	glTranslatef(0.0, -0.75, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma(0.5, 0.5, 0.5);
	//torso
	glTranslatef(0.0, -1.25, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	prisma(2.0, 2.0, 1.0);
	glPushMatrix();
	//hombro
	glTranslatef(1.15, 0.75, 0.0);
	glRotatef(angleHombro, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(1.0 / 3.0, 0.5, 1.0);
	prisma(1, 1, 1);
	//brazo
	glScalef(3.0, 2.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.65, 0.0, 0.0);
	glScalef(1.0, 0.5, 1.0);
	prisma(1, 1, 1);
	//codo
	glScalef(1.0, 2.0, 1.0);
	glTranslatef(0.6, 0.0, 0.0);
	glRotatef(angleCodo, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.2, 0.5, 1.0);
	prisma(1, 1, 1);
	//antebrazo
	glScalef(5.0, 2.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glScalef(0.8, 0.5, 0.5);
	prisma(1, 1, 1);
	//muñeca
	glScalef(1.25, 2.0, 1.0);
	glTranslatef(0.45, 0.0, 0.0);
	glRotatef(anglePalma, 0.0, 0.0, 1.0);
	glColor3f(0.5, 0.0, 1.0);
	glScalef(0.1, 0.5, 1.0);
	prisma(1, 1, 1);
	//palma
	glScalef(10, 2.0, 1.0);
	glTranslatef(0.35, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glScalef(0.6, 0.5, 1.0);
	prisma(1, 1, 1);
	//pulgar1
	glScalef(1.66, 2.0, 1.0);
	glTranslatef(-0.2, 0.3, 0.25);
	glColor3f(0.8, 0.8, 0.0);
	glScalef(0.2, 0.1, 0.5);
	prisma(1, 1, 1);
	//pulgar2
	glScalef(5, 10, 2.0);
	glTranslatef(0.0, -0.5, 0.25);
	glRotatef(angleDedo, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.5, -0.25);
	glTranslatef(0.0, 0.1, 0.0);
	glColor3f(0.0, 0.8, 0.8);
	glScalef(0.2, 0.1, 0.5);
	prisma(1, 1, 1);
	//INDICE 
	//Falange 1
	glScalef(5, 10, 2);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.6, -0.2, 0);
	glTranslatef(-0.5, 0.0, 0.1);
	glRotatef(angleInd, 0, 1, 0);
	glTranslatef(0.5, 0.0, -0.1);
	glScalef(0.2, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(5, 10, 1);
	//Falange 2
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.1, 0, 0);
	glScalef(0.09, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(11.11, 10, 1);
	//Falange 3
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.085, 0, 0);
	glScalef(0.08, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(12.5, 10, 1);

	//MEDIO
	//Falange 1
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.195, -0.13, 0);
	glScalef(0.1, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(10, 10, 1);
	//Falange2
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.1, 0, 0);
	glScalef(0.1, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(10, 10, 1);
	//Falange 3
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.1, 0, 0);
	glScalef(0.1, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(10, 10, 1);

	//ANULAR
	//Falange 1
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.20, -0.13, 0);
	glScalef(0.1, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(10, 10, 1);
	//Falange2
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.09, 0, 0);
	glScalef(0.08, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(12.5, 10, 1);
	//Falange 3
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.08, 0, 0);
	glScalef(0.08, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(12.5, 10, 1);

	//MEÑIQUE
	//Falange 1
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.185, -0.13, 0);
	glScalef(0.07, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(14.28, 10, 1);
	//Falange2
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.07, 0, 0);
	glScalef(0.07, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(14.28, 10, 1);
	//Falange 3
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.07, 0, 0);
	glScalef(0.07, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(14.28, 10, 2);
	glPopMatrix();
	glPushMatrix();
	//hombro
	glRotatef(180, 0.0, 1.0, 0.0);
	glTranslatef(1.15, 0.75, 0.0);
	glRotatef(angleHombro, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(1.0 / 3.0, 0.5, 1.0);
	prisma(1, 1, 1);
	//brazo
	glScalef(3.0, 2.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.65, 0.0, 0.0);
	glScalef(1.0, 0.5, 1.0);
	prisma(1, 1, 1);
	//codo
	glScalef(1.0, 2.0, 1.0);
	glTranslatef(0.6, 0.0, 0.0);
	glRotatef(angleCodo, 0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.2, 0.5, 1.0);
	prisma(1, 1, 1);
	//antebrazo
	glScalef(5.0, 2.0, 1.0);
	glTranslatef(0.5, 0.0, 0.0);
	glColor3f(1.0, 0.0, 1.0);
	glScalef(0.8, 0.5, 0.5);
	prisma(1, 1, 1);
	//muñeca
	glScalef(1.25, 2.0, 1.0);
	glTranslatef(0.45, 0.0, 0.0);
	glRotatef(anglePalma, 0.0, 0.0, 1.0);
	glColor3f(0.5, 0.0, 1.0);
	glScalef(0.1, 0.5, 1.0);
	prisma(1, 1, 1);
	//palma
	glScalef(10, 2.0, 1.0);
	glTranslatef(0.35, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.5);
	glScalef(0.6, 0.5, 1.0);
	prisma(1, 1, 1);
	//pulgar1
	glScalef(1.66, 2.0, 1.0);
	glTranslatef(-0.2, 0.3, 0.25);
	glColor3f(0.8, 0.8, 0.0);
	glScalef(0.2, 0.1, 0.5);
	prisma(1, 1, 1);
	//pulgar2
	glScalef(5, 10, 2.0);
	glTranslatef(0.0, -0.5, 0.25);
	glRotatef(angleDedo, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 0.5, -0.25);
	glTranslatef(0.0, 0.1, 0.0);
	glColor3f(0.0, 0.8, 0.8);
	glScalef(0.2, 0.1, 0.5);
	prisma(1, 1, 1);
	//INDICE 
	//Falange 1
	glScalef(5, 10, 1);
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(0.6, -0.2, 0);
	glTranslatef(-0.5, 0.0, 0.1);
	glRotatef(angleInd, 0, 1, 0);
	glTranslatef(0.5, 0.0, -0.1);
	glScalef(0.2, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(5, 10, 1);
	//Falange 2
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.1, 0, 0);
	glScalef(0.09, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(11.11, 10, 1);
	//Falange 3
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.085, 0, 0);
	glScalef(0.08, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(12.5, 10, 1);

	//MEDIO
	//Falange 1
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.195, -0.13, 0);
	glScalef(0.1, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(10, 10, 1);
	//Falange2
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.1, 0, 0);
	glScalef(0.1, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(10, 10, 1);
	//Falange 3
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.1, 0, 0);
	glScalef(0.1, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(10, 10, 1);

	//ANULAR
	//Falange 1
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.20, -0.13, 0);
	glScalef(0.1, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(10, 10, 1);
	//Falange2
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.09, 0, 0);
	glScalef(0.08, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(12.5, 10, 1);
	//Falange 3
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.08, 0, 0);
	glScalef(0.08, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(12.5, 10, 1);

	//MEÑIQUE
	//Falange 1
	glColor3f(1.0, 1.0, 0.0);
	glTranslatef(-0.185, -0.13, 0);
	glScalef(0.07, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(14.28, 10, 1);
	//Falange2
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.07, 0, 0);
	glScalef(0.07, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(14.28, 10, 1);
	//Falange 3
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0.07, 0, 0);
	glScalef(0.07, 0.1, 1);
	prisma(1, 1, 1);
	glScalef(14.28, 10, 1);
	glPopMatrix();
	glPushMatrix();
	//muslo izquierdo
	glTranslatef(-0.5, -1.5, -0.25);
	glColor3f(0.0, 1.0, 0.0);
	prisma(0.5, 1.0, 1.0);
	//rodilla izquierda
	glTranslatef(0.0, -0.625, 0.0);
	glColor3f(0.5, 0.5, 0.0);
	prisma(0.5, 0.25, 1.0);
	//rodilla izquierda
	glTranslatef(0.0, -0.875, 0.0);
	glColor3f(0.5, 0.0, 0.5);
	prisma(0.5, 1.5, 1.0);
	//pie izquierdo	
	glTranslatef(0.0, -0.875, 0.25);
	glColor3f(0.0, 0.5, 0.5);
	prisma(0.5, 0.25, 1.5);

	//muslo izquierdo
	glTranslatef(1.0, 2.375, -0.25);
	glColor3f(0.0, 1.0, 0.0);
	prisma(0.5, 1.0, 1.0);
	//rodilla izquierda
	glTranslatef(0.0, -0.625, 0.0);
	glColor3f(0.5, 0.5, 0.0);
	prisma(0.5, 0.25, 1.0);
	//rodilla izquierda
	glTranslatef(0.0, -0.875, 0.0);
	glColor3f(0.5, 0.0, 0.5);
	prisma(0.5, 1.5, 1.0);
	//pie izquierdo	
	glTranslatef(0.0, -0.875, 0.25);
	glColor3f(0.0, 0.5, 0.5);
	prisma(0.5, 0.25, 1.5);
	glPopMatrix();

	glutSwapBuffers();
    //glFlush();
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.1,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		case 'o':
		case 'O':
			if (angleHombro < 90)
				angleHombro += 0.2f;
			printf("ang: %f\n", angleHombro);
			break;
		case 'p':
		case 'P':
			if (angleHombro > -90)
				angleHombro -= 0.2f;
			break;
		case 'i':
		case 'I':
			if (angleCodo < 130)
				angleCodo += 0.2f;
			break;
		case 'u':
		case 'U':
			if (angleCodo > 0)
				angleCodo -= 0.2f;
			break;
		case 't':
		case 'T':
			if (anglePalma < 90)
				anglePalma += 0.2f;
			break;
		case 'y':
		case 'Y':
			if (anglePalma > -90)
				anglePalma -= 0.2f;
			break;
		case 'q':
		case 'Q':
			if (angleDedo < 90)
				angleDedo += 0.2f;
			break;
		case 'e':
		case 'E':
			if (angleDedo > 0)
				angleDedo -= 0.2f;
			break;
		case 'c':
		case 'C':
			if (angleInd < 0)
				angleInd += 0.2f;
			break;
		case 'v':
		case 'V':
			if (angleInd > -90)
				angleInd -= 0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
      //glutFullScreen ( ); // Full Screen Mode
      //break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
      //glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
      //break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;

    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Reporte 4"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



