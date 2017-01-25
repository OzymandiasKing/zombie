#ifndef STAGE_H_
#define STAGE_H_

#include <vector>

#define MAX_DOORNUM 30

class CMap;
class CDoor;
class CSceneObject;
class CWeapon;
class CDead;

class CStage
{
	typedef std::vector<CMap*>::iterator MAPITER;
	typedef std::vector<CDead*>::iterator DEADITER;
	typedef std::vector<CSceneObject*>::iterator SCENEOBJITER;
	typedef std::vector<CWeapon*>::iterator WEAPONITER;
	typedef int INT_PARAM;
public:
	CStage();
	~CStage();
	////////////////////////////inline function
	void StagePlus() {++m_iStage;}
	void StageReduce() {--m_iStage;}
	int GetStage()const {return m_iStage;}
	int GetCurMapIndex()const {return m_iCurIndex;}
	void SetCurMapIndex(int index) {m_iCurIndex = index;}
	int GetDoorIndexTable(int index)const {return m_iDoorIndexTable[index];}
	////////////////////////////
	RECT GetCurMapSize()const; //���ص�ǰ��ͼ��С
	CDoor* FoundRelativeDoor(int iDoorIndex); //���������ҵ���Ӧ��door����
	void SetCurMapNewWeapon(CWeapon *pOld,CWeapon *pNew); //һ���������ʰȡ����ʱ

	bool LoadMapInfo(); //��ʼ��ĳ��ͼ����������Ϣ(�������)
	void CreateWeaponOnGround(int id,POINT &ptPos); //������ͼ�ϵ�����
	void CreateSceneObject(int id,POINT &ptPos,int iWidth,int iHeigth,LPVOID pVoid); //�����ڱ�������
	void CreateZombie(int id,POINT &ptPos,int iWidth,int iHeigth,LPVOID pVoid); //����ɥʬ
	bool InitializeStage(CPlayer &player,POINT &ptClientOrgOnMap);

	void ClearAllDead(); //����˹ؿ����е�ͼ��������ʬ
	void ClearAllSceneObj(); //����˹ؿ����е�ͼ�����б�������
	void ClearAllWeapon(); //����˹ؿ����е�ͼ�����е��ϵ�����

	void GetCurMapDead(std::vector<CDead*> &vecDead); //������ǰ��ͼ����ʬ
	void GetCurMapSceneObj(std::vector<CSceneObject*> &vecSceneObj); //������ǰ��ͼ������
	void GetCurMapWeapon(std::vector<CWeapon*> &vecWeapon); //������ǰ��ͼ����

	void ReInitialStage();

	void EraseObjFromCurMap(CSceneObject *pObj); //ɾ��ָ����������
	void EraseWeaponFromCurMap(CWeapon *pWeapon); //ɾ��ָ������


	void AddObjToCurMap(CSceneObject *pObj); //���ָ������
	void AddWeaponToCurMap(CWeapon *pWeapon); //���ָ������
	void AddDeadToCurMap(CDead *pDead); //���ָ��ɥʬ
protected:
	void InitializeMap(int id,POINT &ptPos, //in
		int iWidth, int iHeigth, //in
		CPlayer &player, //out
		POINT &ptClientOrgOnMap /*out*/); //��ʼ��ĳ��ͼ(��С)
protected:
	int m_iStage; //��ǰ�ؿ�
	int m_iMapNodeNum; //���ؿ���ͼ�ڵ����
	int m_iCurIndex; //���ؿ���ǰ��ͼ����
	int m_iDoorNum; //�����ŵĸ���
	int m_iDoorIndexTable[MAX_DOORNUM]; //�����ŵ�������
	std::vector<CMap*> m_vecMap; //���ؿ���ͼ����
};

#endif