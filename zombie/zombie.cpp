// zombie.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "zombie.h"
#include <mmsystem.h>

#pragma comment(lib,"winmm")

#define MAX_LOADSTRING 100
#define WINDOW_CX 1025
#define WINDOW_CY 531

// ȫ�ֱ���:
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_ZOMBIE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_ZOMBIE));

	// ����Ϣѭ��:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
//  ע��:
//
//    ����ϣ��
//    �˴�������ӵ� Windows 95 �еġ�RegisterClassEx��
//    ����֮ǰ�� Win32 ϵͳ����ʱ������Ҫ�˺��������÷������ô˺���ʮ����Ҫ��
//    ����Ӧ�ó���Ϳ��Ի�ù�����
//    ����ʽ��ȷ�ġ�Сͼ�ꡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ZOMBIE));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   hWnd = CreateWindow(szWindowClass, szTitle, 
	   WS_OVERLAPPEDWINDOW & ~WS_MINIMIZEBOX & ~WS_MAXIMIZEBOX,
      100, 100, WINDOW_CX, WINDOW_CY, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	//int iCharCount;
	PAINTSTRUCT ps;
	HDC hdc;
	static CZombieView view(hInst,hWnd);
	static RECT rcClient;
	static DWORD dwFireLastTime = timeGetTime(); //���ڿ�����������Ƶ��
	static DWORD dwChangeWeaponTime = timeGetTime(); //���ڿ��ư���Ƶ��(q,g��)
	static DWORD dwReloadTime = timeGetTime(); //R��
	DWORD dwCurrentTime; //���ڿ�����������Ƶ��,����Ƶ��(q��)

	//ѡ�����
	if ( !view.m_iGameState )
	{
		POINT ptMouse;
		int elapse;

		switch (message)
		{
		case WM_SIZE:
			GetClientRect(hWnd,&rcClient);
			view.m_rcClient = rcClient;
			mciSendString(TEXT("open .\\res\\GameInitial.wav type MPEGVideo"),
				NULL,0,NULL);
			mciSendString(TEXT("play .\\res\\GameInitial.wav repeat"),NULL,0,NULL);
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			view.ShowSelectBKG(hdc);
			EndPaint(hWnd, &ps);
			return 0;
		case WM_MOUSEMOVE:
			ptMouse.x = LOWORD(lParam);
			ptMouse.y = HIWORD(lParam);

			view.IsMouseOnBtnBKG(ptMouse);
			InvalidateRect(hWnd,&rcClient,FALSE);
			return 0;
		case WM_LBUTTONDOWN:
			view.IsClickOnBtnBKG();
			InvalidateRect(hWnd,&rcClient,FALSE);
			return 0;
		case WM_TIMER:
			switch (wParam)
			{
			case TIMER_TVSNOWRATE:
				view.TvSnow();
				view.PlayTvSnowSound();
				InvalidateRect(hWnd,&rcClient,FALSE);
				break;
			case TIMER_GMAEMACHINEROLL:
				elapse = view.SelBkg4_MoveToNextItem();
				if (elapse)
					SetTimer(hWnd,TIMER_GMAEMACHINEROLL,elapse,NULL);
				else
					KillTimer(hWnd,TIMER_GMAEMACHINEROLL);
				InvalidateRect(hWnd,NULL,FALSE);
				break;
			default:
				break;
			}
			return 0;
		case WM_DESTROY:
			KillTimer(hWnd,GAME_UPDATE);
			PostQuitMessage(0);
			return 0;
		default:
			return DefWindowProc(hWnd,message,wParam,lParam);
		}
	}

	mciSendString(TEXT("close all"),NULL,0,NULL);

	//��Ϸ��ʼ
	switch (message)
	{
	case WM_SIZE:
		GetClientRect(hWnd,&rcClient);
		view.m_rcClient = rcClient;
		SetTimer(hWnd,GAME_UPDATE,20,NULL);
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		view.InitialBackGround(hdc);
		view.DrawPlayer();
		view.DrawZombie();
		view.DrawPlyerMessage();
		view.ShowMssg();
		view.MemToScreen(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		view.m_ptMousePosOnMap.x =
			LOWORD(lParam) + view.m_ptClientOrgOnMap.x;
		view.m_ptMousePosOnMap.y = 
			HIWORD(lParam) + view.m_ptClientOrgOnMap.y;

		view.IsMouseOnObject();
		break;
	case WM_LBUTTONDOWN:
		dwCurrentTime = timeGetTime();
		if ( int(dwCurrentTime - dwFireLastTime) > 
			view.GetPlayerWeaponShootRate() )
		{
			view.PlayerFire();
			dwFireLastTime = dwCurrentTime;
		}
		SetTimer(hWnd,TIMER_PLAYERFIRE,
			(UINT)view.GetPlayerWeaponShootRate(),NULL);
		break;
	case WM_LBUTTONUP:
		KillTimer(hWnd,TIMER_PLAYERFIRE);
		break;
	case WM_CHAR:
		switch (wParam)
		{
		case 'a':
		case 'A':
			view.ChangePlayerDirection(MOVE_LEFT);
			break;
		case 'd':
		case 'D':
			view.ChangePlayerDirection(MOVE_RIGHT);
			break;
		case 'q':
		case 'Q':
			dwCurrentTime = timeGetTime();
			if (int(dwCurrentTime - dwChangeWeaponTime) > 1000)
			{
				view.ChangePlayerWeapon();
				dwChangeWeaponTime = dwCurrentTime;
			}
			break;
		case 'g':
		case 'G':
			dwCurrentTime = timeGetTime();
			if (int(dwCurrentTime - dwChangeWeaponTime) > 1000)
			{
				view.GetWeaponOnGround();
				dwChangeWeaponTime = dwCurrentTime;
			}
			break;
		case 'r':
		case 'R':
			dwCurrentTime = timeGetTime();
			if (int(dwCurrentTime - dwReloadTime) > 2000)
			{
				view.PlayerWeaponReload();
				dwReloadTime = dwCurrentTime;

				//���ӵ�ʱ���ܷ��ӵ�
				dwFireLastTime = dwCurrentTime; 
				KillTimer(hWnd,TIMER_PLAYERFIRE);
			}
			break;
		case 'e':
		case 'E':
			view.SomethingHappen();
			break;
		case 'h':
		case 'H':
			view.OperateHelp();
			break;
		case 'b':
		case 'B':
			view.ShowPlayerBag();
			break;
		default:
			break;
		}
		break;
	case WM_KEYDOWN:
		if ((int)wParam == VK_SPACE)
			view.PlayerJump();
		else
			return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	case WM_KEYUP:
		switch ((int)wParam)
		{
		case 'a':
		case 'A':
		case 'd':
		case 'D':
			view.ChangePlayerDirection(MOVE_HORISTATIC);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_TIMER:
		switch (wParam)
		{
		case GAME_UPDATE:
			view.MovePlayer();
			InvalidateRect(hWnd,&rcClient,FALSE);
			break;
		case TIMER_PLAYERFIRE:
			view.PlayerFire();
			break;
		case TIMER_ENDSHOWMSSG:
			view.EndShowMssg();
			break;
		default:
			break;
		}
		break;
	case WM_DESTROY:
		KillTimer(hWnd,GAME_UPDATE);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


