/*
LPDIRECTINPUT8 dinput; //Direct Object
LPDIRECTINPUTDEVICE8 dinputdev; //device object
HRESULT WINAPI DirectInputCreate8( //初始化
	HINSTANCE hinst,	//当前程序实例句柄
	DWORD dwVersion,	
	REFIID riidltf,		//想要使用的DirectInput版本的引用标识符
	LPVOID *ppvOut,		//指向主DirectInput对象指针的指针
	LPUNKNOWN punkOuter);//总是NULL

HRESULT CreateDevice(	//创建新的DirectInput设备
	REFGUID rguid,		//GUID_SysKeyboard,GUID_SysMouse
	LPDIRECTINPUTDEVECE *lplpDirectInputDevice,	//接收DirectInput设备句柄的地址的设备指针
	LPUNKNOWN pUnkOuter);	//总是NULL
*/