#include <windows.h>
#include <strsafe.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	TCHAR szBuffer[128];
	size_t iTarget;

	static int cyChar, cyScreen;

	TEXTMETRIC tm;

	switch (msg)
	{
	case WM_CREATE:
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc,&tm);
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_SIZE:
		cyScreen = HIWORD(lParam);
		return 0;

	case WM_PAINT:
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rect);
		SetPixelV(hdc, 10, 10, RGB(200,20,20));
		MoveToEx(hdc, 10, 13, NULL);
		LineTo(hdc, 200, 200);
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_DESTROY:
		return 0;

	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;

	WNDCLASS wc;
	//wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.lpfnWndProc = WndProc;
	wc.lpszMenuName = TEXT("Bing");
	wc.lpszClassName = TEXT("bing");
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Registing Error"), TEXT("ERROR"), MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(TEXT("bing"), TEXT("bingogo"),
		WS_OVERLAPPEDWINDOW | WS_VSCROLL,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, hInstance, NULL);

	if (!hwnd)
	{
		MessageBox(NULL, TEXT("hwnd Error"), TEXT("ERROR"), MB_ICONERROR);
		return 0;
	}
	if (!hInstance)
	{
		MessageBox(NULL, TEXT("hInstance Error"), TEXT("ERROR"), MB_ICONERROR);
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

