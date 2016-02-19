#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>

#define BLACK 0, 0, 0

double cameraAngle;
double cameraAngleDelta;

float pos1, pos2, pos3;

double rectAngle;

bool canDrawGrid;

void drawBuilding(int x1, int y1, int x2,int y2, int z){
    //back side
    int minZ = 0;
    glColor3f(0,1,1);
	glBegin(GL_QUADS);{
	    glVertex3f(x1, y1, minZ);
	    glVertex3f(x1, y1, z);
	    glVertex3f(x2, y2, z);
	    glVertex3f(x2, y2, minZ);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x1, y1, minZ);
	    glVertex3f(x1, y1, z);

	    glVertex3f(x1, y1, z);
	    glVertex3f(x2, y2, z);

	    glVertex3f(x2, y2, z);
	    glVertex3f(x2, y2, minZ);

	    glVertex3f(x2, y2, minZ);
	    glVertex3f(x1, y1, minZ);
	}glEnd();

	//left side
	glColor3f(0,1,1);
	glBegin(GL_QUADS);{
	    glVertex3f(x1, y1, minZ);
	    glVertex3f(x1, y1, z);
	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x1+20, y1, minZ);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x1, y1, minZ);
	    glVertex3f(x1, y1, z);

	    glVertex3f(x1, y1, z);
	    glVertex3f(x1+20, y1, z);

	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x1+20, y1, minZ);

	    glVertex3f(x1+20, y1, minZ);
	    glVertex3f(x1, y1, minZ);
	}glEnd();

	//front side
	glColor3f(0,1,1);
	glBegin(GL_QUADS);{
	    glVertex3f(x1+20, y1, minZ);
	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x2+20, y2, minZ);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x1+20, y1, minZ);
	    glVertex3f(x1+20, y1, z);

	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x2+20, y2, z);

	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x2+20, y2, minZ);

	    glVertex3f(x2+20, y2, minZ);
	    glVertex3f(x1+20, y1, minZ);
	}glEnd();

	//right side
	glColor3f(0,1,1);
	glBegin(GL_QUADS);{
	    glVertex3f(x2, y2, minZ);
	    glVertex3f(x2, y2, z);
	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x2+20, y2, minZ);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x2, y2, minZ);
	    glVertex3f(x2, y2, z);

	    glVertex3f(x2, y2, z);
	    glVertex3f(x2+20, y2, z);

	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x2+20, y2, minZ);

	    glVertex3f(x2+20, y2, minZ);
	    glVertex3f(x2, y2, minZ);
	}glEnd();

	//roof
	glColor3f(0,1,1);
	glBegin(GL_QUADS);{
	    glVertex3f(x1, y1, z);
	    glVertex3f(x2, y2, z);
	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x1+20, y1, z);
	}glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINES);{
	    glVertex3f(x1, y1, z);
	    glVertex3f(x2, y2, z);

	    glVertex3f(x2, y2, z);
	    glVertex3f(x2+20, y2, z);

	    glVertex3f(x2+20, y2, z);
	    glVertex3f(x1+20, y1, z);

	    glVertex3f(x1+20, y1, z);
	    glVertex3f(x1, y1, z);
	}glEnd();
}

void car1(int x){
    glColor3f(1,0,0);
    glBegin(GL_QUADS);{
        glVertex3f(-10, 80-x, 5);
        glVertex3f(-10, 80-x, 10);
        glVertex3f(-10, 100-x, 10);
        glVertex3f(-10, 100-x, 5);
    }glEnd();
    glColor3f(1,0,0);
    glBegin(GL_QUADS);{
        glVertex3f(-10, 85-x, 5);
        glVertex3f(-10, 85-x, 20);
        glVertex3f(-10, 95-x, 20);
        glVertex3f(-10, 95-x, 5);
    }glEnd();
}

void car2(int x){
    glColor3f(0,0,1);
    glBegin(GL_QUADS);{
        glVertex3f(10, -80+x, 5);
        glVertex3f(10, -80+x, 10);
        glVertex3f(10, -100+x, 10);
        glVertex3f(10, -100+x, 5);
    }glEnd();
    glColor3f(0,0,1);
    glBegin(GL_QUADS);{
        glVertex3f(10, -85+x, 5);
        glVertex3f(10, -85+x, 20);
        glVertex3f(10, -95+x, 20);
        glVertex3f(10, -95+x, 5);
    }glEnd();
}

void car3(int x){
    glColor3f(0,1,0);
    glBegin(GL_QUADS);{
        glVertex3f(-100+x, 0, 5);
        glVertex3f(-100+x, 0, 10);
        glVertex3f(-80+x, 0, 10);
        glVertex3f(-80+x, 0, 5);
    }glEnd();
    glColor3f(0,1,0);
    glBegin(GL_QUADS);{
        glVertex3f(-95+x, 0, 5);
        glVertex3f(-95+x, 0, 20);
        glVertex3f(-85+x, 0, 20);
        glVertex3f(-85+x, 0, 5);
    }glEnd();
}

