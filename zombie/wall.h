#ifndef WALL_H_
#define WALL_H_

#include "SceneObject.h"

#define TYPE_HORI 1 //ˮƽ
#define TYPE_VERT 2 //��ֱ

class CWall:public CSceneObject
{
public:
	CWall();
	~CWall();
	void SetType(int iType) {m_iType = iType;}
public://virtual function
	void Draw(HINSTANCE hInstance,HDC hdc);
	int IsOnObject(POINT ptPos);
	bool IsBulletOn(CBullet *pBullet);
protected:
	int m_iType; //ǽ������
};

#endif