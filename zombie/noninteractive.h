#pragma once

#include "multipleObj.h"

class CNonInteractiveObj:public CMultipleObj //�ǽ���ʽ��Ʒ��
{
public:
	CNonInteractiveObj(int width,int height);
public:
	virtual int IsOnObject(POINT ptPos);
	virtual int OnObjectWhere(POINT &ptPos);
};