#pragma once

#include "dead.h"
#include <vector>

class CSpider_b:public CDead
{
	enum CLIMB_STATE
	{
		cs_notOnWall,
		cs_onWall
	};
	typedef std::vector<RECT>::iterator BUIDING_ITER;
	typedef std::vector<RECT>::size_type BUIDING_ST;
public:
	CSpider_b();
	virtual ~CSpider_b();
public:
	void setBuidingRectClimbAble(const RECT &rc) {m_vecBuiding.push_back(rc);}//���ÿɸ��ŵĽ����ﷶΧ
public: //virtual function
	virtual void Draw(HINSTANCE hInstance,HDC hdc);
	virtual void SetHuntRect(const RECT &rcClient);
protected: //virtual function
	virtual void DrawDiedZombie(HINSTANCE hInstance,HDC hdc); //���ƹҵ�ɥʬ
	virtual bool Move(CPlayer &player,const RECT &rc);//rcһ�㴫����ǵ�ǰ��ͼ�Ĵ�С
	virtual bool LoseBlood(int iHurt);
	virtual THING SelfAction(); //����С֩��
protected:
	void ClimbStateChange(); //����״̬�����ı�
	void Jump(int speed); //��Ծ
	void Action(const POINT &pos); //spider��Ӧ
	void getDirection(const POINT &pos); //��ȡ֩�����˹����ķ���(ͼƬ̫��ֻ����÷��򣬲���תͼƬ)
	bool CheckBuidingArea(); //��m_cs == cs_notOnWall������ʱ��ʹ�ô˺������
	bool IsOutofCurBuidingArea(); //��m_cs == cs_onWallʱ��ʹ�ô˺������
protected:
	float m_sinA; //
	float m_cosA; //
	CLIMB_STATE m_cs; //����״̬
	std::vector<RECT> m_vecBuiding; //��¼�������еĽ����ﷶΧ
	BUIDING_ST m_curBuiding; //��¼֩�뵱ǰ���ŵĽ���(-1û�ڽ�����)
	int m_jumpTimes; //��Ծʱ����
	int m_cJump; //��Ծʱ��������
	int m_speedOnAir; //�ڿ��е�ˮƽ�ٶ�
	unsigned int m_bmpId; //ͼƬid
	bool m_bLoseReward; //������ʱ�����½�����Ʒ��ʶ
	static const int m_maxJumpSpeed;//��������ٶ�
};