#ifndef WEAPON_H_
#define WEAPON_H_

#include <vector>
using namespace std;

class CBullet;
class CDead;
class CSceneObject;

class CWeapon
{
public:
	CWeapon(int id = 0,
		int iKind = 0,
		int iWidth = 0,
		int iHeigth = 0,
		int iBulletNum = 0,
		int iRestBulletNum = 0,
		int iShootRate = 0
		);
	virtual ~CWeapon();
	/////////////////////inline function
	int GetWidth()const {return m_iWidth;}
	int GetHeigth()const {return m_iHeigth;}
	int GetWeaponID()const {return m_iWeaponId;}
	int GetShootRate()const {return m_iShootRate;}
	int GetBulletNum()const {return m_iBulletNum;}
	int GetRestBulletNum()const {return m_iRestBulletNum;}
	void SetPosOnGround(POINT &ptPos) {m_ptPosOnGround = ptPos;}
	POINT GetPosOnGround()const {return m_ptPosOnGround;}
	int GetKind()const {return m_iWeaponKind;}
	int GetWeaponHurt()const {return m_iHurt;}
	void GetWeaponName(TCHAR szName[]) {lstrcpy(szName,m_szWeaponName);}
	void GetBulletSupply(int iBulletNum) {m_iRestBulletNum += iBulletNum;}
	void SetBulletNum(int iNum) {m_iBulletNum = iNum;}
	/////////////////////
	void ClearBullet();
	bool IsExistBullet(); //������ӵ��Ƿ��ڴ���(�����������ʧ)
	void DrawBullet(HINSTANCE hInstance,HDC hdc); //���ӵ����ƶ��ӵ�
	void ShootOn(vector<CDead*> &vecDead,
		vector<CSceneObject*> &vecSceneObj);
	void PlayPullSound(); //������ǹ˨����
	void Reload(); //���ӵ�
protected:
	void PlayFireSound(); //����ǹ������
	void PlayNoBulletFireSound(); //����û���ӵ�ǹ������
	void PlayReloadSound(); //���Ż���������
public:
	virtual void Draw(HINSTANCE hInstance,
		HDC hdc,
		int iFace,
		POINT ptPos,
		double sinA,
		double cosA
		) = 0;
	//�����ӵ�(�����������ó�ʼλ��)
	virtual void Fire(const POINT &ptPos,double sinA,double cosA) = 0; 
	//�����ڵ��ϵ�����
	virtual void DrawOnGround(HINSTANCE hInstance,HDC hdc) = 0; 
protected:
	int m_iWeaponId; //����ID
	int m_iWeaponKind; //��������
	int m_iBulletNum; //ÿ�������е��ӵ�����
	int m_iRestBulletNum; //ʣ�µ��ӵ�(�����е�)
	int m_iBulletPerCartridge; //������ʱ���ӵ�
	int m_iWidth;
	int m_iHeigth;
	int m_iShootRate; //����Ƶ��(msΪ��λ)
	int m_iHurt; //ɱ����
	TCHAR m_szWeaponName[20]; //������
	POINT m_ptPosOnGround; //�ڵ���ʱ��λ��(������������ϵ�������Ҫ�ô�����)
	vector<CBullet*> m_vecBullet; //��������ӵ�
};

#endif