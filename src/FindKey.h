//----------------------------------------------------------------------//
// NyanFi																//
//  �L�[����															//
//----------------------------------------------------------------------//
#ifndef FindKeyH
#define FindKeyH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>

//---------------------------------------------------------------------------
class TFindKeyDlg : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TButton *DummyBtn;
	TLabel *KeyLabel;
	TLabel *Label1;
	TSpeedButton *CancelBtn;

	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall WmMenuChar(TMessage &msg);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall DummyBtnClick(TObject *Sender);
	void __fastcall CancelBtnClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);

private:	// ���[�U�[�錾
	bool __fastcall IsFirstCmdKey(UnicodeString keystr);

public:		// ���[�U�[�錾
	TStringList *KeyList;
	UnicodeString KeyStr;

	__fastcall TFindKeyDlg(TComponent* Owner);

	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_MENUCHAR,	TMessage,	WmMenuChar)
	END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TFindKeyDlg *FindKeyDlg;
//---------------------------------------------------------------------------
#endif