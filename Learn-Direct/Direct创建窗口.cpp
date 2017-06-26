#if false
#include <iostream>
#include <windows.h>
#include <d3d9.h>
#include <string>
#include <time.h>

using namespace std;
#pragma comment(lib, "d3d9.lib")	//让链接器在创建的最终可执行文件中加入这个库文件

	const string APPTITLE = "Bingogo's FirstDirect3D_Windowed";
	const int SCREENW = 1024;
	const int SCREENH = 768;

	LPDIRECT3D9 d3d = NULL;					//D3D的大佬：接口
	LPDIRECT3DDEVICE9 d3ddev = NULL;		//设备对象
	bool gameover = false;

	#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

	bool Game_Init(HWND hwnd)
	{
		//initialize Direct3D
		d3d = Direct3DCreate9(D3D_SDK_VERSION);//初始化D3D，说明D3D已经准备好并可以使用
		if (d3d == NULL)
		{
			MessageBox(hwnd, "Error initializing Direct3D", "Error", MB_OK);
			return FALSE;
		}

		//set Direct3D presentation parameters
		
		//窗口化的present parameter
		D3DPRESENT_PARAMETERS d3dpp;				//创建一个D3DPERSENT_PARAMETERS结构体变量用于设置设备参数
		ZeroMemory(&d3dpp, sizeof(d3dpp));			//使用前将D3DPRESENT_PARAMETERS结构体中所有值清零
		d3dpp.Windowed = TRUE;						//窗口化
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;	//后台缓冲区的交换模式
		d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;	//后台缓冲区格式,在窗口模式中，传递D3DFMT_UNKNOW使用桌面格式
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		d3dpp.BackBufferCount = 1;
		d3dpp.BackBufferHeight = SCREENH;
		d3dpp.BackBufferWidth = SCREENW;
		d3dpp.hDeviceWindow = hwnd;
		
		/**
		//全屏的present parameter
		D3DPRESENT_PARAMETERS d3dpp;
		D3DDISPLAYMODE dm;
		d3d->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &dm);
		ZeroMemory(&d3dpp, sizeof(d3dpp));
		d3dpp.hDeviceWindow = hwnd;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.BackBufferFormat = dm.Format;
		d3dpp.BackBufferCount = 1;
		d3dpp.BackBufferWidth = dm.Width;
		d3dpp.BackBufferHeight = dm.Height;
		d3dpp.Windowed = FALSE;
		**/
		//create Direct3D device
		d3d->CreateDevice(
			D3DADAPTER_DEFAULT,
			D3DDEVTYPE_HAL,
			hwnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp,
			&d3ddev);
		if (d3ddev == NULL)
		{
			MessageBox(hwnd, "Error creating Direct3D device", "Error", MB_OK);
			return FALSE;
		}
		return true;
	}

	//Game update function
	void Game_Run(HWND hwnd)
	{
		//make sure the Direct3D device is valid
		if (!d3ddev)	return;
		d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 225), 1.0f, 0);
		
		//start rendering
		if (d3ddev->BeginScene())
		{
			//do something?
			//stop rendering
			d3ddev->EndScene();
			//copy back buffer to the frame buffer
			d3ddev->Present(NULL, NULL, NULL, NULL);
		}

		//check for escape key (to exit program)
		if (KEY_DOWN(VK_ESCAPE))
			PostMessage(hwnd, WM_DESTROY, 0, 0);
	}

	//Game shutdown function
	void Game_End(HWND hwnd)
	{
		if (d3ddev)
		{
			d3ddev->Release();
			d3ddev = NULL;
		}
		if (d3d)
		{
			d3d->Release();
			d3d = NULL;
		}
	}

	//windows event handling function
	LRESULT WINAPI WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_DESTROY:
			gameover = true;
			break;
		}
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	//Main Windows entry function
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
	{
		WNDCLASSEX wc;
		MSG msg;
		//set the new window's properties
		//previously found in the MyRegisterClass function
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.lpfnWndProc = (WNDPROC)WinProc;
		wc.style = 0;		//CS_HREDRAW | CS_VREDRAW;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hIcon = NULL;
		wc.hIconSm = NULL;
		wc.lpszMenuName = NULL;
		wc.hInstance = hInstance;
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);
		wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wc.lpszClassName = "MainWindowClass";
		if (!RegisterClassEx(&wc))
			return FALSE;

		//create a new window
		//previously found in the InitInstance function
		//窗口化的窗口
		HWND hwnd = CreateWindow("MainWindowClass", APPTITLE.c_str(),
			WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
			SCREENW, SCREENH, (HWND)NULL,
			(HMENU)NULL, hInstance, (LPVOID)NULL);
		/*
		//创建一个全频的窗口
		HWND hwnd = CreateWindow("MainWindowClass",APPTITLE.c_str(),
			WS_EX_TOPMOST | WS_POPUP,0,0,//位置设为0,0
			640,480,(HWND)NULL,
			(HMENU)NULL,hInstance,(LPVOID)NULL);

		//上面d3dpp改成
			D3DDISPLAYMODE dm;
			d3d->GetAdapterDisplayMode(D3DADAPATER_DEFAULT,&dm);
			ZeroMemory(&d3dpp,sizeof(d3dpp));
			d3dpp.hDeviceWindow = hwnd;
			d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
			d3dpp.BackBufferFormat = dm.Format;
			d3dpp.BackBufferCount = 1;
			d3dpp.BackBufferWidth = dm.Width;
			d3dpp.BackBufferHeight = dm.Height;
			d3dpp.Windowed = FALSE;
		*/		

		//was there an error creating the window?
		if (hwnd == 0)	return 0;
		//display the window
		ShowWindow(hwnd, nCmdShow);
		UpdateWindow(hwnd);
		//initialize the game 
		if (!Game_Init(hwnd))	return 0;

		//Main message loop
		while (!gameover)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			Game_Run(hwnd);
		}
		Game_End(hwnd);
		return msg.wParam;
	}




#endif