#if false
#include <windows.h>
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE prevInstance,LPSTR lpstr,int cmdLine)
{
	MessageBox(NULL, TEXT("WINDOWS!!!"), TEXT("Bingogo"), MB_OKCANCEL | MB_DEFBUTTON2 | MB_ICONINFORMATION);
}

#endif

/*�Ⱥ���ѧ����API����*/
/*

	-MessageBox			:	��ʾ�ı��Ĵ���
	-GetMessage			:	��ȡϵͳ��Ϣ
	-TranslateMessage	:	 
	-DispatchMessage	:
	-PostQuitMessage	:	�˳���Ϣ

	-GetDC				:	��ȡ�豸����
	-ReleaseDC			:	�ͷ��豸����

	-DrawText			:	�ı����
	-TextOut			:	�ı����

	-BeginPaint			:	���ƴ���
	-EndPaint			:	ֹͣ����

	-GetClientRect		:	��ȡ�û���
	-window��С�ı�ʱ�᷵��һ��WM_SIZE��Ϣ  /SCROLL.cpp��ʾ
		-LOWORD(lParam)		:	��ȡ�û����Ŀ�ȣ�Low Word����16λ
		-HIWORD(lParam)		:	��ȡ�û����ĸ߶ȣ���16λ
							
	-wsprintf			:	���ַ������뻺�����������������������
	-lstrlen			:	��ȡ�ַ�����С
	-StringCchPrintf	:	��wsprintf��ȫ
	-StringCchLength	:	��ȡ�ַ�����С

	-GetTextMetrics		:	��ȡ�ı��ߴ粢��仺����,���TEXTMETIRC�ṹ��ʹ��
	-GetSystemMetrics	:	��ȡϵͳ����ͼ����ĳߴ���Ϣ������ꡢͼ�꣬����ֵ����������Ϊ��λ,Ŀǰ�н�100������
							����GetSystemMetircs(SM_CXSCREEN)������Ļ���,GetSystemMetircs(SM_CYSCREEN)������Ļ�߶�
	
	-SetTextAlign		:	�����ı����뷽ʽ��TA_LEFT,TA_RIGHT,TA_TOP
*/


/*
����һ�����ڵļ򵥹���
-WinMain()
-RegisterWindow
-CreateWindow
-ShowWindow
-UpdateWindow
-GetMessage
-TranslateMessage
-DispatchMessage
-WndProc()
-switch(msg)
//-WM_CREAT
-WM_PAINT
*/

/*������
	-GetScrollRange		:	��ȡ�������ķ�Χ
	-SetScrollRange		��	���ù������ķ�Χ
	-GetScrollPos		:	��ȡ��������λ��
	-SetScrollPos		:	���ù�������λ��
		-LOWORD(wParam)	:	��16λ�����Ĳ���
		-HIWORD(wParam)	:	��16λ������λ��
	-InvalidateRect		:	ʹһ���������򣨿����������ͻ�����ʧЧ������һ���ػ����Ϣ����Ϣ����
	-ScrollWindow		:	�ػ�ʧЧ����ʧЧ����Ϊ����Ҫ��ʾ��������Ҫһ��LPCSCROLLINFO�ṹ�����
	-GetScrollInfo		:	����GetScrollRange��GetScrollPos�ĺ���
	-SetScrollInfo		:	����SetScrollRange��SetScrollPos�ĺ���
*/

/*���ڻ滭
	-SetPixel			:	���㣬��Ҫһ��RGB����Ϊ������RGB(r,g,b)������RGB��ɫ
	-SetPixelV			��	��SetPixelЧ�ʸߣ�����һ��bool���ͣ�ʧ�ܷ���0�����������豸��֧�ָú��� 
	-GetPixel			:	��ȡһ�����ص����ɫ
	-MoveToEx			:	ָ����ʼλ��
	-LineTo				��	ָ���յ�滭�߶�
	-GetCurrentPositionEx:	��ȡ��ǰλ������
*/
