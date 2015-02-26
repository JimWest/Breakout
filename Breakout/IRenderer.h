#pragma once
#include "StaticBox.h"

// An abstract class for a RendererAPI like OpenGL.
class IRenderer
{
public:
	// Default deconstructor.
	virtual ~IRenderer(void) {};

	// Creates a new window for rendering.
	// Will also create and initialize all needed rendering objects.
	//
	// @param width The width of the window.	
	// @param height The height of the window.
	virtual void createWindow(int width, int height, char *title) {};

	// Handles all stuff that needs to be done before actually render something
	// like clearing the window etc. This needs to be called before rendering 
	// objects once per frame.
	virtual void preRender() {};

	// Renders the given StaticBox with its correct color, position, width and height.
	//
	// @param *box The box object that should be rendered.
	virtual void renderObject(StaticBox* box) {}; 

	// Handles the Direct3D events that needs to be happen after the rendering.
	// This needs to be called after rendereing all the objects once per frame.
	virtual void postRender() {};

	// Prints the given number 
	//
	// @param number The number that should be printed.
	// @param x The x coordinate where the number should be printed.
	// @param y The y coordinate where the number should be printed.
	virtual void renderNumber(int number, int x, int y) {};

	// Closes the current window.
	virtual void closeWindow() {};

	// Returns the current time of the renderer.	
	//
	// @return The value of the current time.
	virtual double getTime() { return 0;};
	
	// Returns if the Renderer is still running or terminated.	
	//
	// @return True if the renderer is still running.
	virtual bool getRunning() { return false;};

	// Returns the current time of the renderer.	
	//
	// @param key The Key-Code of the key (see KeyInput.h)
	// @return 1 if the key is pressed.
	virtual int getKey(int key) { return 0;};
};

