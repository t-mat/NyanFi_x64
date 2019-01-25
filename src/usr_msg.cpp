//----------------------------------------------------------------------//
// ���b�Z�[�W															//
//																		//
//----------------------------------------------------------------------//
#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <memory>
#include <System.StrUtils.hpp>
#include "usr_str.h"
#include "usr_msg.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

//---------------------------------------------------------------------------
//���b�Z�[�W������̎擾
//---------------------------------------------------------------------------
UnicodeString LoadUsrMsg(int id, UnicodeString s)
{
	std::unique_ptr<TStringList> msg_lst(new TStringList());
	msg_lst->Text =
		"1001=%s��������܂���B\n"							//USTR_NotFound
		"1002=%s���̑���ɂ͑Ή����Ă��܂���B\n"				//USTR_OpeNotSuported
		"1003=���̑���͂ł��܂���B\n"							//USTR_CantOperate
		"1004=�Ή����Ă��Ȃ��`���ł��B\n"						//USTR_FmtNotSuported
		"1005=�ꎞ�𓀂Ɏ��s���܂����B\n"						//USTR_FaildTmpUnpack
		"1006=�ړ��悪�����ł��B\n"								//USTR_SameMoveDest
		"1007=�R�s�[�悪�����ł��B\n"							//USTR_SameCopyDest
		"1008=�f�B���N�g�����܂܂�Ă��܂��B\n"					//USTR_IncludeDir
		"1009=�f�B���N�g���ɃA�N�Z�X�ł��܂���B\n"				//USTR_CantAccessDir
		"1010=�s���ȓ��t�܂��͎����ł��B\n"						//USTR_IllegalDate
		"1011=�s���Ȏw��ł��B\n"								//USTR_IllegalParam
		"1012=�s���Ȍ`���ł��B\n"								//USTR_IllegalFormat
		"1013=�s���ȃA�h���X�ł�\n"								//USTR_IllegalAddress
		"1014=�N���Ɏ��s���܂����B\n"							//USTR_FaildExec
		"1015=�����Ɏ��s���܂����B\n"							//USTR_FaildProc
		"1016=�ǂݍ��݂Ɏ��s���܂����B\n"						//USTR_FaildLoad
		"1017=%s�̕ۑ��Ɏ��s���܂����B\n"						//USTR_FaildSave
		"1018=�폜�Ɏ��s���܂����B\n"							//USTR_FaildDelete
		"1019=�R�s�[�Ɏ��s���܂����B\n"							//USTR_FaildCopy
		"1020=���j���[�����s�ł��܂���B\n"						//USTR_FaildMenu
		"1021=���f���܂����B\n"									//USTR_Canceled
		"1022=���[�N���X�g���J���܂���B\n"						//USTR_WlistCantOpen
		"1023=�������ɂ��̑���͂ł��܂���B\n"					//USTR_ProcBusy
		"1024=�Ώۂ�����܂���B\n"								//USTR_NoObject
		"1025=���K�\���Ɍ�肪����܂��B\n"						//USTR_IllegalRegEx
		"1026=����������̓���\n"								//USTR_InputFmtStr
		"1027=���łɓo�^����Ă��܂��B\n"						//USTR_Registered
		"1028=�@������...�^�@ESC�L�[�Œ��f���܂��B\n"			//USTR_SearchingESC
		"1029=�@�v�Z��...�^�@ESC�L�[�Œ��f���܂��B\n"			//USTR_CalculatingESC
		"1030=�@������...�^�@ESC�L�[�Œ��f���܂��B\n"			//USTR_ProcessingESC
		"1031=�@������...�^�@���΂炭���������������B\n"		//USTR_WaitForReady
		"1032=���X�|���X�t�@�C���̍쐬�Ɏ��s���܂����B\n"		//USTR_FaildListFile
		"1033=�ꎞ�f�B���N�g�����쐬�ł��܂���B\n"				//USTR_CantMakeTmpDir
		"1034=�s���ȍ\���ł��B\n"								//USTR_SyntaxError
		"1035=�Ή����鐧�䕶��������܂���B\n"				//USTR_BadStatmet
		"1036=�p�����[�^���w�肳��Ă��܂���B\n"				//USTR_NoParameter
		"1037=�A�v���P�[�V������������܂���B\n"				//USTR_AppNotFound
		"1038=�摜�̏������ł��Ă��܂���B\n"					//USTR_ImgNotReady
		"1039=�t�@�C�����J���܂���B\n"							//USTR_FileNotOpen
		"1040=�f�B���N�g����������܂���B\n"					//USTR_DirNotFound
		"1041=�����ȃR�}���h�ł��B\n"							//USTR_InvalidCmd
		"1042=. �ŋ�؂��ĕ����w��\\n"						//USTR_HintMltFExt
		"1043=; �ŋ�؂��ĕ����w��\\n"						//USTR_HintMltSepSC
		"1044=�Ή�����G�f�B�^������܂���\n"					//USTR_NoEditor
		"1045=�Đ��ł��܂���B\n"								//USTR_CantPlay
		"1046=%s�ɖ��O��t���ĕۑ�\n"							//USTR_SaveAs
		"1047=�f�B���N�g��[%s]���쐬�ł��܂���B\n"				//USTR_CantCreDir
		"1048=%s���R�s�[���܂���?\n"							//USTR_CopyQ
		"1049=%s���폜���܂���?\n"								//USTR_DeleteQ
		"1050=%s�����S�폜���܂���?\n"							//USTR_CompDeleteQ
		"1051=%s�̗��������ׂč폜���܂���?\n"					//USTR_DelHistoryQ
		"1052=���ׂĂ̏ꏊ�̂��ׂẴ}�[�N���������܂���?\n"	//USTR_ClrAllMarkQ
		"1053=�R�}���h�𒆒f���܂���?\n"						//USTR_CancelCmdQ
		"1054=�A�[�J�C�u���J���܂���B\n"						//USTR_ArcNotOpen
		"1055=�e�L�X�g�t�@�C���ł͂���܂���B\n"				//USTR_NotText
		"1056=%s�𒊏o���܂���?\n"								//USTR_Extract
		"1057=%s��񂪎擾�ł��܂���B\n"						//USTR_CantGetInfo
		"1058=���O���d�����Ă��܂��B\n"							//USTR_DuplicateName
		"1059=�㏑�����Ă��悢�ł���?\n"						//USTR_OverwriteQ
		"1060=%s���A�b�v���[�h���܂���?\n"						//USTR_UploadQ
		"1061=%s���_�E�����[�h���܂���?\n"						//USTR_DownloadQ
		"1062=�폜�J�n  %s\n"									//USTR_BeginDelete
		"1063=�����t�@�C���̏��� <%s>\n"						//USTR_SameName
		"1064=���O�̕ύX\n"										//USTR_Rename
		"1065=�f�B���N�g�������̈قȂ铯���Ώۂ����݂��܂��B\n"	//USTR_NgSameName
		"1066=�s���ȓ��t�����ł��B\n"							//USTR_IllegalDtCond
		"1067=�I���}�X�N���̃��[�N���X�g�͕ύX�ł��܂���B\n"	//USTR_WorkFiltered
		"1068=���E������f�B���N�g���ł��B\n"					//USTR_SameDirLR
		"1069=�����p�l�����B��\n"								//USTR_HideOptPanel
		"1070=�����p�l����\��\n"								//USTR_ShowOptPanel

		"1100=�I������\n"										//USTR_SelectedItem
		"1101=�ꗗ\n"											//USTR_List
		"1102=�A�b�v���[�h\n"									//USTR_Upload
		"1103=�_�E�����[�h\n";									//USTR_Download

	UnicodeString ret_str = REPLACE_TS(msg_lst->Values[IntToStr(id)], "�^", "\r\n");
	ret_str = s.IsEmpty()? replace_regex(ret_str, _T("%s[�̂�����]?"), null_TCHAR) : ReplaceStr(ret_str, "%s", s);
	return ret_str;
}
//---------------------------------------------------------------------------
UnicodeString LoadUsrMsg(int id, const _TCHAR *s)
{
	return LoadUsrMsg(id, UnicodeString(s));
}
//---------------------------------------------------------------------------
UnicodeString LoadUsrMsg(int id, int id_s)
{
	return LoadUsrMsg(id, LoadUsrMsg(id_s));
}

