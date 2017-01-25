#ifndef MAP_H_
#define MAP_H_

#include <vector>

class CDead;
class CSceneObject;
class CWeapon;

class CMap
{
	typedef std::vector<CDead*>::iterator DEADITER;
	typedef std::vector<CSceneObject*>::iterator SCENEOBJITER;
	typedef std::vector<CWeapon*>::iterator WEAPONITER;
public:
	CMap();
	~CMap();
	//////////////inline function
	int GetIndex()const {return m_iMapIndex;}
	void SetIndex(int Index) {m_iMapIndex = Index;}
	void IndexPlus() {++m_iMapIndex;}
	RECT GetSize()const {return m_rcMap;}
	////////////////////////////
	void ClearAllDead();
	void ClearAllSceneObj();
	void ClearAllWeapon();

	void InitializeMapSize(POINT &ptPos,int iWidth,int iHeigth);

	void AddDead(CDead* pDead);
	void AddSceneObj(CSceneObject* pSceneObj);
	void AddWeapon(CWeapon* pWeapon);

	void EraseObjFromMap(CSceneObject *pObj);
	void EraseWeaponFromMap(CWeapon *pWeapon);

	CDoor* FoundRelativeDoor(int iDoorIndex);

	void SetNewWeapon(CWeapon *pOldWeapon,CWeapon *pNewWeapon);

	void GetDead(std::vector<CDead*> &vecDead);
	void GetSceneObj(std::vector<CSceneObject*> &vecSceneObj);
	void GetWeapon(std::vector<CWeapon*> &vecWeapon);
protected:
	int m_iMapIndex; //��ͼ����0������ֵ
	RECT m_rcMap; //��ͼ��С.
	std::vector<CDead*> m_vecDead; //�˵�ͼ��ʬ����
	std::vector<CSceneObject*> m_vecSceneObj; //�˵�ͼ�����Ｏ��
	std::vector<CWeapon*> m_vecWeaponOnGround; //�˵�ͼ��������
};

#endif