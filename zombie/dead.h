#ifndef DEAD_H_
#define DEAD_H_

class CPlayer;
class CBullet;

enum THING_TYPE
{
	tt_none,
	tt_sceneObj,
	tt_weapon,
	tt_dead
};

struct THING
{
	THING_TYPE tpye;
	void *pThing;
};

class CDead
{
public:
	CDead(
		int iId = 0,
		int iWidth = 0,
		int iHeigth = 0,
		int iSpeed = 0,
		int iHurt = 0,
		int iBlood = 0
		);
	virtual ~CDead();
public:
	void SetHeight(int iHeight) {m_iHeigth = iHeight;}
	void SetWidth(int iWidth) {m_iWidth = iWidth;}
	int GetDeadID()const {return m_iId;}
	bool IsSelfActionAble()const {return m_bSelfAction;}
	void SetAttackRect(const RECT &rcAttack); //���ù�������
	void SetCurPos(POINT ptPos);
	POINT GetCurPos()const;
	bool ChangeDirection(int ix); //�ı���ʬˮƽ����
	bool ChangeVertState(int iState); //�ı���ֱ�����ϵ�״̬
	BOOL IsInHuntRect(POINT ptpos); //����Ƿ���׷������
	BOOL IsInAttackRect(POINT ptPos); //����Ƿ��ڹ�������
	int GetWidth()const;
	int GetHeigth()const;
	int GetVertState()const;
	bool IsDied()const;
	bool IsBulletOn(CBullet *pBullet); //�ӵ�����
	void SetVertPos(int iy);
	void SetHoriPos(int ix);
	void PlayDeadHuntSound();//���Ź���׷��������
	void PlayDeadShootenSound(); //���Ź��ﱻ��������
protected:
	bool IsInMapRect(const RECT &rc); //�������Ƿ񳬳���ͼ����
	void HitBack(CBullet *pBullet); //�����ӵ���������
	void BloodOut(HINSTANCE hInstance,HDC hdc); //���г�Ѫ
public: //virtual function
	virtual void Draw(HINSTANCE hInstance,HDC hdc) = 0; //���ƽ�ʬ
	virtual void SetHuntRect(const RECT &rcClient) = 0; //����׷������
	virtual bool Move(CPlayer &player,const RECT &rc) = 0; //�ƶ� rcһ�㴫�뱾��ͼ��С
	virtual THING SelfAction(); //�Ե�ͼ�����ı���Զ��嶯��(�����֩����Բ���С֩��)
protected: //virtual function
	virtual void DrawDiedZombie(HINSTANCE hInstance,HDC hdc) = 0; //ɥʬ�ҵ�
	virtual bool LoseBlood(int iHurt); //���е�Ѫ(Ϊ�˲����������������麯��)
protected:
	int m_iId; //id
	int m_iSpeed; //ˮƽ����speed
	int m_iVertSpeed; //��ֱ�����ٶ�
	int m_iWidth; //width
	int m_iHeigth; //heigth
	int m_iDirection; //����
	int m_iBlood; //Ѫ��
	int m_iHurt; //������
	int m_iVertState; //��ֱ�����ϵ�״̬
	int m_iStepRate; //�Ų��ƶ�Ƶ��
	RECT m_rcHunt; //׷������Χ
	RECT m_rcAttack; //��������
	POINT m_ptCurPos; //position
	bool m_bBulletHitOn; //��ʶ�ӵ��Ƿ������ʬ
	bool m_bDied; //��־ɥʬ�Ƿ��Ѿ�����
	POINT m_ptBulletHitPos; //���������(m_bBulletHitOn == true)�ӵ���λ��
	int m_soundHuntId; //��������id
	int m_soundShootenId; //�����н���id
	bool m_bSelfAction; //�Ƿ����Զ�����Ϊ
	static int m_iGravity; //��ֱ(����)���ٶ�
};

#endif