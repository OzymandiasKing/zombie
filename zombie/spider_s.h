#pragma once

#include "dead.h"

class CSpider_s:public CDead
{
public:
	CSpider_s();
	virtual ~CSpider_s();
public:
	void setMoveAbleRect(const RECT &rc) {m_rcMove = rc;}
public: //virtual function
	virtual void Draw(HINSTANCE hInstance,HDC hdc);
	virtual void SetHuntRect(const RECT &rcClient);
protected: //virtual function
	virtual void DrawDiedZombie(HINSTANCE hInstance,HDC hdc); //���ƹҵ�ɥʬ
	virtual bool Move(CPlayer &player,const RECT &rc);//rcһ�㴫����ǵ�ǰ��ͼ�Ĵ�С
	virtual bool LoseBlood(int iHurt);
protected:
	void Action(); //spider��Ӧ
	void getDirection(const POINT &pos); //��ȡ֩�����˹����ķ���(�Ա���תλͼ)
	bool IsInMoveAbleRect(const POINT &pos)const {return (bool)PtInRect(&m_rcMove,pos);} //�Ƿ���֩��Ŀ��ƶ���
protected:
	RECT m_rcMove; //ֻ���ڴ������ƶ�
	float m_sinA; //
	float m_cosA; //
};