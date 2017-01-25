#ifndef BULLET_H_
#define BULLET_H_

class CBullet
{
public:
	CBullet(int id = 0,
		int iWidth = 0,
		int iHeigth = 0,
		int iSpeed = 0,
		int iRange = 0,
		int iHurt = 0
		);
	virtual ~CBullet();
	bool Move();
	void SetAngleValue(double sinA,double cosA);
	//inline function
	int GetID()const {return (int)m_uiBulletId;}
	void SetBulletPos(const POINT &ptPos) {m_ptCurPos = ptPos;}
	int GetHurt()const {return m_iHurt;}
	void SetHurt(int iHurt) {m_iHurt = iHurt;}
	POINT GetPosition()const {return m_ptCurPos;}
	void SetRange(int iRange) {m_iRange = iRange;}
	int GetCosA()const {return (int)m_dCosA;}
public: //virtual function
	virtual void Draw(HINSTANCE,HDC) = 0;
protected:
	UINT m_uiBulletId; //�ӵ�id(��ǹ��id��ͬ)
	int m_iWidth;
	int m_iHeigth;
	int m_iSpeed; //�ӵ��ٶ�
	int m_iHurt; //�˺�(�ӵ��Ĺ�����)
	int m_iRange; //�ӵ����
	POINT m_ptCurPos; //�ӵ�λ��
	double m_dSinA; //����
	double m_dCosA; //����
	int m_ixDistance;
	int m_iyDistance;
	//������������ͨ��m_iSpeed��������ֵ
	//����������ڼ��ټ������
	int m_ixIncrement; //ˮƽ��������
	int m_iyIncrement; //��ֱ��������
};

#endif