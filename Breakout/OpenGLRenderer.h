#pragma once
#include "irenderer.h"
#include <GLFW/glfw3.h>
#include "KeyInput.h"

#include "0.c"		
#include "1.c"		
#include "2.c"		
#include "3.c"		
#include "4.c"		
#include "5.c"		
#include "6.c"		
#include "7.c"		
#include "8.c"		
#include "9.c"	

// Realizes a RenderAPI with OpenGL Engine.
class OpenGLRenderer :
	public IRenderer
{

private:
	bool mRunning;
	GLFWwindow* mWindow;
	int m_Width, m_Height;
	GLuint score;

public:
	OpenGLRenderer(void);
	~OpenGLRenderer(void);

	// Creates a new Windows for the OpenGL Rendering.
	// Will also create and initialize all needed OpenGL objects.
	//
	// @param width The width of the window.	
	// @param height The height of the window.
	virtual void createWindow(int width, int height);

	// Handles all stuff that needs to be done before actually render something
	// like clearing the window etc. This needs to be called before rendering 
	// objects once per frame.
	virtual void preRender();

	// Renders the given StaticBox with its correct color, position, width and height.
	//
	// @param *box The box object that should be rendered.
	virtual void renderObject(StaticBox* box);

	// Handles the OpenGL events that needs to be happen after the rendering.
	// This needs to be called after rendereing all the objects once per frame.
	virtual void postRender();

	// Prints the given number 
	//
	// @param number The number that should be printed.
	// @param x The x coordinate where the number should be printed.
	// @param y The y coordinate where the number should be printed.
	virtual void renderNumber(int number, int x, int y);

	// Closes the current window.
	virtual void closeWindow();

	// Returns the current time of the renderer.	
	//
	// @return The value of the current time.
	virtual double getTime();
	
	// Returns if the Renderer is still running or terminated.	
	//
	// @return True if the renderer is still running.
	virtual bool getRunning();
	
	// Returns the current time of the renderer.	
	//
	// @param key The Key-Code of the key (see KeyInput.h)
	// @return 1 if the key is pressed.
	virtual int getKey(int key);
};

