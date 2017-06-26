#if false
#include <windows.h>
#include <strsafe.h>//StringCch...
#define LINELENGTH 20

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
//	RECT rect;
	PAINTSTRUCT ps;
	TCHAR szbuffer[20];	// = TEXT("Bingogo");
	int i;
	size_t iTarget;		// StringCchLength

	////�ı��ĳߴ�
	//static int cxChar, cyChar;	// �ı��Ŀ���
	//TEXTMETRIC tm;				// �ߴ�ṹ 
	////��WM_CREATEʵ��

	switch (msg)
	{
	////��仺����
	//case WM_CREATE:
	//	hdc = GetDC(hwnd);//�����豸����
	//	//���óߴ�
	//	GetTextMetrics(hdc, &tm);	//��ȡ�ı��ߴ粢��仺����
	//	cxChar = tm.tmAveCharWidth;
	//	cyChar = tm.tmHeight + tm.tmExternalLeading;
	//	ReleaseDC(hwnd, hdc);		//����豸����
	//
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		//GetClientRect(hwnd, &rect);
		
		for (i = 0; i < 10; i++)
		{
			//wsprintf(szbuffer, TEXT("%2d %s"), i+1, TEXT("Bingogo"));
			StringCchPrintf(szbuffer, 20, TEXT("Bingogo"));
			StringCchLength(szbuffer, 20, &iTarget);
			TextOut(hdc, 0, i*LINELENGTH, szbuffer, iTarget);
		}
		
		EndPaint(hwnd, &ps);
		return 0;

	//case WM_CLOSE:
	//	MessageBox(hwnd, TEXT("ȷ��Ҫ�˳���"), TEXT("�˳�"), MB_YESNOCANCEL | MB_ICONQUESTION);
	//	return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hwnd,msg,wParam,lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwnd;
	MSG msg;

	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(hInstance, IDC_ARROW);
	wc.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("bing");
	wc.lpszMenuName = NULL;
	wc.hInstance = hInstance;

	if (!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("Registing Error"), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(TEXT("bing"), NULL,
		WS_OVERLAPPEDWINDOW,
		0, 0, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	if (!hwnd)
	{
		MessageBox(NULL, TEXT("Creating window Error"), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}
	if (!hInstance)
	{
		MessageBox(NULL, TEXT("hInstance Error"), TEXT("Error"), MB_OK | MB_ICONERROR);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, hwnd, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
#endif