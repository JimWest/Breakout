#include "StdAfx.h"
#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer(void)
{
}

OpenGLRenderer::~OpenGLRenderer(void)
{
	glfwTerminate();
}


static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}


void OpenGLRenderer::createWindow(int width, int height, char *title)
{
	m_Width = width;
	m_Height = height;

	// Initialize the glfw library
	if (!glfwInit())
		exit(EXIT_FAILURE);

	glfwSetErrorCallback(error_callback);

	mRunning = true;

	// Create a windowed mode window and its OpenGL context
	mWindow = glfwCreateWindow(width, height, title, NULL, NULL);

	if (!mWindow)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}	

	glfwMakeContextCurrent(mWindow);

	float ratio;
	glfwGetFramebufferSize(mWindow, &width, &height);
	ratio = width / (float) height;

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glfwWindowHint(GLFW_SAMPLES, 4);

	// set the viewport so the coordinate center is not in the center of the screen
	// but on the upper left corner
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	

	// generate the texture name
	glGenTextures(1, &score);

}

void OpenGLRenderer::preRender()
{
	// clears the bacakground color
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	// replaces the current matrix with the identity matrix
	glLoadIdentity();

	// activates orthographic 2d render mode
	glOrtho(0 ,m_Width, m_Height, 0, -1, 1);
}

void OpenGLRenderer::renderObject(StaticBox* box)
{	
	// Saves both projection and modelview matrices to the matrix stack.
	glPushMatrix();

	// sets the Color of the StaticBox
	glColor3f(box->getColor().getR(), box->getColor().getG(), box->getColor().getB()); 

	// actual Render of the box
	glBegin(GL_QUADS); 
	glVertex2f(box->getOrigin().x, box->getOrigin().y);
	glVertex2f(box->getOrigin().x + box->getWidth(), box->getOrigin().y);
	glVertex2f(box->getOrigin().x + box->getWidth(), box->getOrigin().y + box->getHeight());
	glVertex2f(box->getOrigin().x, box->getOrigin().y + box->getHeight());
	glEnd( );

	// Restores both projection and modelview matrices off the top of the matrix stack
	glPopMatrix(); 
}


void OpenGLRenderer::postRender()
{	
	// Swaps front and back buffer	
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}

void OpenGLRenderer::renderNumber(int number, int x, int y)
{	
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, score);

	// actuall Rendering of the number, gets the desirec number pixel data from images 
	// created by gimp and exported as raw c image which can be loaded directly.

	switch (number)
	{		
	case 1:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_1.width, number_1.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_1.pixel_data);
		break;
	case 2:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_2.width, number_2.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_2.pixel_data);
		break;
	case 3:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_3.width, number_3.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_3.pixel_data);
		break;
	case 4:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_4.width, number_4.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_4.pixel_data);
		break;
	case 5:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_5.width, number_5.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_5.pixel_data);
		break;
	case 6:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_6.width, number_6.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_6.pixel_data);
		break;
	case 7:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_7.width, number_7.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_7.pixel_data);
		break;
	case 8:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_8.width, number_8.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_8.pixel_data);
		break;
	case 9:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_9.width, number_9.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_9.pixel_data);
		break;
	case 0:
	default:
		glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, number_0.width, number_0.height, 
			0, GL_RGBA, GL_UNSIGNED_BYTE, number_0.pixel_data);
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glEnable(GL_TEXTURE_2D);

	glTranslatef(x, y, 1);
	glScalef(30, 40, 1);


	glColor3f(1,1,1);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 0.0, 1.0);
	glTexCoord2d(0, 0); glVertex2d(0.0, 0.0);
	glTexCoord2d(0, 1); glVertex2d(0.0, 1.0);
	glTexCoord2d(1, 1); glVertex2d(1.0, 1.0);
	glTexCoord2d(1, 0); glVertex2d(1.0, 0.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glPopMatrix(); 
}

void OpenGLRenderer::closeWindow()
{
	glfwSetWindowShouldClose(mWindow, GL_TRUE);
	mRunning = false;
}

double OpenGLRenderer::getTime()
{
	return glfwGetTime();
}

bool OpenGLRenderer::getRunning()
{
	return mRunning && !glfwWindowShouldClose(mWindow);
}

int OpenGLRenderer::getKey(int key)
{
	int glfwKey = 0;

	// translates the KeyInput enum to the GLFW input scheme
	switch (key)
	{
	case KeyUp:
		glfwKey = GLFW_KEY_UP;
		break;
	case KeyDown:
		glfwKey = GLFW_KEY_DOWN;
		break;
	case KeyLeft:
		glfwKey = GLFW_KEY_LEFT;
		break;
	case KeyRight:
		glfwKey = GLFW_KEY_RIGHT;
		break;
	case KeyR:
		glfwKey = GLFW_KEY_R;
		break;
	default:
		return 0;		
	}

	return glfwGetKey(mWindow, glfwKey);
}
