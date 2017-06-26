#if false

#include <windows.h>
#include <iostream>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;

	switch (msg)
	{
	//case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
		MessageBox(NULL, L"哎呀，我被按了一下", L"好爽啊", MB_OK);
		return 0;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		DrawText(hdc, L"Hello Windows!", -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		EndPaint(hwnd, &ps);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR cmdLine, int cmdShow)
{
	HWND hwnd;
	MSG msg;
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.lpfnWndProc = WndProc;
	wc.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = L"BINGOGO";

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, L"Error RegisterClass", L"ERROR", MB_OK | MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(L"BINGOGO",
		L"Windows",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hInstance)
	{
		MessageBox(NULL, L"ERROR HINSTANCE", L"BERROR", MB_OK);
	}
	if (!hwnd)
	{
		MessageBox(NULL, L"ERROR", L"ERROR", 0);
	}//CreateWindow的第一个参数值和WNDCLASS的lpzeClassName一定要一致！！！否则CreateWindow返回NULL
	ShowWindow(hwnd,cmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


#endif
