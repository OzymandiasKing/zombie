#ifndef BIRD_H_
#define BIRD_H_

#include "dead.h"

class CBullet;

class CBird:public CDead
{
public:
	CBird();
	~CBird();
	void SetHearRect(RECT &rcHear);
	bool IsHearFire(CBullet *pBullet);
public: //virtual function
	virtual void Draw(HINSTANCE hInstance,HDC hdc);
	virtual void SetHuntRect(const RECT &rcClient);
	virtual bool Move(CPlayer &player,const RECT &rc);
protected: //virtual function
	virtual void DrawDiedZombie(HINSTANCE hInstance,HDC hdc); //���ƹҵ�ɥʬ
protected:
	RECT m_rcHear; //��������
	int m_iVertDirection; //��ֱ�����״̬
	int m_iChangeTimes; //�ı䷽��Ƶ��
	int m_iChangeRateCount; //�ı䷽��Ƶ�ʼ���
	int m_iChangeTimesCount; //�ı��������
	static bool m_bHearFire; //����ǹ��
};

#endif