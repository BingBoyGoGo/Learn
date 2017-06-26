#if false
/*ʹ��GetScrollRange��APIʵ��*/
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
	static int ivScrollPos;			//�������仯ʱ���������滭����������һ��

	switch (msg)
	{
	case WM_LBUTTONDOWN:
		GetClientRect(hwnd, &rect);
		MessageBox(NULL, TEXT("����˰װٺ�һ��"), TEXT("��û�"), MB_ICONSTOP);
		return 0;

	case WM_CREATE:
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hwnd, hdc);
		SetScrollRange(hwnd, SB_VERT, 0, 50, false);	//���ù������ķ�Χ
		SetScrollPos(hwnd, SB_VERT, 0, true);			//���ù�������λ��
		return 0;

	case WM_SIZE:
		hdc = GetDC(hwnd);
		hScreen = LOWORD(lParam);
		vScreen = HIWORD(lParam);
		ReleaseDC(hwnd, hdc);
		return 0;

	case WM_HSCROLL:			//����ˮƽ����������Ϣ
		return 0;				//��������ͬWM_VSCROLL

	case WM_VSCROLL:			//����ֱ����������Ϣ
		//LOWORD(wParam);		//��16λ���ڹ������ϵĲ���
		hdc = GetDC(hwnd);
		switch (LOWORD(wParam))
		{//ͨ���ı�ivScroll���ı�WM_PAINT�Ļ�������
		case SB_LINEUP:									//��һ��
			ivScrollPos--;
			TextOut(hdc, 350, 50, TEXT("��һ��"), 3);
			break;
		case SB_LINEDOWN:								//��һ��
			ivScrollPos++;
			TextOut(hdc, 350, 50, TEXT("��һ��"), 3);
			break;
		case SB_PAGEUP:									//��һҳ
			ivScrollPos -= vScreen / cyChar;			//�õ�һҳ�ĸ߶�
			TextOut(hdc, 350, 50, TEXT("��һҳ"), 3);
			break;
		case SB_PAGEDOWN:								//��һҳ
			ivScrollPos += vScreen / cyChar;
			TextOut(hdc, 350, 50, TEXT("��һҳ"), 3);
			break;
		case SB_THUMBPOSITION:							//��������λ��
			ivScrollPos = HIWORD(wParam);				//�ò����ĸ�16λ�����λ��
			break;
		}
		ivScrollPos = max(0, min(ivScrollPos, 49));		//��ֹivScrollPos��Ϊ����
		SetScrollPos(hwnd, SB_VERT, ivScrollPos, true);	//���ù�������λ��
		InvalidateRect(hwnd,NULL,true);					//����һ���ػ����Ϣ����Ϣ���У�ִ��ǰ��Ҫ�ȴ�ǰ�����Ϣִ�����
		ReleaseDC(hwnd, hdc);
		return 0;
	
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		for (int i = 0; i < 50; i++)
		{
			StringCchPrintf(szbuffer, 128, TEXT("%d: %s"), i+1, TEXT("Bingogo"));
			StringCchLength(szbuffer, 128, &len);			//iTarget����  
			SetTextAlign(hdc, TA_RIGHT | TA_TOP);
			TextOut(hdc, 80, cyChar*(i-ivScrollPos), szbuffer, len);
		}
		
		StringCchPrintf(szbuffer, 128, TEXT("��ǰ�ͻ�����СΪ %d * %d"), hScreen, vScreen);
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
		WS_OVERLAPPEDWINDOW | WS_HSCROLL | WS_VSCROLL,//������ˮƽ�ʹ�ֱ������ 
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
	UpdateWindow(hwnd);					//����WM_PAINT��Ϣ

	while (GetMessage(&msg, hwnd, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0; 
}
#endif

#if false
/*ʹ��GetScrollInfo��SetScrollInfoʵ��*/
#include <windows.h>
#include <strsafe.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	SCROLLINFO si;			// ����SCROLLWINDOW�Ĳ���
	TEXTMETRIC tm;			// ���������ı���С

	TCHAR szBuffer[128];	
	size_t strlen;

	static int cyChar;		// �ı��ĸ߶�
	static int cyScroll;	// �������߶�



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