#ifndef _selectPlayerBagBkgH_
#define _selectPlayerBagBkgH_

#include "SelectBKG.h"

class CPlayer;
class CSceneObject;
class CWeapon;

class CSelectPlayerBagBkg:public CSelectBKG
{
public:
	CSelectPlayerBagBkg(CPlayer *player = 0);
	virtual ~CSelectPlayerBagBkg();
	/////////////////////////////////////////////
	CSceneObject* DropObjFromPlayerBag();
	CSceneObject* EquipPlayer();
public: // virtual func
	void ShowSelectBKG(HINSTANCE hInstance,HDC hdc);
	void IsOnBtn(POINT &ptMouse);
	int IsClickOnBtn();
protected:
	void CenterObj(int index);
	bool IsObjEquipAble(); //��Ʒ�Ƿ����װ��
	bool IsSelAvailable();
protected:
	CPlayer *m_pPlayer; //��Ҫdelete
	std::vector<CSceneObject*> m_vecObjInBag; //��Ҫdelete
	CButtonBKG *m_pEquipBtn;
	CButtonBKG *m_pDropBtn;
	CButtonBKG *m_pExitBtn;
	CButtonBKGEx *m_pMoveBtn; //��������ƶ���ť
	CButtonBKGEx *m_pSelectedBtn; //ѡ�еİ�ť
	POINT m_ptKeyPoint[16]; //ÿ����Ʒ������϶���
	int m_moveBtnIndex; //�ƶ���ť��ǰ����
	int m_selBtnIndex; //ѡ�а�ť������
};

#endif