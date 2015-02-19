#include "StdAfx.h"
#include "Direct3dRenderer.h"

// include the basic windows header files and the Direct3D header file
#include <windows.h>
#include <windowsx.h>
#include <iostream>
#include <ctime>

#include <d3d9.h>
#include <d3dx9.h>
// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

// global declarations
LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;    // the pointer to the vertex buffer

LPD3DXSPRITE gSprite=NULL;			// our sprite interfaces
LPDIRECT3DTEXTURE9 gTexture=NULL;	// our texture

HWND hWnd;
MSG msg;

std::time_t start;

// the WindowProc function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

// this function initializes and prepares Direct3D for use
void initD3D(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface

	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D
	d3dpp.BackBufferFormat=D3DFMT_UNKNOWN;
	d3dpp.BackBufferCount=1;


	// create a device class using this information and the info from the d3dpp stuct
	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);

	// Create our sprite object - only one needed as it is just a set of functions
	D3DXCreateSprite(d3ddev,&gSprite);

	D3DXCreateTexture(d3ddev, 200, 200, 0, 0, D3DFMT_X8R8G8B8, D3DPOOL_MANAGED, &gTexture);
	D3DXFilterTexture (gTexture, 0, 0, D3DX_DEFAULT); 
}


// this is the main message handler for the program
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		} break;
	}

	return DefWindowProc (hWnd, message, wParam, lParam);
}



Direct3dRenderer::Direct3dRenderer(void)
{
}


Direct3dRenderer::~Direct3dRenderer(void)
{
	if (gTexture)
	{
		gTexture->Release();
		gTexture=NULL;
	}

	if (gSprite)
	{
		gSprite->Release();
		gSprite=NULL;
	}

	d3ddev->Release();    // close and release the 3D device
	d3d->Release();    // close and release Direct3D
}

void Direct3dRenderer::createWindow(int width, int height)
{	
	m_Width = width + 15;
	m_Height = height + 40;

	HINSTANCE pHinst = (HINSTANCE)GetCurrentProcess();
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = pHinst;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpszClassName = L"WindowClass";

	RegisterClassEx(&wc);

	//HWND hWnd;
	hWnd = CreateWindowEx(NULL,
		L"WindowClass",
		L"Our Direct3D Program",
		WS_OVERLAPPEDWINDOW,
		0, 0,
		m_Width, m_Height,
		NULL,
		NULL,
		pHinst,
		NULL);	
	
	// set up and initialize Direct3D
	initD3D(hWnd);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	MSG msg;
	ZeroMemory( &msg, sizeof(msg) );

	start = std::time(NULL);
}

void Direct3dRenderer::preRender()
{
	if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	if(msg.message == WM_QUIT)
	{
		this->mRunning = false;
	}

	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3ddev->BeginScene();    // begins the 3D scene
	
}

void Direct3dRenderer::renderObject(StaticBox* box)
{	
	RECT rct;
	rct.left=0;
	rct.right=box->getWidth();	    

	D3DXVECTOR3 pos(box->getOrigin().x,box->getOrigin().y,0);

	// Draw our sprites
	gSprite->Begin(D3DXSPRITE_ALPHABLEND);		

	// Top sprite		
	rct.top=0;
	rct.bottom=box->getHeight();

	d3ddev->SetTextureStageState( 0, D3DTSS_COLOROP,   D3DTOP_ADD );
	d3ddev->SetTextureStageState( 0, D3DTSS_COLORARG1, D3DTA_TEXTURE );
	d3ddev->SetTextureStageState( 0, D3DTSS_COLORARG2, D3DTA_DIFFUSE );
		
	
	gSprite->Draw(gTexture, &rct, NULL,&pos,D3DCOLOR_COLORVALUE(box->getColor().getR(),box->getColor().getG(),box->getColor().getB(),1));

	// Done
	gSprite->End();

}


void Direct3dRenderer::postRender()
{
	d3ddev->EndScene();    // ends the 3D scene
	d3ddev->Present(NULL, NULL, NULL, NULL);   // displays the created frame on the screen  
}


void Direct3dRenderer::renderString(const std::string& str, float x, float y)
{	
}

void Direct3dRenderer::closeWindow()
{
}

double Direct3dRenderer::getTime()
{
	return std::difftime(std::time(NULL), start);
}

bool Direct3dRenderer::getRunning()
{
	return mRunning;
}

int Direct3dRenderer::getKey(int key)
{
	if (msg.message == WM_KEYDOWN)
	{	
		if (key == 263)
		{
			return msg.wParam == VK_LEFT;		
		}
		else if (key == 262)
		{
			return msg.wParam == VK_RIGHT;
		}
	}
	return 0;
}

