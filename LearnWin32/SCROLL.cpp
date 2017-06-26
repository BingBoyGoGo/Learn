#if false
/*使用GetScrollRange等API实现*/
#include <windows.h>
#include <strsafe.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	RECT rect;
	PAINTSTRUCT ps;

	TCHAR szbuffer[128];
	size_t len;

	TEXTMETRIC tm;
	static int cyChar, vScreen, hScreen;
	static int ivScrollPos;			//滚动条变化时，窗口所绘画的内容是哪一条

	switch (msg)
	{
	case WM_LBUTTONDOWN:
		GetClientRect(hwnd, &rect);
		MessageBox(NULL, TEXT("你戳了白百何一下"), TEXT("你好坏"), MB_ICONSTOP);
		return 0;

	case WM_CREATE:
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hwnd, hdc);
		SetScrollRange(hwnd, SB_VERT, 0, 50, false);	//设置滚动条的范围
		SetScrollPos(hwnd, SB_VERT, 0, true);			//设置滚动条的位置
		return 0;

	case WM_SIZE:
		hdc = GetDC(hwnd);
		hScreen = LOWORD(lParam);
		vScreen = HIWORD(lParam);
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_HSCROLL:			//处理水平滚动条的消息
		return 0;				//操作基本同WM_VSCROLL

	case WM_VSCROLL:			//处理垂直滚动条的消息
		//LOWORD(wParam);		//低16位是在滚动条上的操作
		hdc = GetDC(hwnd);
		switch (LOWORD(wParam))
		{//通过改变ivScroll来改变WM_PAINT的绘制内容
		case SB_LINEUP:									//上一行
			ivScrollPos--;
			TextOut(hdc, 350, 50, TEXT("上一行"), 3);
			break;
		case SB_LINEDOWN:								//下一行
			ivScrollPos++;
			TextOut(hdc, 350, 50, TEXT("下一行"), 3);
			break;
		case SB_PAGEUP:									//上一页
			ivScrollPos -= vScreen / cyChar;			//得到一页的高度
			TextOut(hdc, 350, 50, TEXT("上一页"), 3);
			break;
		case SB_PAGEDOWN:								//下一页
			ivScrollPos += vScreen / cyChar;
			TextOut(hdc, 350, 50, TEXT("下一页"), 3);
			break;
		case SB_THUMBPOSITION:							//最后滚到的位置
			ivScrollPos = HIWORD(wParam);				//该参数的高16位是鼠标位置
			break;
		}
		ivScrollPos = max(0, min(ivScrollPos, 49));		//防止ivScrollPos变为负数
		SetScrollPos(hwnd, SB_VERT, ivScrollPos, true);	//设置滚动条的位置
		InvalidateRect(hwnd,NULL,true);					//发送一个重绘的消息到消息队列，执行前需要等待前面的消息执行完毕
		ReleaseDC(hwnd, hdc);
		return 0;
	
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 0; i < 50; i++)
		{
			StringCchPrintf(szbuffer, 128, TEXT("%d: %s"), i+1, TEXT("Bingogo"));
			StringCchLength(szbuffer, 128, &len);			//iTarget长度  
			SetTextAlign(hdc, TA_RIGHT | TA_TOP);
			TextOut(hdc, 80, cyChar*(i-ivScrollPos), szbuffer, len);
		}
		
		StringCchPrintf(szbuffer, 128, TEXT("当前客户区大小为 %d * %d"), hScreen, vScreen);
		StringCchLength(szbuffer, 128, &len);
		TextOut(hdc, 300, 30, szbuffer, len);
		
		EndPaint(hwnd, &ps);
		return 0;


	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;

	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("bing");
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;
	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Error RegisterClass"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(TEXT("bing"), NULL, 
		WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,//加上了水平和垂直滚动条 
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 600, NULL, NULL, hInstance, NULL);
	if (!hwnd)
	{
		MessageBox(NULL, TEXT("hwnd Error"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
		return 0;
	}
	if (!hInstance)
	{
		MessageBox(NULL, TEXT("hInstance Error"), TEXT("ERROR"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);					//发送WM_PAINT消息

	while (GetMessage(&msg, hwnd, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0; 
}
#endif

#if false
/*使用GetScrollInfo和SetScrollInfo实现*/
#include <windows.h>
#include <strsafe.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	SCROLLINFO si;			// 用于SCROLLWINDOW的参数
	TEXTMETRIC tm;			// 用于设置文本大小

	TCHAR szBuffer[128];	
	size_t strlen;

	static int cyChar;		// 文本的高度
	static int cyScroll;	// 滚动条高度



	switch (msg)
	{
	case WM_CREATE:
		GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		cyChar = tm.tmExternalLeading + tm.tmHeight;
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_SIZE:
		return 0;

	case WM_PAINT:
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;
	RECT rect;

	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.lpfnWndProc = WndProc;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("bing");

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, TEXT("Registing Error"), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(TEXT("bing"), TEXT("Bing"),
		WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, hInstance, NULL);

	if (!hwnd)
	{
		MessageBox(NULL, TEXT("hwnd Error"), TEXT("Error"), MB_ICONERROR);
		return 0;
	}
	if (!hInstance)
	{
		MessageBox(NULL, TEXT("hInstance Error"), TEXT("Error"), MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg,hwnd,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

#endif