void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(BLACK, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera is looking?
	//3. Which direction is the camera's UP direction?

	//instead of CONSTANT information, we will define a circular path.
//	gluLookAt(-30,-30,50,	0,0,0,	0,0,1);

	gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), 150,		0,0,0,		0,0,1);
	//NOTE: the camera still CONSTANTLY looks at the center
	// cameraAngle is in RADIAN, since you are using inside COS and SIN


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/

	/****************************
	/ Author : Sadman Ilham
	****************************/

    //the main land
	/*glColor3f(0,0,1);
	glBegin(GL_QUADS);{
	    glVertex3f(-100, -100, 0);
	    glVertex3f(100, -100, 0);
	    glVertex3f(100, 100, 0);
	    glVertex3f(-100, 100, 0);
	}glEnd();*/

	//border
	glColor3f(1,1,1);
	glBegin(GL_LINES);{
	    glVertex3f(-100, -100, 0);
	    glVertex3f(-100, 100, 0);

	    glVertex3f(-100, 100, 0);
	    glVertex3f(100, 100, 0);

	    glVertex3f(100, 100, 0);
	    glVertex3f(100, -100, 0);

	    glVertex3f(100, -100, 0);
	    glVertex3f(-100, -100, 0);
	}glEnd();

	//roads
	glColor3f(1,1,1);
	glBegin(GL_QUADS);{
	    glVertex3f(-100,-20,0);
	    glVertex3f(-100,20,0);
	    glVertex3f(100,20,0);
	    glVertex3f(100,-20,0);
	}glEnd();

	glColor3f(1,1,1);
	glBegin(GL_QUADS);{
	    glVertex3f(-20,100,0);
	    glVertex3f(20,100,0);
	    glVertex3f(20,-100,0);
	    glVertex3f(-20,-100,0);
	}glEnd();

	//moving car
	pos1 += .1;
	if(pos1>180) pos1 = 0;
	car1(pos1);

    	pos2 += .05;
	if(pos2>180) pos2 = 0;
	car2(pos2);

	pos3 += .075;
	if(pos3>180) pos3 = 0;
	car3(pos3);

    //top left buildings 1st row
    drawBuilding(-90, -90, -90, -70, 50);
    drawBuilding(-90, -60, -90, -40, 30);

    //top left buildings 2nd row
    drawBuilding(-60, -90, -60, -70, 60);
    drawBuilding(-55, -60, -55, -40, 40);

    //top right buildings 1st row
    drawBuilding(-90, 90, -90, 70, 70);
    drawBuilding(-90, 60, -90, 40, 50);

    //top right buildings 2nd row
    drawBuilding(-60, 90, -60, 75, 80);
    drawBuilding(-60, 70, -60, 35, 45);

    //middle left buildings
    drawBuilding(40, -90, 40, -70, 40);
    drawBuilding(40, -60, 40, -40, 50);

    //middle right buildings
    drawBuilding(30, 90, 30, 70, 30);
    drawBuilding(30, 60, 30, 40, 50);

    //bottom left buildings
    drawBuilding(70, -90, 70, -70, 30);
    drawBuilding(75, -60, 75, -40, 30);

    //bottom right buildings
    drawBuilding(70, 90, 70, 70, 90);
    drawBuilding(70, 65, 70, 40, 30);



	/****************************
	/ Author : Sadman Ilham
	****************************/

	//add objects
	//rotate this rectangle around the Z axis

	/*glPushMatrix();{	//STORE the state
		glRotatef(rectAngle,	0,0,1);	// in DEGREE
		//a simple rectangles
		glColor3f(0.3, 0.4, 0.8);
		glBegin(GL_QUADS);{
			glVertex3f(0,0,30);
			glVertex3f(10,0,30);
			glVertex3f(10,20,30);
			glVertex3f(0,20,30);
		}glEnd();

		///lets draw another one in the XY plane --- i.e. Z = 0
		glColor3f(0.15, 0.2, 0.4);
		glBegin(GL_QUADS);{
			glVertex3f(0,0,0);
			glVertex3f(10,0,0);
			glVertex3f(10,20,0);
			glVertex3f(0,20,0);
		}glEnd();
	}glPopMatrix();*/		//the effect of rotation is not there now.



	//some gridlines along the field

	/*int i;

	//WILL draw grid IF the "canDrawGrid" is true:

	if(canDrawGrid == true){
		glColor3f(0.3, 0.3, 0.3);	//grey
		glBegin(GL_LINES);{
			for(i=-10;i<=10;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -100, 0);
				glVertex3f(i*10,  100, 0);

				//lines parallel to X-axis
				glVertex3f(-100, i*10, 0);
				glVertex3f( 100, i*10, 0);
			}
		}glEnd();
	}*/

	// draw the two AXES
	/*glColor3f(1, 1, 1);	//100% white
	glBegin(GL_LINES);{
		//Y axis
		glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
		glVertex3f(0,  150, 0);

		//X axis
		glVertex3f(-150, 0, 0);
		glVertex3f( 150, 0, 0);
	}glEnd();*/


	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Camera

	cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.	// keep the camera steady NOW!!

	//codes for any changes in Models

	rectAngle += 1;

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();	//this will call the display AGAIN
}

void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case '1':
			cameraAngleDelta += .0002;
			break;

        	case '2':
			cameraAngleDelta -= .0002;
			break;

		case '3':
			cameraAngleDelta = 0;
			break;

		default:
			break;
	}
}

void init(){
	//codes for initialization
	cameraAngle = 0;	//// init the cameraAngle
	cameraAngleDelta = 0;
	rectAngle = 0;
	canDrawGrid = true;

	//clear the screen
	glClearColor(BLACK, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(70,	1,	0.1,	10000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("City View");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
