#ifndef SELECT_BKG_H
#define SELECT_BKG_H

/************************************************************************/
/* ѡ��������                                                                
/************************************************************************/

class CSelectBKG
{
public:
	CSelectBKG(int id = 0,
		int iWidth = 0,
		int iHeight = 0);
	virtual ~CSelectBKG();
	/////////////////inline function
	static void SetClientSize(RECT &rcClient) {m_rcClient = rcClient;}
	void SetOrgPoint(POINT &ptPos) {m_ptOrgPos = ptPos;}
	POINT getOrgPoint()const {return m_ptOrgPos;}
	void SetBKGId(int id) {m_iBKGCurId = id;}
	int GetBKGId()const {return m_iBKGCurId;}
	int GetWidth()const {return m_iBKGWidth;}
	int GetHeight()const {return m_iBKGHeight;}
	///////////////////////////////
	void SrcInvert(HDC srcDc);                 //��ָ������ɫ
	void LoadBKG(HINSTANCE hInstance,HDC hdc);
	void BltBKG(HDC hdc,int bFlag);
public: //virtual func
	virtual void ShowSelectBKG(HINSTANCE hInstance,HDC hdc) = 0;
	virtual void IsOnBtn(POINT &ptMouse) = 0;
	virtual int IsClickOnBtn() = 0;
	virtual void PlaySelectBkgSound();//����ѡ��������ʱ������
protected:
	int m_iBKGCurId; //����ͼƬid
	int m_iBKGWidth; //����ͼƬ���
	int m_iBKGHeight; //����ͼƬ�߶�
	POINT m_ptOrgPos; //ͼƬ���ϵ�λ��
	HDC m_hMemDc; //�ڴ�dc
	HBITMAP m_hBitmap; //λͼ���
	static RECT m_rcClient; //�ͻ�����С
};

#endif