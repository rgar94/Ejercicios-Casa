//Semestre 2019 - 2
 /*
 García Callejas Ricardo
 Grupo 2
 Visual Studio 2017
 Reporte 4
 Manual
 Se utilizo la función prisma de la práctica anterior usando las funciones de translate se pudo dibujar la figura deseada,
 cuidando simpre la posición en la que nos encontramos despues de realizar el gltranslate3f
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




void InitGL ( GLvoid )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Negro de fondo
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
	prisma(1,1,1);
	//cuello
	glTranslatef(0.0,-0.75,0.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma(0.5, 0.5, 0.5);
	//torso
	glTranslatef(0.0, -1.25, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	prisma(2.0, 2.0, 1.0);
	//hombro derecho
	glTranslatef(1.25, 0.75, 0.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma(0.5, 0.5, 1.0);
	//antebrazo derecho
	glTranslatef(1.25, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	prisma(2.0, 0.5, 1.0);
	//brazo derecho
	glTranslatef(1.5, 0.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	prisma(1.0, 0.5, 1.0);
	//mano derecha
	glTranslatef(0.75, 0.0, 0.25);
	glColor3f(1.0, 0.0, 1.0);
	prisma(0.5, 0.5, 1.5);
	//hombro izquierdo
	glTranslatef(-6.0, 0.0, -0.25);
	glColor3f(0.0, 1.0, 0.0);
	prisma(0.5, 0.5, 1.0);
	//antebrazo izquierdo
	glTranslatef(-1.25, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	prisma(2.0, 0.5, 1.0);
	//brazo izquierdo
	glTranslatef(-1.5, 0.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	prisma(1.0, 0.5, 1.0);
	//mano izquierdo
	glTranslatef(-0.75, 0.0, 0.25);
	glColor3f(1.0, 0.0, 1.0);
	prisma(0.5, 0.5, 1.5);

	//muslo izquierdo
	glTranslatef(4.25, -2.25, -0.25);
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
		case 'q':
		case 'Q':
			transY += 0.2f;
			break;
		case 'e':
		case 'E':
			transY -= 0.2f;
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



