#if false
#include <windows.h>
#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE prevInstance,LPSTR lpstr,int cmdLine)
{
	MessageBox(NULL, TEXT("WINDOWS!!!"), TEXT("Bingogo"), MB_OKCANCEL | MB_DEFBUTTON2 | MB_ICONINFORMATION);
}

#endif

/*先后所学过的API函数*/
/*

	-MessageBox			:	显示文本的窗口
	-GetMessage			:	获取系统消息
	-TranslateMessage	:	 
	-DispatchMessage	:
	-PostQuitMessage	:	退出消息

	-GetDC				:	获取设备环境
	-ReleaseDC			:	释放设备环境

	-DrawText			:	文本输出
	-TextOut			:	文本输出

	-BeginPaint			:	绘制窗口
	-EndPaint			:	停止绘制

	-GetClientRect		:	获取用户区
	-window大小改变时会返回一个WM_SIZE消息  /SCROLL.cpp演示
		-LOWORD(lParam)		:	获取用户区的宽度，Low Word，低16位
		-HIWORD(lParam)		:	获取用户区的高度，高16位
							
	-wsprintf			:	将字符串填入缓冲区，可能引发缓冲区溢出
	-lstrlen			:	获取字符串大小
	-StringCchPrintf	:	比wsprintf安全
	-StringCchLength	:	获取字符串大小

	-GetTextMetrics		:	获取文本尺寸并填充缓冲区,配合TEXTMETIRC结构体使用
	-GetSystemMetrics	:	获取系统所有图形项的尺寸信息，如鼠标、图标，返回值都是以像素为单位,目前有近100个参数
							例如GetSystemMetircs(SM_CXSCREEN)返回屏幕宽度,GetSystemMetircs(SM_CYSCREEN)返回屏幕高度
	
	-SetTextAlign		:	设置文本对齐方式，TA_LEFT,TA_RIGHT,TA_TOP
*/


/*
绘制一个窗口的简单过程
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

/*滚动条
	-GetScrollRange		:	获取滚动条的范围
	-SetScrollRange		：	设置滚动条的范围
	-GetScrollPos		:	获取滚动条的位置
	-SetScrollPos		:	设置滚动条的位置
		-LOWORD(wParam)	:	低16位，鼠标的操作
		-HIWORD(wParam)	:	高16位，鼠标的位置
	-InvalidateRect		:	使一个矩形区域（可以是整个客户区）失效，发送一个重绘的消息到消息队列
	-ScrollWindow		:	重绘失效区域，失效区域为滚动要显示的区域，需要一个LPCSCROLLINFO结构体参数
	-GetScrollInfo		:	代替GetScrollRange和GetScrollPos的函数
	-SetScrollInfo		:	代替SetScrollRange和SetScrollPos的函数
*/

/*窗口绘画
	-SetPixel			:	画点，需要一个RGB宏作为参数，RGB(r,g,b)，返回RGB颜色
	-SetPixelV			：	比SetPixel效率高，返回一个bool类型，失败返回0。不是所有设备都支持该函数 
	-GetPixel			:	获取一个像素点的颜色
	-MoveToEx			:	指定初始位置
	-LineTo				：	指定终点绘画线段
	-GetCurrentPositionEx:	获取当前位置坐标
*/
