//----------------------------------------------------------------------//
// NyanFi																//
//  �U�蕪���_�C�A���O													//
//----------------------------------------------------------------------//
#ifndef DistrDlgH
#define DistrDlgH

//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Actions.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include "usr_spbar.h"

//---------------------------------------------------------------------------
class TDistributionDlg : public TForm
{
__published:	// IDE �ŊǗ������R���|�[�l���g
	TAction *AddRegAction;
	TAction *ChgRegAction;
	TAction *DelRegAction;
	TAction *EditListAction;
	TAction *ExeCopyAction;
	TAction *ExeMoveAction;
	TAction *FindDownAction;
	TAction *FindUpAction;
	TAction *GroupCheckAction;
	TAction *MakeFileAction;
	TAction *PrvListAction;
	TAction *SelFileAction;
	TActionList *ActionList1;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TButton *AddItemBtn;
	TButton *CheckBtn;
	TButton *ChgItemBtn;
	TButton *CopyBtn;
	TButton *DelItemBtn;
	TButton *DowItemBtn;
	TButton *HiddenCanBtn;
	TButton *MoveBtn;
	TButton *RefDirButton;
	TButton *RefListBtn;
	TButton *UpItemBtn;
	TCheckBox *CreDistrDirCheckBox;
	TCheckListBox *RegListBox;
	TComboBox *SameNameComboBox;
	THeaderControl *PrvListHeader;
	TLabel *Label1;
	TLabeledEdit *DistrDirEdit;
	TLabeledEdit *DistrMaskEdit;
	TLabeledEdit *FindEdit;
	TLabeledEdit *TitleEdit;
	TListBox *ListListBox;
	TListBox *PrvListBox;
	TMenuItem *EditListItem;
	TMenuItem *EditListItem2;
	TMenuItem *GroupChkItem;
	TMenuItem *PrvListItem;
	TMenuItem *PrvListItem2;
	TMenuItem *SaveRegItem;
	TMenuItem *SelFileItem;
	TMenuItem *Sep_1;
	TMenuItem *Sep_2;
	TMenuItem *Sep_3;
	TPanel *ExePanel;
	TPanel *ListPanel;
	TPanel *MainPanel;
	TPanel *PrvPanel;
	TPanel *RegPanel;
	TPopupMenu *PopupMenu1;
	TPopupMenu *PopupMenu2;
	TSpeedButton *FindDownBtn;
	TSpeedButton *FindUpBtn;
	TSplitter *ListSplitter;
	TSplitter *PrvSplitter;
	TStatusBar *StatusBar1;

	void __fastcall ExeCopyActionExecute(TObject *Sender);
	void __fastcall ExeMoveActionExecute(TObject *Sender);
	void __fastcall ExeActionUpdate(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall AddRegActionExecute(TObject *Sender);
	void __fastcall ChgRegActionExecute(TObject *Sender);
	void __fastcall ChgRegActionUpdate(TObject *Sender);
	void __fastcall DelRegActionExecute(TObject *Sender);
	void __fastcall RegListBoxClick(TObject *Sender);
	void __fastcall AddRegActionUpdate(TObject *Sender);
	void __fastcall RegListBoxClickCheck(TObject *Sender);
	void __fastcall RegListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall PrvListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall ListListBoxDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall CheckBtnClick(TObject *Sender);
	void __fastcall RegListBoxKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall ListListBoxKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall PrvListBoxData(TWinControl *Control, int Index, UnicodeString &Data);
	void __fastcall PrvListHeaderDrawSection(THeaderControl *HeaderControl, THeaderSection *Section,
			const TRect &Rect, bool Pressed);
	void __fastcall PrvListHeaderSectionClick(THeaderControl *HeaderControl, THeaderSection *Section);
	void __fastcall PrvListHeaderSectionResize(THeaderControl *HeaderControl, THeaderSection *Section);
	void __fastcall RefDirButtonClick(TObject *Sender);
	void __fastcall FindDownActionExecute(TObject *Sender);
	void __fastcall FindDownActionUpdate(TObject *Sender);
	void __fastcall FindUpActionExecute(TObject *Sender);
	void __fastcall FindUpActionUpdate(TObject *Sender);
	void __fastcall FindEditChange(TObject *Sender);
	void __fastcall FindEditKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall CreDistrDirCheckBoxClick(TObject *Sender);
	void __fastcall RefListBtnClick(TObject *Sender);
	void __fastcall PrvListBoxDblClick(TObject *Sender);
	void __fastcall MakeFileActionExecute(TObject *Sender);
	void __fastcall SelFileActionExecute(TObject *Sender);
	void __fastcall GroupCheckActionExecute(TObject *Sender);
	void __fastcall PrvListActionExecute(TObject *Sender);
	void __fastcall EditListActionExecute(TObject *Sender);
	void __fastcall EditListActionUpdate(TObject *Sender);

private:	// ���[�U�[�錾
	SttProgressBar *SttPrgBar;		//�v���O���X�o�[
	int PrvSortMode;
	UnicodeString LastDistDir;
	UnicodeString DistrFile;
	bool RegEnabled;				//�o�^���e�̕ύX������

	void __fastcall WmFormShowed(TMessage &msg);
	void __fastcall AssignRegListBox();
	bool __fastcall LoadDistrFile();
	bool __fastcall SaveDistrFile();
	void __fastcall UpdatePreview(bool upd = true);
	UnicodeString __fastcall MakeRegItem(int idx = -1);
	bool __fastcall MatchRegItem(int idx);
	bool __fastcall MatchRegMask(UnicodeString mask, UnicodeString nnam);
	void __fastcall UpdateListItem(int idx);

public:		// ���[�U�[�錾
	TStringList *ItemList;			// IN �Ώۃ��X�g
	TStringList *DistrList;			//OUT �U�蕪�����X�g(�t�@�C���� \t �U�蕪����)
	UnicodeString OppPath;			//���΃p�X
	bool IsMove;					//true=�ړ�/ false=�R�s�[
	bool ImmediateExe;				//�m�F�����Œ����Ɏ��s
	int  SkipCount;					//�U�蕪����s�݂ɂ��X�L�b�v��

	__fastcall TDistributionDlg(TComponent* Owner);

	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER(WM_FORM_SHOWED,	TMessage,	WmFormShowed)
	END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TDistributionDlg *DistributionDlg;
//---------------------------------------------------------------------------
#endif