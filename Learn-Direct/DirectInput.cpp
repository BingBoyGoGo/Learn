/*
LPDIRECTINPUT8 dinput; //Direct Object
LPDIRECTINPUTDEVICE8 dinputdev; //device object
HRESULT WINAPI DirectInputCreate8( //��ʼ��
	HINSTANCE hinst,	//��ǰ����ʵ�����
	DWORD dwVersion,	
	REFIID riidltf,		//��Ҫʹ�õ�DirectInput�汾�����ñ�ʶ��
	LPVOID *ppvOut,		//ָ����DirectInput����ָ���ָ��
	LPUNKNOWN punkOuter);//����NULL

HRESULT CreateDevice(	//�����µ�DirectInput�豸
	REFGUID rguid,		//GUID_SysKeyboard,GUID_SysMouse
	LPDIRECTINPUTDEVECE *lplpDirectInputDevice,	//����DirectInput�豸����ĵ�ַ���豸ָ��
	LPUNKNOWN pUnkOuter);	//����NULL
*/