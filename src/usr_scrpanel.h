//----------------------------------------------------------------------//
// �V���v���X�N���[���o�[�E�p�l��										//
//																		//
//  TListBox�ATStringGrid�ATScrollBar �̉��ꂩ�Ɋ֘A�t���\			//
//----------------------------------------------------------------------//
#ifndef UsrScrollPanelH
#define UsrScrollPanelH

//---------------------------------------------------------------------------
#include <Vcl.CheckLst.hpp>
#include <Vcl.Grids.hpp>

//---------------------------------------------------------------------------
//Flag
#define USCRPNL_FLAG_FL		0x0001	//�t�@�C�����X�g
#define USCRPNL_FLAG_GL		0x0002	//�ꗗ���X�g
#define USCRPNL_FLAG_TV		0x0004	//�e�L�X�g�r���A�[

#define USCRPNL_FLAG_P_WP	0x0020	//�e�p�l���� WindowProc ����ւ�
#define USCRPNL_FLAG_L_WP	0x0040	//���X�g�{�b�N�X�� WindowProc ����ւ�
#define USCRPNL_FLAG_G_WP	0x0080	//�O���b�h�� WindowProc ����ւ�
#define USCRPNL_FLAG_HS		0x0100	//�����X�N���[���o�[�t(ListBox or Grid)

//---------------------------------------------------------------------------
#define WM_NYANFI_USCROLL	(WM_APP + 500)	//�t�@�C�����X�g�̃m�u�����p

//---------------------------------------------------------------------------
class UsrScrollPanel
{
private:
	TPanel     *ScrPanelV;			//�����X�N���[���p�l��
	TPaintBox  *ScrPaintBoxV;		//�`��̈�

	TPanel     *ScrPanelH;			//�����X�N���[���p�l��
	TPaintBox  *ScrPaintBoxH;		//�`��̈�

	TRect ScrKnobRectV;				//�m�u�̒����`
	TRect ScrKnobRectH;
	int   ScrKnobMaxY;				//�ő�m�u�ʒu
	int   ScrKnobMaxX;

	bool  ScrCatchKnob;				//�m�u������ł���
	int   ScrCatchYp;
	int   ScrCatchXp;
	int   ScrPage;

	TWndMethod org_ParentPanelWndProc;
	void __fastcall ParentPanelWndProc(TMessage &msg);

	TWndMethod org_AssoListWndProc;
	void __fastcall AssoListWndProc(TMessage &msg);

	TWndMethod org_AssoChkListWndProc;
	void __fastcall AssoChkListWndProc(TMessage &msg);

	TWndMethod org_AssoGridWndProc;
	void __fastcall AssoGridWndProc(TMessage &msg);

	TWndMethod org_ScrPanelVWndProc;
	void __fastcall ScrPanelVWndProc(TMessage &msg);

	TWndMethod org_ScrPanelHWndProc;
	void __fastcall ScrPanelHWndProc(TMessage &msg);

	void __fastcall ScrPaintBoxPaint(TObject *Sender);
	int  __fastcall GetKnobPosH();

	int  __fastcall get_GridTotalWidth();
	void __fastcall set_GridLefCol(int pos);
	int  __fastcall get_GridTotalHeight();
	void __fastcall set_GridTopRow(int pos);

	void __fastcall ScrPaintBoxMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
	void __fastcall ScrPaintBoxMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall ScrPaintBoxMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);

public:
	TPanel			*ParentPanel;		//�e�p�l��
	TListBox		*AssoListBox;		//�֘A���X�g�{�b�N�X
	TCheckListBox	*AssoChkListBox;	//�֘A�`�F�b�N���X�g�{�b�N�X
	TStringGrid		*AssoStrGrid;		//�֘A�O���b�h
	TScrollBar		*AssoScrollBar;		//�֘A�X�N���[���o�[

	int Flag;							//�ݒ�t���O
	int KnobWidth;

	Graphics::TBitmap *KnobImgBuffV;	//�����m�u�摜
	Graphics::TBitmap *KnobImgBuffH;	//�����m�u�摜

	TColor Color;						//�w�i�F
	TColor KnobColor;					//�m�u�F
	TColor KnobBdrColor;				//�m�u�֊s�F
	TColor HitLineColor;				//�q�b�g�s�F
	int  HitLineAlpha;					//�q�b�g�s�A���t�@

	bool ListCsrVisible;				//���X�g�{�b�N�X�̃J�[�\������ɉ��̈��

	TMouseEvent OnRButtonUp;			//�E�N���b�N�C�x���g

	bool FVisible;
	void __fastcall SetVisible(bool Value)
	{
		FVisible = Value;
		if (!FVisible) {
			ScrPanelV->Visible = VisibleV = false;
			if (ScrPanelH) ScrPanelH->Visible = VisibleH = false;
		}
	}
	__property bool Visible = {read = FVisible,  write = SetVisible};

	bool VisibleV, VisibleH;			//�X�N���[���o�[�̕\�����

	TStringList *HitLines;				//�������ʈʒu���X�g

	UsrScrollPanel(TPanel *pp, TListBox *lp,      int flag);
	UsrScrollPanel(TPanel *pp, TCheckListBox *lp, int flag);
	UsrScrollPanel(TPanel *pp, TStringGrid *gp,   int flag);
	UsrScrollPanel(TPanel *pp, TScrollBar *sp,    int flag);
	~UsrScrollPanel();

	void __fastcall InitializePanel();
	void __fastcall UpdateKnob();
	void __fastcall Repaint();

	void __fastcall SetRBCornerPanel(TPanel *pp);

	bool __fastcall KeyWordChanged(UnicodeString kwd, int max_cnt, bool case_sw = false, int code_page = 0);
	void __fastcall AddHitLine(int n);
};
//---------------------------------------------------------------------------
#endif