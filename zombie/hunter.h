#pragma once

#include "dead.h"

class CHunter:public CDead
{
public:
	CHunter();
	virtual ~CHunter();
public:
public: //virtual function
	virtual void Draw(HINSTANCE hInstance,HDC hdc);
	virtual void SetHuntRect(const RECT &rcClient);
protected: //virtual function
	virtual void DrawDiedZombie(HINSTANCE hInstance,HDC hdc); //���ƹҵ�ɥʬ
	virtual bool Move(CPlayer &player,const RECT &rc);
	virtual bool LoseBlood(int iHurt);
protected:
	int CheckDistance(const POINT &pos); //���͸�����ľ���,���ع������������ٶ�
	void Jump(int speed); //����
	void Action(const POINT *pos); //hunter��Ӧ
protected:
	int m_jumpTimes; //��Ծʱ����
	int m_cJump; //��Ծʱ��������
	static const int m_maxJumpSpeed;//��������ٶ�
};