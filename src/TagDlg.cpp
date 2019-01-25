//----------------------------------------------------------------------//
// NyanFi																//
//  �^�O�ݒ�/����														//
//----------------------------------------------------------------------//
#include <vcl.h>
#pragma hdrstop
#include <algorithm>
#include <memory>
#include <RegularExpressions.hpp>
#include "UserFunc.h"
#include "UserMdl.h"
#include "Global.h"
#include "InpExDlg.h"
#include "TagDlg.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTagManDlg *TagManDlg = NULL;

//---------------------------------------------------------------------------
__fastcall TTagManDlg::TTagManDlg(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::FormCreate(TObject *Sender)
{
	MaxTagWidth = 0;
	InhEdit = false;

	ListScrPanel = new UsrScrollPanel(ListPanel, TagCheckListBox, USCRPNL_FLAG_P_WP | USCRPNL_FLAG_L_WP);

	SwatchPanel = new UsrSwatchPanel(this);
	SwatchPanel->Parent = this;
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::FormShow(TObject *Sender)
{
	Initialized = false;

	Constraints->MinWidth  = 0;

	IniFile->LoadPosInfo(this, DialogCenter);

	SwatchPanel->SetPanelSize16x8(15);
	SwatchPanel->Left = ClientWidth  - SwatchPanel->Width;
	SwatchPanel->Top  = ClientHeight - SwatchPanel->Height;

	RevColCheckBox->Checked = RevTagCololr;

	set_StdListBox(TagCheckListBox);
	if (RevTagCololr) TagCheckListBox->ItemHeight = TagCheckListBox->ItemHeight + ScaledInt(2);
	MaxTagWidth = usr_TAG->IniCheckList(TagCheckListBox) + ScaledInt(32);

	set_UsrScrPanel(ListScrPanel);
	ListScrPanel->UpdateKnob();

	set_ButtonMark(HideOptBtn,  UBMK_BDOWN);
	set_ButtonMark(ShowOptBtn,  UBMK_BUP);
	HideOptBtn->Hint = LoadUsrMsg(USTR_HideOptPanel);
	ShowOptBtn->Hint = LoadUsrMsg(USTR_ShowOptPanel);
	TagEdit->Hint	 = LoadUsrMsg(USTR_HintMltSepSC);

	FindOptPanel->Visible = false;
	OptPanel->Height	  = FindOptPanel->Height + InpOptPanel->Height;

	if (SameText(CmdStr, "FindTag")) {
		HideCheckBox->Checked	 = IniFile->ReadBoolGen(_T("FindTagDlgHide"));
		FindOptPanel->Visible	 = true;
		AndCheckBox->Checked	 = IniFile->ReadBoolGen(_T("FindTagDlgAnd"),	true);
		ResLinkCheckBox->Visible = true;
		ResLinkCheckBox->Checked = IniFile->ReadBoolGen(_T("FindTagResLink"));
		SelMaskCheckBox->Visible = false;
		OptPanel->Visible		 = IniFile->ReadBoolGen(_T("FindTagShowOpt"),	true);
		SetColPanel->Visible	 = OptPanel->Visible;
		Caption = UnicodeString().cat_sprintf(_T("�^�O���� (%s)"), AndCheckBox->Checked? _T("AND") : _T("OR"));
	}
	else if (SameText(CmdStr, "SetTag")) {
		set_FormTitle(this, _T("�^�O�̐ݒ�"));
		HideCheckBox->Checked = IniFile->ReadBoolGen(_T("SetTagDlgHide"));
		OptPanel->Height	  = InpOptPanel->Height;
		OptPanel->Visible	  = IniFile->ReadBoolGen(_T("SetTagShowOpt"),	true);
		SetColPanel->Visible  = OptPanel->Visible;

		TStringDynArray org_lst = split_strings_semicolon(TagEdit->Text);
		for (int i=0; i<org_lst.Length; i++) {
			int idx = TagCheckListBox->Items->IndexOf(org_lst[i]);
			if (idx!=-1) TagCheckListBox->Checked[idx] = true;
		}
	}
	else if (SameText(CmdStr, "AddTag")) {
		set_FormTitle(this, _T("�^�O�̒ǉ�"));
		HideCheckBox->Checked = IniFile->ReadBoolGen(_T("AddTagDlgHide"));
		OptPanel->Height	  = InpOptPanel->Height;
		OptPanel->Visible	  = IniFile->ReadBoolGen(_T("AddTagShowOpt"),	true);
		SetColPanel->Visible  = OptPanel->Visible;
	}
	else if (SameText(CmdStr, "TagSelect")) {
		set_FormTitle(this, _T("�^�O�I��"));
		HideCheckBox->Checked	 = IniFile->ReadBoolGen(_T("TagSelDlgHide"));
		FindOptPanel->Visible	 = true;
		AndCheckBox->Checked	 = IniFile->ReadBoolGen(_T("TagSelDlgAnd"),	true);
		SelMaskCheckBox->Visible = (ScrMode==SCMD_FLIST);
		SelMaskCheckBox->Checked = IniFile->ReadBoolGen(_T("TagSelSelMask"));
		ResLinkCheckBox->Visible = false;
		OptPanel->Visible		 = IniFile->ReadBoolGen(_T("TagSelShowOpt"),	true);
		SetColPanel->Visible	 = OptPanel->Visible;
	}
	BlankPanel->Visible = !OptPanel->Visible;

	ShowTagCountAction->Checked = IniFile->ReadBoolGen(_T("TagDlgShowCount"));

	SetOptBtn();

	InpPanel->Visible = !HideCheckBox->Checked;

	::PostMessage(Handle, WM_FORM_SHOWED, 0, 0);
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::WmFormShowed(TMessage &msg)
{
	if (ShowTagCountAction->Checked) {
		Repaint();
		usr_TAG->CountTags(TagCheckListBox);
	}

	SetCtrlFocus();
	Initialized = true;
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::FormClose(TObject *Sender, TCloseAction &Action)
{
	CloseIME(Handle);

	IniFile->SavePosInfo(this);

	if (SameText(CmdStr, "FindTag")) {
		IniFile->WriteBoolGen(_T("FindTagDlgHide"),		HideCheckBox);
		IniFile->WriteBoolGen(_T("FindTagDlgAnd"),		AndCheckBox);
		IniFile->WriteBoolGen(_T("FindTagResLink"),		ResLinkCheckBox);
		IniFile->WriteBoolGen(_T("FindTagShowOpt"),		OptPanel->Visible);
	}
	else if (SameText(CmdStr, "SetTag")) {
		IniFile->WriteBoolGen(_T("SetTagDlgHide"),		HideCheckBox);
		IniFile->WriteBoolGen(_T("SetTagShowOpt"),		OptPanel->Visible);
	}
	else if (SameText(CmdStr, "AddTag")) {
		IniFile->WriteBoolGen(_T("AddTagDlgHide"),		HideCheckBox);
		IniFile->WriteBoolGen(_T("AddTagShowOpt"),		OptPanel->Visible);
	}
	else if (SameText(CmdStr, "TagSelect")) {
		IniFile->WriteBoolGen(_T("TagSelDlgHide"),		HideCheckBox);
		IniFile->WriteBoolGen(_T("TagSelDlgAnd"),		AndCheckBox);
		IniFile->WriteBoolGen(_T("TagSelSelMask"),		SelMaskCheckBox);
		IniFile->WriteBoolGen(_T("TagSelShowOpt"),		OptPanel->Visible);
	}

	IniFile->WriteBoolGen(_T("TagDlgShowCount"),	ShowTagCountAction->Checked);

	Initialized = false;
	CmdStr = EmptyStr;
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::FormDestroy(TObject *Sender)
{
	delete ListScrPanel;
}

//---------------------------------------------------------------------------
void __fastcall TTagManDlg::ListPanelResize(TObject *Sender)
{
	ListScrPanel->UpdateKnob();
	SetOptBtn();
}

//---------------------------------------------------------------------------
void __fastcall TTagManDlg::SetCtrlFocus()
{
	if (InpPanel->Visible) {
		TagEdit->SetFocus();
		TagEdit->SelStart = TagEdit->Text.Length();
	}
	else {
		TagCheckListBox->SetFocus();
		if (TagCheckListBox->Count>0) {
			if (TagCheckListBox->ItemIndex==-1) TagCheckListBox->ItemIndex = 0;
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TTagManDlg::HideCheckBoxClick(TObject *Sender)
{
	InpPanel->Visible = !HideCheckBox->Checked;
	SetCtrlFocus();
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::OptCheckBoxClick(TObject *Sender)
{
	if (SameText(CmdStr, "FindTag")) {
		Caption = UnicodeString().cat_sprintf(_T("�^�O���� (%s)"), AndCheckBox->Checked? _T("AND") : _T("OR"));
	}

	SetCtrlFocus();
}

//---------------------------------------------------------------------------
//�I�v�V�����̊J��
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::SetOptBtn()
{
	if (BlankPanel->Visible) {
		if (ScrBarStyle==0)
			set_ControlRBCorner(TagCheckListBox, BlankPanel);
		else
			ListScrPanel->SetRBCornerPanel(BlankPanel);
	}

}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::ChgOptBtnClick(TObject *Sender)
{
	OptPanel->Visible	  = !OptPanel->Visible;

	BlankPanel->Visible   = !OptPanel->Visible;
	SetColPanel->Visible  = OptPanel->Visible;

	Constraints->MinWidth = OptPanel->Visible? 320 : 160;

	SetOptBtn();
}

//---------------------------------------------------------------------------
//���͗��ł̑���
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TagEditChange(TObject *Sender)
{
	if (!Initialized || InhEdit) return;

	TStringDynArray org_lst = split_strings_semicolon(TagEdit->Text);
	std::unique_ptr<TStringList> lst(new TStringList());
	for (int i=0; i<org_lst.Length; i++)
		if (!org_lst[i].IsEmpty()) lst->Add(org_lst[i]);

	TCheckListBox *lp = TagCheckListBox;
	for (int i=0; i<lp->Count; i++) {
		lp->Checked[i] = (lst->IndexOf(lp->Items->Strings[i])!=-1);
		if (lp->Checked[i]) lp->ItemIndex = i;
	}

	TagCheckListBoxClickCheck(NULL);
	TagCheckListBox->Invalidate();

	if (InpPanel->Visible) {
		TagEdit->SetFocus();
		TagEdit->SelStart = TagEdit->Text.Length();
	}
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TagEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	UnicodeString KeyStr = get_KeyStr(Key, Shift);
	if (KeyStr.IsEmpty()) return;

	TCheckListBox *lp = TagCheckListBox;
	if (contained_wd_i(KeysStr_ToList, KeyStr)) {
		if (lp->Count>0) {
			lp->SetFocus();
			if (lp->ItemIndex==-1) lp->ItemIndex = 0;
		}
	}
	else return;
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TagEditKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (is_KeyPress_CtrlNotCV(Key) || Key==VK_RETURN || Key==VK_ESCAPE) Key = 0;
}

//---------------------------------------------------------------------------
//�^�O�ꗗ�ł̑���
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TagCheckListBoxClickCheck(TObject *Sender)
{
	if (!Initialized) return;

	UnicodeString lbuf = usr_TAG->CheckToTags(TagCheckListBox, TagEdit->Text);
	if (!SameStr(lbuf, TagEdit->Text)) {
		InhEdit = true;
		TagEdit->Text = lbuf;
		InhEdit = false;
	}
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TagCheckListBoxClick(TObject *Sender)
{
	TagCheckListBox->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TagCheckListBoxKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	UnicodeString KeyStr = get_KeyStr(Key, Shift);
	UnicodeString cmd_F  = Key_to_CmdF(KeyStr);

	TCheckListBox *lp = TagCheckListBox;

	if		(contained_wd_i(KeysStr_CsrDown, KeyStr))	Key = VK_DOWN;
	else if (contained_wd_i(KeysStr_CsrUp, KeyStr))		Key = VK_UP;
	//�^�O�̉���
	else if (USAME_TI(cmd_F, "RenameDlg")) {
		RenTagAction->Execute();
	}
	//�^�O�̍폜
	else if (USAME_TI(cmd_F, "Delete")) {
		DelTagAction->Execute();
	}
	//�S�`�F�b�N/����
	else if (lp->Count>0 && StartsText("SelAll", cmd_F)) {
		int cnt = 0;
		for (int i=0; i<lp->Count; i++) if (lp->Checked[i]) cnt++;
		lp->CheckAll((cnt>0)? cbUnchecked : cbChecked);
		lp->Invalidate();
		TagCheckListBoxClickCheck(NULL);
	}
	//�������T�[�`
	else if (is_IniSeaKey(KeyStr)) {
		int idx = lp->ItemIndex;
		int idx0=-1, idx1=-1;
		TRegExOptions opt; opt << roIgnoreCase;
		for (int i=0; i<lp->Count && idx1==-1; i++) {
			if (i<=idx && idx0!=-1) continue;
			if (TRegEx::IsMatch(lp->Items->Strings[i], KeyStr, opt)) ((i<=idx)? idx0 : idx1) = i;
		}
		idx = (idx1!=-1)? idx1 : idx0;
		if (idx!=-1) {
			lp->ItemIndex = idx;
			lp->Invalidate();
		}
	}

	if (!is_DialogKey(Key)) Key = 0;
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TagCheckListBoxKeyPress(TObject *Sender, System::WideChar &Key)
{
	//�C���N�������^���T�[�`�����
	Key = 0;
}

//---------------------------------------------------------------------------
//�ꗗ�̕`��
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TagCheckListBoxDrawItem(TWinControl *Control, int Index,
          TRect &Rect, TOwnerDrawState State)
{
	TCheckListBox *lp = (TCheckListBox*)Control;
	TCanvas  *cv = lp->Canvas;
	cv->Font->Assign(lp->Font);
	cv->Brush->Color = lp->Checked[Index]? col_selItem : col_bgList;
	cv->FillRect(Rect);

	int xp = Rect.Left + 4;
	int yp = Rect.Top + get_TopMargin(cv);
	if (RevTagCololr) yp += ScaledInt(2);

	usr_TAG->DrawTags(lp->Items->Strings[Index], cv, xp, yp,
		(RevTagCololr? col_bgList : clNone), UserModule->SpuitEnabled());

	//�g�p��
	int n = (int)lp->Items->Objects[Index];
	if (n>0) {
		cv->Font->Color = col_fgList;
		UnicodeString lbuf = n;
		xp += (MaxTagWidth + cv->TextWidth("99999999") - cv->TextWidth(lbuf));
		cv->TextOut(xp, yp, lbuf);
	}

	//�J�[�\��
	if (Index==lp->ItemIndex) {
		int lw = lp->Focused()? std::max(CursorWidth, 1) : 1;
		int yp = Rect.Bottom - lw;
		draw_Line(lp->Canvas, Rect.Left, yp, Rect.Right, yp, lw, col_Cursor, lp->Focused()? psSolid : psDot);
	}

	if (State.Contains(odFocused)) lp->Canvas->DrawFocusRect(Rect);
}
//---------------------------------------------------------------------------
//�^�O���̕ύX
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::RenTagActionExecute(TObject *Sender)
{
	if (TagCheckListBox->ItemIndex==-1) return;

	UnicodeString old_tag = TagCheckListBox->Items->Strings[TagCheckListBox->ItemIndex];
	UnicodeString new_tag = old_tag;
	if (input_query_ex(_T("�^�O���̕ύX"), _T("�^�O��"), &new_tag)
		&& !new_tag.IsEmpty() && !SameStr(old_tag, new_tag))
	{
		int new_idx = TagCheckListBox->Items->IndexOf(new_tag);
		int old_idx = TagCheckListBox->Items->IndexOf(old_tag);
		if (new_idx!=-1 && new_idx!=old_idx && !msgbox_Sure(_T("�����̓����^�O�ɓ������܂����H"))) return;

		int cnt = usr_TAG->RenTag(old_tag, new_tag);
		MaxTagWidth = usr_TAG->IniCheckList(TagCheckListBox, new_tag, ShowTagCountAction->Checked);
		ListScrPanel->UpdateKnob();
		if (cnt>0) msgbox_OK(UnicodeString().sprintf(_T("%u���ڂ̃^�O�ݒ���X�V���܂����B"), cnt));
	}
}
//---------------------------------------------------------------------------
//�^�O���̍폜
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::DelTagActionExecute(TObject *Sender)
{
	if (TagCheckListBox->ItemIndex==-1) return;

	UnicodeString tag = TagCheckListBox->Items->Strings[TagCheckListBox->ItemIndex];
	UnicodeString msg; msg.sprintf(_T("[%s] ���^�O�f�[�^����폜���܂���?"), tag.c_str());
	if (msgbox_Sure(msg)) {
		int cnt = usr_TAG->DelTagData(tag);
		MaxTagWidth = usr_TAG->IniCheckList(TagCheckListBox, EmptyStr, ShowTagCountAction->Checked);
		ListScrPanel->UpdateKnob();
		TagEdit->Text = EmptyStr;
		if (cnt>0) msgbox_OK(UnicodeString().sprintf(_T("%u���ڂ̃^�O���폜���܂����B"), cnt));
	}
}
//---------------------------------------------------------------------------
//�^�O�F�̐ݒ�
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::SetColorActionExecute(TObject *Sender)
{
	if (TagCheckListBox->ItemIndex==-1) return;

	UnicodeString tag = TagCheckListBox->Items->Strings[TagCheckListBox->ItemIndex];
	UserModule->ColorDlg->Color = usr_TAG->GetColor(tag, col_fgTagNam);
	if (UserModule->ColorDlg->Execute()) {
		usr_TAG->SetColor(tag, UserModule->ColorDlg->Color);
		TagCheckListBox->Repaint();
	}
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::DefColorActionExecute(TObject *Sender)
{
	if (TagCheckListBox->ItemIndex==-1) return;

	usr_TAG->SetColor(TagCheckListBox->Items->Strings[TagCheckListBox->ItemIndex], clNone);
	TagCheckListBox->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::SelActionUpdate(TObject *Sender)
{
	((TAction *)Sender)->Enabled = (TagCheckListBox->ItemIndex!=-1);

	if (!UserModule->SpuitEnabled()) SpuitImage->Visible = (TagCheckListBox->ItemIndex!=-1);
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::RefTagColBtnClick(TObject *Sender)
{
	SetColorAction->Execute();
}

//---------------------------------------------------------------------------
//�^�O�̎g�p�����J�E���g
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::CountTagActionExecute(TObject *Sender)
{
	usr_TAG->CountTags(TagCheckListBox);
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::CountTagActionUpdate(TObject *Sender)
{
	((TAction *)Sender)->Enabled = (TagCheckListBox->Count>0 && !ShowTagCountAction->Checked);
}

//---------------------------------------------------------------------------
//�^�O�̎g�p����\��
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::ShowTagCountActionExecute(TObject *Sender)
{
	TAction *ap = (TAction *)Sender;
	ap->Checked = !ap->Checked;
	usr_TAG->CountTags(TagCheckListBox, !ap->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::ShowTagCountActionUpdate(TObject *Sender)
{
	((TAction *)Sender)->Enabled = (TagCheckListBox->Count>0);
}

//---------------------------------------------------------------------------
//���݂��Ȃ����ڂ̃f�[�^�폜
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::TrimDataActionExecute(TObject *Sender)
{
	if (msgbox_Sure(LoadUsrMsg(USTR_DeleteQ, _T("���݂��Ȃ����ڂ̃f�[�^")), SureDelete)) {
		cursor_HourGlass();
		int cnt = usr_TAG->TrimData();
		cursor_Default();

		UnicodeString msg;
		if (cnt>0)
			msg.sprintf(_T("%u �̃f�[�^���폜���܂����B"), cnt);
		else
			msg.USET_T("���݂��Ȃ����ڂ̃f�[�^�͂���܂���ł����B");
		msgbox_OK(msg);
	}
}

//---------------------------------------------------------------------------
//����������R�}���h�t�@�C���Ƃ��ĕۑ�
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::PopupMenu1Popup(TObject *Sender)
{
	MakeNbtItem->Visible = SameText(CmdStr, "FindTag");
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::MakeNbtActionExecute(TObject *Sender)
{
	TAction *ap = (TAction *)Sender;
	UserModule->PrepareSaveDlg(_T("�R�}���h�t�@�C���Ƃ��ĕۑ�"), F_FILTER_NBT, NULL, CmdFilePath);
	if (UserModule->SaveDlg->Execute()) {
		CmdFilePath = ExtractFilePath(UserModule->SaveDlg->FileName);
		std::unique_ptr<TStringList> fbuf(new TStringList());
		UnicodeString kwd = TagEdit->Text;
		if (!AndCheckBox->Checked) kwd = ReplaceStr(kwd, ";", "|");
		UnicodeString tmp;
		fbuf->Add(tmp.sprintf(_T(";�^�O���� [%s]"), kwd.c_str()));
		if (ap->Tag==1) fbuf->Add("ToOpposite");
		fbuf->Add(tmp.sprintf(_T("FindTag_%s"), kwd.c_str()));
		if (!saveto_TextUTF8(UserModule->SaveDlg->FileName, fbuf.get())) msgbox_ERR(USTR_FaildSave);
	}
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::MakeNbtActionUpdate(TObject *Sender)
{
	TAction *ap = (TAction *)Sender;
	ap->Visible = SameText(CmdStr, "FindTag");
	ap->Enabled = ap->Visible && !TagEdit->Text.IsEmpty();
}

//---------------------------------------------------------------------------
//�X�|�C�g
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::SpuitImageMouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
	TCheckListBox *lp = TagCheckListBox;
	if (Button!=mbLeft || lp->ItemIndex==-1) return;

	//�X�E�H�b�`�u�b�N
	SetCustomColToSwatch(UserModule->ColorDlg->CustomColors);
	SwatchPanel->Visible = true;
	SwatchPanel->BringToFront();

	TColor col_def = usr_TAG->GetColor(lp->Items->Strings[lp->ItemIndex], clNone);
	UserModule->BeginSpuit(SpuitPanel, (TImage*)Sender, col_def);
	lp->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::SpuitImageMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	SwatchPanel->Visible = false;

	if (UserModule->SpuitEnabled()) {
		TColor col = UserModule->EndSpuit();
		TCheckListBox *lp = TagCheckListBox;
		if (lp->ItemIndex!=-1) usr_TAG->SetColor(lp->Items->Strings[lp->ItemIndex], col);
		lp->Repaint();
	}
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::RevColCheckBoxClick(TObject *Sender)
{
	RevTagCololr = RevColCheckBox->Checked;
	TagCheckListBox->Invalidate();
}

//---------------------------------------------------------------------------
void __fastcall TTagManDlg::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	UnicodeString KeyStr = get_KeyStr(Key, Shift);

	if (equal_ENTER(KeyStr))
		ModalResult = mrOk;
	else if (equal_ESC(KeyStr)) {
		if (UserModule->SpuitEnabled()) {
			SwatchPanel->Visible = false;
			UserModule->EndSpuit();
			TagCheckListBox->Repaint();
		}
		else
			ModalResult = mrCancel;
	}
	else {
		UnicodeString topic = HELPTOPIC_FL;
		topic.cat_sprintf(_T("#%s"), CmdStr.c_str());
		SpecialKeyProc(this, Key, Shift, topic.c_str());
	}
}
//---------------------------------------------------------------------------
void __fastcall TTagManDlg::CanButtonClick(TObject *Sender)
{
	if (UserModule->SpuitEnabled()) {
		SwatchPanel->Visible = false;
		UserModule->EndSpuit();
		TagCheckListBox->Repaint();
		ModalResult = mrNone;
	}
	else
		ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
