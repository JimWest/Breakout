#pragma once
#include "irenderer.h"
#include <windows.h>
#include <windowsx.h>
#include <iostream>
#include <ctime>
#include "KeyInput.h"

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

class Direct3dRenderer :
	public IRenderer
{
		
private:
	bool mRunning;	
	int m_Width, m_Height;	

	LPDIRECT3D9 d3d;				// the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 d3ddev;		// the pointer to the device class

	LPD3DXSPRITE gSprite;			// our sprite interfaces
	LPDIRECT3DTEXTURE9 gTexture;	// our texture
	ID3DXFont *g_pFont;

	HWND hWnd;
	MSG msg;

	std::time_t start;	
	
	// Set up and initializes Direct3D.
	// Has to be called after the creation of the window.
	void initD3D(HWND hWnd);

public:
	Direct3dRenderer(void);
	~Direct3dRenderer(void);

	// Creates a new Windows for the Direct3D Rendering.
	// Will also create and initialize all needed Direct3D objects.
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
	virtual void renderObject(StaticBox *box);

	// Handles the Direct3D events that needs to be happen after the rendering.
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

