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

	LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class

	LPD3DXSPRITE gSprite;			// our sprite interfaces
	LPDIRECT3DTEXTURE9 gTexture;	// our texture
	ID3DXFont *g_pFont;

	HWND hWnd;
	MSG msg;

	std::time_t start;	

	void initD3D(HWND hWnd);

public:
	Direct3dRenderer(void);
	~Direct3dRenderer(void);

	virtual void createWindow(int width, int height);
	virtual void preRender();
	virtual void renderObject(StaticBox* box);
	virtual void postRender();
	virtual void renderNumber(int number, int x, int y);
	virtual void closeWindow();
	virtual double getTime();
	virtual bool getRunning();
	virtual int getKey(int key);

};

