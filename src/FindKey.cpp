//----------------------------------------------------------------------//
// NyanFi																//
//  �L�[����															//
//----------------------------------------------------------------------//
#include <vcl.h>
#pragma hdrstop
#include "usr_key.h"
#include "Global.h"
#include "FindKey.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFindKeyDlg *FindKeyDlg = NULL;

//---------------------------------------------------------------------------
__fastcall TFindKeyDlg::TFindKeyDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFindKeyDlg::FormCreate(TObject *Sender)
{
	KeyList = new TStringList();
}
//---------------------------------------------------------------------------
void __fastcall TFindKeyDlg::FormShow(TObject *Sender)
{
	KeyStr = EmptyStr;
	KeyLabel->Caption = EmptyStr;
	DummyBtn->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFindKeyDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (ModalResult!=mrOk) KeyStr = EmptyStr;
	KeyList->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFindKeyDlg::FormDestroy(TObject *Sender)
{
	delete KeyList;
}

//---------------------------------------------------------------------------
void __fastcall TFindKeyDlg::WmMenuChar(TMessage &msg)
{
	if (msg.WParamHi==MF_POPUP)
		TForm::Dispatch(&msg);
	else
		msg.Result = (MNC_CLOSE << 16);		//�r�[�v������Ȃ��悤�ɂ���
}

//---------------------------------------------------------------------------
//2�X�g���[�N�J�n�L�[��?
//---------------------------------------------------------------------------
bool __fastcall TFindKeyDlg::IsFirstCmdKey(UnicodeString keystr)
{
	bool res = false;
	for (int i=0; i<KeyList->Count; i++) {
		UnicodeString fkey = KeyList->Names[i];
		if (contains_s(fkey, _T('~'))) {
			fkey = get_tkn_m(fkey, ':', '~');
			if (SameText(keystr, fkey)) { res = true; break; }
		}
	}

	if (res) KeyLabel->Caption = "2�X�g���[�N�L�[: " + KeyStr + "~";
	return res;
}

//---------------------------------------------------------------------------
//ENTER�ȊO�̃L�[����
//---------------------------------------------------------------------------
void __fastcall TFindKeyDlg::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	UnicodeString key_str = get_KeyStr(Key);
	if (!key_str.IsEmpty()) {
		if (KeyStr.IsEmpty()) {
			KeyStr = get_ShiftStr(Shift) + key_str;
			if (!IsFirstCmdKey(KeyStr)) ModalResult = mrOk;
		}
		else {
			KeyStr.cat_sprintf(_T("~%s"), key_str.c_str());
			ModalResult = mrOk;
		}
	}

	Key = 0;
}
//---------------------------------------------------------------------------
//ENTER�L�[�̏��� (DummyBtn �Ŏ󂯎��)
//---------------------------------------------------------------------------
void __fastcall TFindKeyDlg::DummyBtnClick(TObject *Sender)
{
	UnicodeString key_str = "ENTER";
	UnicodeString sft_str;
	if (is_KeyDown(VK_SHIFT))	sft_str += KeyStr_Shift;
	if (is_KeyDown(VK_CONTROL))	sft_str += KeyStr_Ctrl;
	if (is_KeyDown(VK_MENU))	sft_str += KeyStr_Alt;

	if (KeyStr.IsEmpty()) {
		KeyStr = sft_str + key_str;
		if (!IsFirstCmdKey(KeyStr)) ModalResult = mrOk;
	}
	else {
		KeyStr.cat_sprintf(_T("~%s"), key_str.c_str());
		ModalResult = mrOk;
	}
}

//---------------------------------------------------------------------------
void __fastcall TFindKeyDlg::CancelBtnClick(TObject *Sender)
{
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