//---------------------------------------------------------------------------
//���[�U��`���b�Z�[�W�� EAbort �𑗏o
//---------------------------------------------------------------------------
void UserAbort(unsigned id)
{
	throw EAbort(LoadUsrMsg(id));
}

//---------------------------------------------------------------------------
void SysErrAbort(unsigned id)
{
	throw EAbort(SysErrorMessage(id));
}
//---------------------------------------------------------------------------
void LastErrAbort()
{
	throw EAbort(SysErrorMessage(GetLastError()));
}
//---------------------------------------------------------------------------
void TextAbort(const _TCHAR *msg)
{
	throw EAbort(UnicodeString(msg));
}
//---------------------------------------------------------------------------
void SkipAbort()
{
	throw EAbort("SKIP");
}

//---------------------------------------------------------------------------
//�G���[���b�Z�[�W
//---------------------------------------------------------------------------
void msgbox_ERR(UnicodeString msg)
{
	if (msg.IsEmpty()) return;
	MessageDlg(msg, mtError, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------
void msgbox_ERR(unsigned id)
{
	msgbox_ERR(LoadUsrMsg(id));
}

//---------------------------------------------------------------------------
//�x�����b�Z�[�W
//---------------------------------------------------------------------------
void msgbox_WARN(UnicodeString msg)
{
	if (msg.IsEmpty()) return;
	MessageDlg(msg, mtWarning, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------
void msgbox_WARN(unsigned id)
{
	msgbox_WARN(LoadUsrMsg(id));
}

//---------------------------------------------------------------------------
//���b�Z�[�W
//---------------------------------------------------------------------------
void msgbox_OK(UnicodeString msg, UnicodeString tit)
{
	Application->MessageBox(msg.c_str(),
		def_if_empty(tit, _T("�m�F")).c_str(), MB_OK);
}
//---------------------------------------------------------------------------
bool msgbox_Y_N(UnicodeString msg, UnicodeString tit)
{
	int res = Application->MessageBox(msg.c_str(),
				def_if_empty(tit, _T("�m�F")).c_str(), MB_YESNO|MB_ICONQUESTION);
	return (res==IDYES);
}
//---------------------------------------------------------------------------
int msgbox_Y_N_C(UnicodeString msg, UnicodeString tit)
{
	return Application->MessageBox(msg.c_str(),
		def_if_empty(tit, _T("�m�F")).c_str(), MB_YESNOCANCEL|MB_ICONQUESTION);
}

//---------------------------------------------------------------------------
//�m�F���b�Z�[�W
//---------------------------------------------------------------------------
bool SureCopy;					//�m�F - �R�s�[
bool SureMove;					//�m�F - �ړ�
bool SureDelete;				//�m�F - �폜
bool SureUnPack;				//�m�F - ��
bool SureExec;					//�m�F - ���s
bool SureOther;					//�m�F - ���̑�
bool SureExit;					//�m�F - �I��
bool SureCmpDel;				//�m�F - ���S�폜��2�x�m�F
bool SureCancel;				//�m�F - �L�����Z���{�^����\��
bool SureDefNo;					//�m�F - �u�������v���f�t�H���g
bool SureAdjPos;				//�m�F - �\���ʒu���󋵂ɍ��킹�Ē���

bool MsgPosCenter = false;		//���C����ʂ̒����ɕ\��

//---------------------------------------------------------------------------
bool msgbox_Sure(UnicodeString msg, bool ask, bool center)
{
	if (!ask) return true;
	unsigned int flag = (SureCancel? MB_YESNOCANCEL : MB_YESNO) | MB_ICONQUESTION;
	if (SureDefNo) flag |= MB_DEFBUTTON2;

	MsgPosCenter = center;
	bool res = (Application->MessageBox(msg.c_str(), _T("�m�F"), flag)==IDYES);
	MsgPosCenter = false;

	return res;
}
//---------------------------------------------------------------------------
bool msgbox_Sure(const _TCHAR *msg, bool ask, bool center)
{
	return msgbox_Sure(UnicodeString(msg), ask, center);
}
//---------------------------------------------------------------------------
bool msgbox_Sure(int id, bool ask, bool center)
{
	if (!ask) return true;
	return msgbox_Sure(LoadUsrMsg(id), ask, center);
}

//---------------------------------------------------------------------------
//�u���ׂĂɓK�p�v�`�F�b�N�{�b�N�X�t��
//---------------------------------------------------------------------------
int msgbox_SureAll(UnicodeString msg, bool &app_chk, bool center)
{
	TForm *MsgDlg = CreateMessageDialog(msg, mtConfirmation,
						TMsgDlgButtons() << mbYes << mbNo << mbCancel, 
						SureDefNo? mbNo : mbYes);

	//�u���ׂĂɓK�p�v�`�F�b�N�{�b�N�X��ǉ�
	TCheckBox *cp = new TCheckBox(MsgDlg);
	MsgDlg->ClientHeight = MsgDlg->ClientHeight + cp->Height + 12;
	cp->Caption = "���ׂĂɓK�p(&A)";
	cp->Parent	= MsgDlg;
	cp->Left	= 20;
	cp->Top		= MsgDlg->ClientHeight - cp->Height - 12;
	cp->Width	= MsgDlg->ClientWidth - cp->Left;

	MsgPosCenter = center;
	int res = MsgDlg->ShowModal();
	MsgPosCenter = false;

	app_chk = cp->Checked;
	delete MsgDlg;

	return res;
}
//---------------------------------------------------------------------------