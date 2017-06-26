/*
装在位图的函数
HRESULT D3DXLoadSurfaceFromFile(
	LPDIRECT3DSURFACE9 pDestSurface,
	CONST PALETTEENTRY* pDestPalette,
	CONST RECT* pDestRect,
	LPCTSTR pSrcFile,
	CONST RECT* pSrcRect,
	DWORD Filter,
	D3DCOLOR ColorKey,
	D3DXIMAGE_INFO* pSrcInfo
	);
*/

#if true

#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include <time.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
using namespace std;

const string APPTITLE = "Create Surface Program";
//macro to read the keyboard
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

//screen resolution
#define SCREENW 1024
#define SCREENH 768

//Direct3D objects
LPDIRECT3D9 d3d = NULL;
LPDIRECT3DDEVICE9 d3ddev = NULL;
LPDIRECT3DSURFACE9 surface = NULL;
LPDIRECT3DSURFACE9 backbuffer = NULL;
bool gameover = false;

//Game initialization function
bool Game_Init(HWND hwnd)
{
	//initialize Direct3D
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (d3d == NULL)
	{
		MessageBox(hwnd, "Error Initializing Direct3D", "Error", MB_OK);
		return false;
	}

	//set Direct3D presentation parameters
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = SCREENH;
	d3dpp.BackBufferWidth = SCREENW;
	d3dpp.hDeviceWindow = hwnd;

	//Create Direct3D device
	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL, hwnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &d3ddev);

	if (!d3ddev)
	{
		MessageBox(hwnd, "Error creating Window", "Error", MB_OK);
		return false;
	}

	//clear the backbuffer to black
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	//create pointer to the back buffer
	//d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);

	//create surface
	HRESULT result = d3ddev->CreateOffscreenPlainSurface(
		100,				//width of the surface
		100,				//height of the surface
		D3DFMT_X8R8G8B8,	//surface format
		D3DPOOL_DEFAULT,	//memory pool to use
		&surface,			//pointer to the surface
		NULL);				//reserved (always NULL)

	if (result != D3D_OK)
		return false;
	result = D3DXLoadSurfaceFromFile(surface, NULL, NULL, "bing.png", NULL, D3DX_DEFAULT, 0, NULL);
	if (result != D3D_OK)
		return false;
	return true;
}

//Game update function
void Game_Run(HWND hwnd)
{
	//make sure the Direct3D device is valid
	if (!d3ddev)	return;

	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);

	//start rendering
	if (d3ddev->BeginScene())
	{
		d3ddev->StretchRect(surface, NULL, backbuffer, NULL, D3DTEXF_NONE);
		d3ddev->EndScene();
		d3ddev->Present(NULL, NULL, NULL, NULL);
	}
	//check for escape key (to exit)
	if (KEY_DOWN(VK_ESCAPE))
	{
		PostMessage(hwnd, WM_DESTROY, 0, 0);
	}
}

//Game shutdown function
void Game_End(HWND hwnd)
{
	if (surface) surface->Release();
	if (d3ddev)	d3ddev->Release();
	if (d3d)	d3d->Release();
}

//Windows event callback function
LRESULT WINAPI WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		gameover = true;
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//create the window class structure
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "MainWindowClass";
	wc.hIconSm = NULL;
	RegisterClassEx(&wc);

	//Create a new window
	HWND window = CreateWindow("MainWindowClass", APPTITLE.c_str(),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		SCREENW, SCREENH, NULL, NULL, hInstance, NULL);
	//was there an error creating the window?
	if (window == 0)return 0;
	//display the window
	ShowWindow(window, nCmdShow);
	UpdateWindow(window);
	//initialize the game
	if (!Game_Init(window))	return 0;

	//main message loop
	MSG message;
	while (!gameover)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		Game_Run(window);
	}
	return message.wParam;
}

#endif 