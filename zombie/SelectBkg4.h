#ifndef SELECTBKG4_H_
#define SELECTBKG4_H_

#include "SelectBKG.h"
#include <vector>

#define TOTAL_ITEM_NUM 21  //�ܹ�������Ϊ21

enum _choice_name;
class CPlayer;

class CGameMachineOperation // ��Ϸ��������
{
public:
	CGameMachineOperation():m_numMaxSeleted(2)
	{
		m_iCurItem = 0;
	}
	////////////////////////////////////////////
	bool Select(int index)
	{
		if (m_vecSeletedIndex.size() == m_numMaxSeleted)
			return false;

		m_vecSeletedIndex.push_back(index);
		return true;
	}
    ////////////////////////////////////////////////////////
	bool CancelSeleted(int index)
	{	
		for (std::vector<int>::iterator iter = m_vecSeletedIndex.begin();
			iter != m_vecSeletedIndex.end();++iter)
		{
			if (*iter == index)
			{
				m_vecSeletedIndex.erase(iter);
				return true;
			}
		}

		return false;
	}
	/////////////////////////////////////////////////////////
	void CanCelAll()
	{
		m_vecSeletedIndex.clear();
	}
	/////////////////////////////////////////////////////////
	int MoveToNextItem()
	{
		m_iCurItem = (m_iCurItem+1)%TOTAL_ITEM_NUM;
		return m_iCurItem;
	}
	/////////////////////////////////////////////////////////
	int getCurItem()const 
	{return m_iCurItem;}
	/////////////////////////////////////////////////////////
	bool Run()
	{
		if (m_vecSeletedIndex.size() == 0)
			return false;
		return true;
	}
	/////////////////////////////////////////////////////////
	bool IsWin(_choice_name cn)
	{
		for (int i = 0;i != m_vecSeletedIndex.size();++i)
		{
			if (m_vecSeletedIndex[i] == cn)
				return true;
		}
		return false;
	}
	/////////////////////////////////////////////////////////
protected:
	const int m_numMaxSeleted;
	int m_iCurItem;  //��ǰ��������ѡ�� < TOTAL_ITEM_NUM
	std::vector<int> m_vecSeletedIndex; //ѡ��İ�ť����0������
};

enum _choice_name
{
	_bar,
	_double_seven,
	_double_star,
	_double_watermelon,
	_double_bell,
	_mango,
	_orange,
	_apple
};

struct ROLLINFO
{
	ROLLINFO()
	{
		ptPos.x = ptPos.y = 0;
		name = _bar;
	}
	ROLLINFO(int x,int y,_choice_name cn)
	{
		ptPos.x = x;
		ptPos.y = y;
		name =  cn;
	}

	POINT ptPos;
	_choice_name name;
};

class CSelectBKG4:public CSelectBKG
{
	typedef std::vector<CButtonBKGEx*>::iterator BTNBKG_ITER;
public:
	CSelectBKG4(CPlayer *pPlayer = 0);
	~CSelectBKG4();
	//////////////////////////////////////
	void PlayWinSound();
	void PlayLoseSound();
	/////////////////////////////////////
public: // virtual func
	void ShowSelectBKG(HINSTANCE hInstance,HDC hdc);
	void IsOnBtn(POINT &ptMouse);
	int IsClickOnBtn();
	void PlaySelectBkgSound();
	///////////////////////////////////
	int GameMachineMoveToNextItem();  //���ع����������������0����
	////////////////////////////////////
protected:
	CPlayer *m_pPlayer; //����ʱ��Ҫdelete
	int m_numCoinInBag; //�������ӵ�е���Ϸ������
	bool m_bStart; //��ʶ��Ϸ�Ƿ�ʼ
	int m_iRollTotalTimes; //��������
	int m_cRollTimes; //�ѹ�����
	CButtonBKG *m_pExitBtn;  
	CButtonBKG *m_pStartBtn;
	CButtonBKG *m_pRollBtn; //������Ϸ�����İ�ť
	std::vector<CButtonBKGEx*> m_vecChoiceBtn; //ѡ�ť
	CGameMachineOperation m_gameMachineOper;
	ROLLINFO m_Rollinfo[TOTAL_ITEM_NUM];
};

#endif