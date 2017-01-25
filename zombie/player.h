#ifndef PLAYER_H_
#define PLAYER_H_

#include <windows.h>
#include <vector>

class CWeapon;
class CDead;
class CSceneObject;
enum _sound_PLAYER;

#define MAX_LOADSTRING 100

class CPlayer
{
	typedef std::vector<CSceneObject*>::iterator SCENEOBJITER;
public:
	CPlayer();
	~CPlayer();
	///////////////////////////////inline function
	POINT GetCurPos()const {return m_ptCurPos;}
	UINT GetVertDirection()const {return m_uiVertDirection;} //�����ֱ�˶�����
	UINT GetHoriDirection()const {return m_uiHoriDirection;} //���ˮƽ�˶�����
	void SetVertPos(int iy) {m_ptCurPos.y = iy;} //�������ֱ����
	void SetHoriPos(int ix) {m_ptCurPos.x = ix;} //�����ˮƽ����
	int GetWidth()const {return m_iWidth;}
	int GetHeight()const {return m_iHeight;}
	int GetHoriSpeed()const {return m_uiHorizontalCurSpeed;} //��ȡˮƽ�ٶ�
	int GetVertSpeed()const {return m_uiVerticalCurSpeed;} //��ȡ��ֱ�ٶ�
	bool IsDead()const {return (m_iBlood == 0);}
	void SetBloodOutFlag(bool flag) {m_bBloodOut = flag;}
	void BloodFull() {m_iBlood = 300;}
	/////////////////////////////////
	void Fire(); //��ǹ
	void ChangeWeapon(); //��q���л������е�����
	int GetWeaponShootRate()const;
	bool LoseBlood(int iHurt);
	bool IncreaseBlood(int iBlood);
	//����ƶ��������ӵ������������
	void Move(std::vector<CDead*> &vecDead,
		std::vector<CSceneObject*> &vecSceneObj); 
	void Jump(UINT uiInitSpeed); //����
	bool ChangeDirection(UINT uiDirection); //�ƶ�����ı�
	void DrawPerson(int ix,int iy,HDC hdc,HINSTANCE hInstance); //���������
	void DrawMessage(HINSTANCE hInstance,HDC hdc,POINT &ptPos); //���ƿͻ������Ͻ���ʾ��Ϣ
	void GetWeaponOnGround(CWeapon *&pWeapon); //��õ��ϵ�����
	void WeaponReload(); //���ӵ�
	void GetPlayerRect(RECT &rcRect);
	void GetUsefulObject(CSceneObject *pSceneObj); //������õ���Ʒ
	void dropObjFromBag(CSceneObject *pSceneObj); //�������ڵĶ�������
    BOOL IsUseObject(int iObjID,int index = -1); //�Ƿ����ʹ����Ʒ(����) index���ڲ���Կ��
	BOOL IsUseObject(CSceneObject *pObj); //�Ƿ����ʹ����Ʒ(����)
	int  getObjNumInBag(int iObjID); //������Ʒ����ĳ����Ʒ������
	void ClearObjBag(); //�����Ʒ���е���Ʒ
	void ReInitialize(); //���¿�ʼ��Ϸ��ʼ���������
	bool GetBulletSupply(int iWeaponKind,int iBulletNum); //����ӵ�����
	void RememberInitilaWeaponBag(); //����ʱ�����ʼʱ�̵�������
	void playSound(_sound_PLAYER sound);
	void getAllObjInBag(std::vector<CSceneObject*> &vecBagObj);
	void EquipHead(CSceneObject *pObj);
protected:
	void DrawHande(int ix,int iy,HDC hdc); //����
	void DrawHead(int ix,int iy,HDC hdc,HINSTANCE hInstance); //��ͷ
	void DrawBody(HINSTANCE hInstance,HDC hdc); //��������
//	void DrawWeapon(HINSTANCE,HDC,POINT,double,double); //��������
	void BloodOut(HINSTANCE hInstance,HDC hdc); //��Ѫ
	void InitWeaponBag(); //��ʼ��������
	void DrawObjEquipHead(HDC hdc,HINSTANCE hInstance); //����ͷ��װ��Ʒ
protected:
	TCHAR m_szPlayerName[MAX_LOADSTRING]; //�����
	int m_iBlood; //Ѫ��
	UINT m_uiLife; //����ֵ
	UINT m_uiHoriDirection; //ˮƽ�ƶ�����
	UINT m_uiVertDirection; //��ֱ�ƶ�����
	UINT m_uiHorizontalCurSpeed; //ˮƽ��ǰ�ٶ�
	UINT m_uiGravity; //��ֱ(����)���ٶ�
	UINT m_uiVerticalCurSpeed; //��ֱ��ǰ�ٶ�
	POINT m_ptCurPos; //��ǰλ��
	int m_iHeight; //���峤��
	int m_iWidth; //���
	int m_iWeaponSelection; //��ǰ����ѡ���ʶ
	bool m_bBloodOut; //��Ѫ��־(������ʱΪtrue)
	CWeapon* m_pWeaponBag[WEAPON_KIND_NUM]; //������
	CWeapon* m_pTemWeaponBag[WEAPON_KIND_NUM]; //��������ʱ��ʼ��������
	std::vector<CSceneObject*> m_vecObjBag; //��Ʒ��
	CSceneObject *m_pObjEquipHead; //��Ҫdelete(ָ����Ʒ���е���Ʒָ��)
	int m_iFace; //����
	_sound_PLAYER m_sound; //��ҷ�������
	POINT m_ptCurHandePos; //��ǰ�ֵ�λ��(��ͼ�ϵ��豸����)
	//��ptOrgΪԭ����߼��Ƕ�����ֵ,ptOrg = {m_ptCurPos.x,m_ptCurPos.y-m_iHeight/2-4};
	double m_dCurSinA; 
	//��ptOrgΪԭ����߼��Ƕ�����ֵ,ptOrg = {m_ptCurPos.x,m_ptCurPos.y-m_iHeight/2-4};
	double m_dCurCosA; 
};


#endif