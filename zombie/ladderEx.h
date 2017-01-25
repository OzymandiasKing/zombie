#pragma once

#include "SceneObject.h"

//����Ը�ǿ��ladder
class CLadderEx:public CSceneObject
{
	enum LADDER_STYLE
	{
		ls_normalL = 1, //������¥����ͨ����
		ls_normalR, //������¥����ͨ����
	};
public:
	CLadderEx(int width,int height);
	//////////////////////////////////////////////////////////////////////////
	void setLadderStyle(int eachWidth,int eachHeight,int style);
public: //virtual function
	virtual void Draw(HINSTANCE hInstance,HDC hdc);
	virtual int IsOnObject(POINT ptPos);
	virtual int OnObjectWhere(POINT &ptPos);
protected:
	int m_eachWidth; //ÿ�����
	int m_eachHeight; //ÿ���߶�
	int m_style; //���ӷ��
	int m_yOnWhere; //��������������ϵ�λ��������(����ڵĻ�)
};