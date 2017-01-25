#ifndef VIEW_H_
#define VIEW_H_

#include "player.h"
#include "stage.h"
#include <vector>
using namespace std;

class CDead;
class CSceneObject;
class CWeapon;
class CSelectBKG;

class CZombieView
{
	typedef vector<CSceneObject*>::iterator SCENEOBJITER;
	typedef vector<CSelectBKG*>::iterator SELECTBKGITER;
public: //view function
	CZombieView();
	CZombieView(HINSTANCE hInstance,HWND hWnd);
	~CZombieView();
	void SetMemDc(HDC hdc);
	void InitialBackGround(HDC hdc);
	void MemToScreen(HDC hdc);
	void SetInitDataFlag(bool bFlag); //
	bool InitializeBKGObject(); //��ʼ�����ж�������
	int PassStage(); //
	void SomethingHappen(); //����E
	void ShowMssg(); //��ʾ��Ϸ�е���ʾ��Ϣ
	void EndShowMssg(); //ֹͣ��ʾ��Ϸ�е���ʾ��Ϣ
	void SetMssg(int iMssg) {m_iMssg = iMssg;} //������ʾ����Ϣ����
	void TvSnow(); //���ӱ���ѩ������
	void PlayTvSnowSound(); //���ŵ��ӻ�ѩ������
	void OperateHelp(); //��h����������˵��
protected: //view function
	bool MoveHoriBkg(const POINT &ptPos); //����ˮƽ�ƶ�
	bool MoveVertBkg(const POINT &ptPos); //������ֱ�ƶ�
	//void SetPassStageRect(); //���ù�������
public: //BKG function
	void InitialSelectBKG();
	void ShowSelectBKG(HDC hdc); //
	void IsMouseOnBtnBKG(POINT &ptMouse); //����Ƿ��ڰ�����(WM_MOUSEMOVE)
	void IsClickOnBtnBKG(); //
//	void ClearBKG();
public: //SelectBkg4 Function
	int SelBkg4_MoveToNextItem();
protected:////////////////// weapon function
	void DrawWeaponOnGround(); //���Ƶ��ϵ�����
	void ClearWeaponOnGround(); //������ϵ���������
public: /////////////player function
	void DrawPlayer();
	POINT GetPlayerPos()const;
	bool ChangePlayerDirection(UINT uiDirection); //�ƶ�����ı�
	void MovePlayer(); //
	void PlayerJump(); //�������
	void PlayerFire(); //������
	int GetPlayerWeaponShootRate()const;
	void DrawPlyerMessage();
	void ChangePlayerWeapon();
	void GetWeaponOnGround();
	void PlayerWeaponReload();
	void ShowPlayerBag(); //��ʾ��ұ��������Ʒ ��B
protected:///////////////player function
	int IsPlayerOnGround(); //�������Ƿ��ڵ���(���ڿ���)
protected: /////////////// sceneobject function
	void DrawSceneObject();
	void ClearSceneObject(); //������б�������
	void IsObjectOnObject(); //�ɶ������Ƿ���������
public: /////////////// sceneobject function
	void IsMouseOnObject(); //����Ƿ���������
public: //zombie function
	void DrawZombie();
	void ClearZombie(); //�������ɥʬ
protected: //zombie function
	int IsDeadOnGround(CDead *pDead); //�����ʬ�Ƿ��ڵ���(���ڿ���)
protected:
	int m_iMssg; //��Ϸ����ʾ��ʾ��Ϣ������
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	HDC m_hMemDc;
	HBITMAP m_hBmpBKG; 
	bool m_bIsInitData; //��������Ƿ��Ѿ���ʼ��
	RECT m_rcPassStage; //��������
	RECT m_rcMap; //��ͼ��С
	CPlayer m_Player; //���
	CStage m_Stage; //�ؿ�
	CSelectBKG *m_pSelectBKG; //ѡ�񱳾�
	vector<CSceneObject*> m_vecDynamicObj; //�ɶ�������
	vector<CSceneObject*> m_vecSceneObj; //�������弯��
	vector<CDead*> m_vecDead; //��ʬ����
	vector<CWeapon*> m_vecWeaponOnGround; //���ϵ���������
	CSceneObject *m_pTemSceneObj;
public:
	POINT m_ptClientOrgOnMap; //�ͻ���ԭ��(����)�ڵ�ͼ�϶�Ӧ�ĵ�
	POINT m_ptMousePosOnMap; //����ڵ�ͼ�ϵĵ�
	RECT m_rcClient; //��Ļ��ʾ�ͻ�����С(���ǵ�ͼ��С)
	int m_iGameState; //��Ϸ״̬
};

#endif