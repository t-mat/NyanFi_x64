//----------------------------------------------------------------------//
// NyanFi																//
//  �O���[�o��															//
//----------------------------------------------------------------------//
#ifndef GlobalH
#define GlobalH

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <htmlhelp.h>
#include <mmsystem.h>
#include "usr_shell.h"
#include "usr_file_ex.h"
#include "usr_arc.h"
#include "usr_migemo.h"
#include "usr_scrpanel.h"
#include "usr_highlight.h"
#include "usr_tag.h"
#include "UIniFile.h"
#include "UserFunc.h"
#include "htmconv.h"
#include "task_thread.h"
#include "imgv_thread.h"
#include "icon_thread.h"
#include "thumb_thread.h"

//---------------------------------------------------------------------------
#define SUPPORT_URL		"http://nekomimi.la.coocan.jp/"
#define DOWNLOAD_URL	"http://nekomimi.la.coocan.jp/freesoft/"
#define COPYRIGHT_INF	"2013-2019 by Nekomimi"

//---------------------------------------------------------------------------
#define WM_FORM_SHOWED		(WM_APP + 1)
#define WM_NYANFI_FLICON	(WM_APP + 100)
#define WM_NYANFI_THUMBNAIL	(WM_APP + 101)
#define WM_NYANFI_CLPCOPIED	(WM_APP + 102)
#define WM_NYANFI_PLAYLIST	(WM_APP + 103)

//---------------------------------------------------------------------------
//WM_COPYDATA ���b�Z�[�W�̎��ʔԍ�
#define CPYDTID_OPTIONS	1		//�N���I�v�V����
#define CPYDTID_DPL_INF	2		//��d�N��������̉�ʏ��
#define CPYDTID_DPL_MSG	3		//��d�N��������̒ʒm���b�Z�[�W
#define CPYDTID_TXTVIEW	4		//�e�L�X�g�r���A�[�ŊJ��
#define CPYDTID_IMGVIEW	5		//�C���[�W�r���A�[�ŊJ��
#define CPYDTID_EXECMDS	6		//�R�}���h�����s

//---------------------------------------------------------------------------
//�N���p�o�b�`�t�@�C��
extern UnicodeString RstBatName;

//---------------------------------------------------------------------------
//HTML�w���v
typedef HWND (WINAPI *FUNC_HtmlHelp)(HWND, LPCWSTR, UINT, DWORD);
extern  HINSTANCE	  hHHctrl;
extern  FUNC_HtmlHelp lpfHtmlHelp;
extern  bool		  CancelHelp;

void HtmlHelpTopic(const _TCHAR *topic);
void HtmlHelpContext(int idx);
void HtmlHelpKeyword(UnicodeString fnam, UnicodeString kwd);
void HtmlHelpClose();

#define HELPTOPIC_TOP	"hid00001.htm"		//�\��
#define HELPTOPIC_FL	"hid00005.htm"		//�t�@�C���[ - �R�}���h
#define HELPTOPIC_TV	"hid00006.htm"		//�e�L�X�g�r���A�[
#define HELPTOPIC_IV	"hid00007.htm"		//�C���[�W�r���A�[
#define HELPTOPIC_IS	"hid00050.htm"		//�C���N�������^���T�[�`
#define HELPTOPIC_CI	"hid00100.htm"		//�R�}���h�̍���
#define HELPTOPIC_CILW	"hid00100.htm#LW"	//�R�}���h�̍���(���O�E�B���h�E)
#define HELPTOPIC_FI	"hid00101.htm"		//�R�}���h�̍���(�@�\��)
#define HELPTOPIC_XC	"hid00063.htm"		//ExeCommands �R�}���h
#define HELPTOPIC_GR	"hid00056.htm"		//�����񌟍�(GREP)
#define HELPTOPIC_RP	"hid00061.htm"		//������u��
#define HELPTOPIC_CH	"hid00109.htm"		//�ύX����

//---------------------------------------------------------------------------
//����JAPI
typedef BOOL (WINAPI *FUNC_GetFontResourceInfo)(LPCWSTR, DWORD*, LPVOID, DWORD);
extern HINSTANCE	 hGdi32;
extern FUNC_GetFontResourceInfo lpGetFontResourceInfo;

//---------------------------------------------------------------------------
//��ʃ��[�h(ScrMode)
#define SCMD_FLIST	1					//�t�@�C���[
#define SCMD_TVIEW	2					//�e�L�X�g�r���A�[
#define SCMD_IVIEW	4					//�C���[�W�r���A�[
#define SCMD_GREP	8					//GREP

#define MAX_FILELIST	 2				//�t�@�C�����X�g�� (���E)
#define MAX_TASK_THREAD	 6				//�ő�^�X�N�� = 4 + 2(�������s�p)

#define MAX_BGIMAGE		 6				//�w�i�摜��(�w�i*2/ ���E*2/ �m�u*2)
#define BGIMGID_KNOB_V	 4
#define BGIMGID_KNOB_H	 5

#define MAX_TABLIST	 	30				//�ő�^�u��

#define MAX_FNTZOOM_SZ	72				//�ő�t�H���g�T�C�Y
#define MIN_FNTZOOM_SZ	2				//�ŏ��t�H���g�T�C�Y

#define MAX_WORKHISTORY 50				//�ő像�[�N���X�g����

#define CMPDEL_BUFF_SIZE 2048			//���S�폜�̃o�b�t�@�T�C�Y
#define CRLF_DETECT_LINE 1000			//���s�R�[�h����̍s��

#define ID_CALL_HOTKEY	101
#define ID_APP_HOTKEY	102

#define TMP_ARC_F	"ARC~%04u"			//�A�[�J�C�u�p�ꎞ�f�B���N�g���̏���
#define TMP_ARC_P	"ARC~????"			//�A�[�J�C�u�p�ꎞ�f�B���N�g���̌����p�^�[��
#define TMP_FTP_D	"FTP~0000"			//FTP�p�ꎞ�f�B���N�g��

#define HILT_INI_FILE "Highlight.INI"	//�\�������\����`
#define DIR_HIST_FILE "DirHistory.INI"	//�f�B���N�g���S�̗���
#define CALC_INI_FILE "Calculator.INI"	//�d��̒�`
#define TAGDATA_FILE  "TAGDATA.TXT"		//�^�O�f�[�^
#define DRVLOG_FILE   "DriveLog.csv"	//�h���C�u�e�ʃ��O
#define RENLOG_FILE   "renamelog.txt"	//�������O

#define WEBMAP_FILE	  "$~WEBMAP.HTM"	//Google�}�b�v�\���p�t�@�C��
#define WEBMAP_TPLT	  "WEBMAP.HTM"		//Google�}�b�v�\���p�e���v���[�g

#define RESPONSE_FILE "$~LISTFILE.TXT"	//���X�|���X�t�@�C����
#define RESPONSE_ERR  "ERROR"

#define DISTR_FILE	  "Distribute.INI"	//�U�蕪���o�^�t�@�C��

#define FONTSMPL_FILE "FontSample.INI"	//�t�H���g���{

#define SFX_AUTOREN   "_\\SN(1)"		//�f�t�H���g�̎�����������(�T�t�B�b�N�X)
#define FMT_AUTO_REN  "\\N" SFX_AUTOREN	//�f�t�H���g�̎�����������

#define EXTMENU_CSVITMCNT	6
#define EXTTOOL_CSVITMCNT	6
#define TABLIST_CSVITMCNT	8
#define DISTRLS_CSVITMCNT	4

#define MAX_CSV_ITEM	255

//---------------------------------------------------------------------------
//���X�g�{�b�N�X�p�I�v�V�����t���O(Tag �ɐݒ�)
//  �t�@�C�����ł͉���2�o�C�g�����ږ��ő啝�ɗ��p
#define LBTAG_OPT_FIF1	0x00010000		//�t�@�C�����(�ŏ���3�s�͊�{���)
#define LBTAG_OPT_FIF2	0x00020000		//�t�@�C�����
#define LBTAG_OPT_SDIR	0x00040000		//����t�H���_�ꗗ(���ϐ��g�p��)
#define LBTAG_OPT_TREE	0x00080000		//�c���[�\��
#define LBTAG_OPT_ZOOM	0x00100000		//�Y�[���\
#define LBTAG_OPT_LNNO	0x00200000		//�s�ԍ��\��
#define LBTAG_OPT_LCPY	0x00400000		//1�s�R�s�[�\
#define LBTAG_OPT_LOOP	0x00800000		//���[�v�ړ�
#define LBTAG_GEN_LIST	0x01000000		//�ꗗ�_�C�A���O
#define LBTAG_FIF_LIST	0x02000000		//�t�@�C�����_�C�A���O
#define LBTAG_TAB_FNAM	0x04000000		//�^�u�ȍ~�Ƀt�@�C����������
#define LBTAG_HAS_SICO	0x08000000		//�X���[���A�C�R����\��

//---------------------------------------------------------------------------
#define SHOW_WARN_TAG	-1

//---------------------------------------------------------------------------
//�������Ɏ󂯕t����R�}���h
#define ONFIND_CMD		"CursorUp|CursorDown|PageUp|PageDown|CurrToOpp|FileEdit|BinaryEdit|OpenByApp|OpenByWin|OpenStandard|Select"

//---------------------------------------------------------------------------
//load_ImageFile �̖߂�l
#define LOADED_BY_STD	1		//WIC�W��
#define LOADED_BY_WIC	2		//WIC���̑�

//---------------------------------------------------------------------------
//��d�N���I�����̉�ʏ��
struct win_dat {
//���C���E�B���h�E
	int WinTop;
	int WinLeft;
	int WinWidth;
	int WinHeight;
	TWindowState WinState;
//�T�u�p�l��
	int SubHeight;
	int SubWidth;
	int InfWidth;
	int InfHeight;
	int ImageWidth;
	int ImageHeight;
	int TailHeight;
//���̑�
	bool ShowFileListOnly;
};
extern win_dat Win2Data;

//---------------------------------------------------------------------------
extern TCursor crTmpPrev;	//�J�[�\���̃v���r���[�p

//---------------------------------------------------------------------------
extern UnicodeString KeyStr_SELECT;
extern UnicodeString KeyStr_Copy;
extern UnicodeString KeyStr_Cut;
extern UnicodeString KeyStr_Migemo;
extern UnicodeString KeyStr_Filter;
extern UnicodeString KeysStr_ToList;
extern UnicodeString KeysStr_CsrDown;
extern UnicodeString KeysStr_CsrUp;
extern UnicodeString KeysStr_PgDown;
extern UnicodeString KeysStr_PgUp;
extern UnicodeString KeysStr_Popup;

extern UnicodeString TabPinMark;

extern UnicodeString SortIdStr;
extern UnicodeString ScrModeIdStr;

//---------------------------------------------------------------------------
extern HWND   MainHandle;
extern DWORD  ProcessId;
extern bool   IsAdmin;
extern bool   IsPrimary;
extern int    StartedCount;
extern int    NyanFiIdNo;
extern int    ScrMode;
extern double ScrScale;
extern int    SIcoSize;
extern TRect  FileListRect;
extern bool   IsMuted;

extern TRichEdit *TempRichEdit;

extern TTaskThread *TaskThread[MAX_TASK_THREAD];
extern bool gTaskCancel[MAX_TASK_THREAD];
extern bool gTaskPause[MAX_TASK_THREAD];
extern int  MaxTasks;
extern bool RsvSuspended;
extern TaskConfigList *TaskReserveList;
extern int  LastOpCount;

extern TImgViewThread   *ImgViewThread;
extern TThumbnailThread *ThumbnailThread;
extern TGetIconThread   *GetIconThread;

extern UserArcUnit *usr_ARC;
extern UnicodeString FExt7zDll;

extern MigemoUnit  *usr_Migemo;
extern UnicodeString MigemoPath;
extern bool LastMigemoMode;
extern bool LastMigemoModeF;

extern int  WicScaleOpt;
extern UnicodeString WicFextStr;

extern bool gCopyAll;
extern bool gCopyCancel;

extern int  gCopyMode;
extern int  gCopyMode2;
extern int  xCopyMode;

#define CPYMD_OW			0
#define CPYMD_NEW			1
#define CPYMD_SKIP			2
#define CPYMD_AUT_REN		3
#define CPYMD_MAN_REN		4
#define CPYMD_REN_CLONE		5
#define CPYMD_NEW_BACKUP	10

extern UnicodeString gCopyFmt;

extern int OptionPageIndex;

extern bool SyncLR;

extern UnicodeString GlobalErrMsg;

extern bool Initialized;
extern bool UnInitializing;
extern bool Closing;

extern int  InhReload;
extern bool DisReload;

extern bool InhUpdate;

extern UnicodeString FindPath;
extern bool FindAborted;
extern bool FindDiff;
extern int  FindTag;
extern int  FindCount;

extern bool CalcAborted;
extern int  CalcTag;

//---------------------------------------------------------------------------
extern bool MultiInstance;
extern bool CloseOthers;
extern bool StoreTaskTray;
extern bool ShowIcon;
extern bool ShowDirType;
extern bool ShowSpace;
extern bool UseIndIcon;
extern bool ShowHideAtr;
extern bool ShowSystemAtr;
extern bool DispRegName;
extern bool UncToNetDrive;
extern bool PathInTitleBar;
extern bool OmitEndOfName;
extern bool ShowAdsInf;
extern bool ShowUseProcInf;
extern bool ShowDirJumboIco;
extern bool ShowInZipImg;
extern bool PreviewAniGif;
extern bool SetPrvCursor;
extern bool ForceDel;
extern bool RemoveCdReadOnly;
extern bool CopyNoBuffering;
extern bool ShowArcCopyProg;
extern bool DelUseTrash;
extern bool EditNewText;
extern bool ViewArcInf;
extern bool ReloadOnActive;
extern bool OpenAddedDrive;
extern bool CheckUnc;
extern bool ShowMsgHint;
extern bool ShowKeyHint;
extern bool ShowNoKeyHint;
extern bool ShowCopyHint;
extern bool ShowDuplNotify;
extern bool ShowTooltip;
extern bool LogErrOnly;
extern bool LogErrMsg;
extern bool LogDebugInf;
extern bool LogHideSkip;
extern bool LogFullPath;
extern bool SaveLog;
extern bool AppendLog;
extern bool NotSortWorkList;
extern bool RegWorkCsrPos;
extern bool AutoDelWorkList;
extern bool NoCheckWorkUnc;
extern bool AddToRecent;
extern bool NoCheckRecentUnc;
extern bool DirHistCsrPos;
extern bool DelDplDirHist;
extern bool WorkToDirHist;
extern bool NoCheckDirHist;
extern bool ExtSaveDirHist;
extern bool LoopFilerCursor;
extern bool FlCursorVisible;
extern bool AutoCompComboBox;
extern bool RestoreComboBox;
extern bool DialogCenter;
extern bool MenuAutoHotkey;
extern bool EscapeHelp;
extern bool InhbitAltMenu;
extern bool SelectByMouse;
extern bool SelectBaseOnly;
extern bool SelectIconSngl;
extern bool TimColEnabled;
extern bool PriorFExtCol;
extern bool ColorOnlyFExt;
extern bool SymColorToName;
extern bool RevTagCololr;
extern bool ShowMainMenu;
extern bool ShowImgPreview;
extern bool ShowProperty;
extern bool ShowLogWin;
extern bool ShowFileListOnly;
extern bool ShowFileListOnly2;
extern bool ShowSttBar;
extern bool ShowToolBar;
extern bool ShowToolBarV;
extern bool ShowToolBarI;
extern bool ToolBarISide;
extern bool ShowTabBar;
extern bool ShowFKeyBar;
extern bool ShowClsTabBtn;
extern bool ShowPopTabBtn;
extern bool ShowPopDirBtn;
extern bool HideScrBar;
extern bool ShowByteSize;
extern bool ShowTargetInf;
extern bool ShowHeader;
extern bool FixListWidth;
extern bool KeepOnResize;
extern bool KeepCurListWidth;
extern bool NoSpaceFExt;
extern bool HideTitleMenu;
extern bool FlatInfPanel;
extern bool ShowLineNo;
extern bool ShowLineCursor;
extern bool ShowTAB;
extern bool ShowCR;
extern bool ShowTextRuler;
extern bool ScrBarToFoldPos;
extern bool TxtSttIsBottom;
extern bool ChkAozora;
extern bool UseXd2tx;
extern bool ClickableUrl;
extern bool RestoreViewLine;
extern bool EmpComment;
extern bool EmpStrings;
extern bool EmpReserved;
extern bool EmpSymbol;
extern bool EmpNumeric;
extern bool EmpHeadline;
extern bool EmpRuby;
extern bool RotViewImg;
extern bool KeepZoomRatio;
extern bool ShowThumbName;
extern bool ShowThumbExif;
extern bool ShowThumbTags;
extern bool ShowThumbFExt;
extern bool NotThumbIfArc;
extern bool LoopViewCursor;
extern bool HintTopEndImg;
extern bool BeepTopEndImg;
extern bool ImgSttIsBottom;
extern bool SeekBindDir;
extern bool SeekSwapNxtPrv;
extern bool HideCsrInFull;
extern bool HideThumbInFull;
extern bool AnimateGif;
extern bool ShowThumbScroll;
extern bool ShowHistogram;
extern bool ShowLoupe;
extern bool ShowGifViewer;
extern bool ShowSeekBar;
extern bool WarnHighlight;
extern bool DoublePage;
extern bool RightBind;
extern bool PermitDotCmds;
extern bool InheritDotNyan;
extern bool DotNyanPerUser;
extern int  InitialModeI;
extern int  LastZoomRatio;

extern bool MarkImgClose;
extern UnicodeString MarkImgPath;
extern UnicodeString MarkImgFExt;
extern UnicodeString MarkImgMemo;

extern int  ScrBarStyle;

extern bool ModalScreen;
extern int  ModalScrAlpha;
extern TColor col_ModalScr;

extern UnicodeString DlgMoveShift;
extern UnicodeString DlgSizeShift;
extern int  DlgMovePrm;
extern int  DlgSizePrm;

extern UnicodeString WheelCmdF[4];
extern UnicodeString WheelCmdV[4];
extern UnicodeString WheelCmdI[4];

extern UnicodeString WheelBtnCmdF[4];
extern UnicodeString WheelBtnCmdV;
extern UnicodeString WheelBtnCmdI;

extern UnicodeString X1BtnCmdF;
extern UnicodeString X2BtnCmdF;
extern UnicodeString X1BtnCmdV;
extern UnicodeString X2BtnCmdV;
extern UnicodeString X1BtnCmdI;
extern UnicodeString X2BtnCmdI;

extern UnicodeString EmpBinPtn1;
extern UnicodeString EmpBinPtn2;
extern UnicodeString EmpBinPtn3;

extern UnicodeString HtmInsHrCls;
extern UnicodeString HtmHdrStr;
extern bool HtmInsHrSct;
extern bool HtmInsHrArt;
extern bool HtmInsHrNav;
extern bool ToMarkdown;
extern UnicodeString HtmDelBlkCls;
extern UnicodeString HtmDelBlkId;

extern UnicodeString NoWatchPath;

extern UnicodeString FExtGetInf;
extern UnicodeString FExtNoInf;
extern UnicodeString NoInfPath;
extern UnicodeString EmpInfItems;

extern UnicodeString FExtImgPrv;
extern UnicodeString FExtNoImgPrv;
extern UnicodeString NoImgPrvPath;

extern UnicodeString FExtNoIView;

extern UnicodeString DrvInfFmtR;
extern UnicodeString DrvInfFmtS;
extern UnicodeString DrvInfFmtN;
extern bool SelColDrvInf;

extern UnicodeString SttBarFmt;
extern UnicodeString SttClockFmt;

extern int  MaxLogFiles;

extern int  ProtectDirMode;
extern bool ProtectSubDir;
extern bool ProtectFile;

extern bool WarnPowerFail;
extern bool WarnDisconnect;
extern bool WarnLowBattery;
extern int  BatLowerLimit;

extern int  BorderMoveWidth;
extern UnicodeString AutoRenFmt;
extern int  RemoteWaitTime;
extern int  NormalWaitTime;
extern int  NopDtctTime;
extern int  TimeTolerance;

extern bool AppListChgMin;
extern bool CreDirChg;
extern bool CreDirCnvChar;
extern UnicodeString FExtExeFile;
extern bool OpenOnlyCurEdit;
extern bool DontClrSelEdit;
extern int  OpenByMode;
extern bool OpenDirByStd;
extern int  DblClickFlMode;
extern bool OpenOnlyCurApp;
extern bool DontClrSelApp;
extern bool OpenOnlyCurWin;
extern bool DontClrSelWin;
extern bool OpenStdTabGroup;
extern bool OpenStdMenuFile;
extern bool OpenStdResultList;
extern bool DownAfterOpenStd;
extern bool OpenStdOnResList;
extern UnicodeString IniSeaShift;
extern bool IniSeaByNum;
extern bool IniSeaBySign;
extern bool IncSeaCaseSens;
extern bool IncSeaLoop;
extern bool IncSeaMatch1Exit;
extern int  IncSeaMigemoMin;
extern bool NotShowNoTask;
extern UnicodeString WebSeaUrl;

extern bool FindPathColumn;
extern int  FindPathWidth;
extern bool FindTagsColumn;
extern int  FindTagsWidth;

extern bool GrepShowItemNo;
extern bool GrepFileItemNo;
extern bool GrepShowSubDir;
extern bool GrepTrimTop;
extern bool GrepOmitTop;
extern bool GrepEmFilter;
extern int  GrepOutMode;
extern UnicodeString GrepFileName;
extern UnicodeString GrepAppName;
extern UnicodeString GrepAppParam;
extern UnicodeString GrepAppDir;
extern bool GrepAppend;
extern UnicodeString GrepFileFmt;
extern UnicodeString GrepInsStrW;
extern UnicodeString GrepInsStrW2;
extern bool GrepTrimLeft;
extern bool GrepReplaceTab;
extern bool GrepReplaceCr;
extern UnicodeString GrepRepCrStr;
extern bool BackupReplace;
extern UnicodeString FExtRepBackup;
extern UnicodeString RepBackupDir;
extern UnicodeString ReplaceLogName;
extern bool SaveReplaceLog;
extern bool ReplaceAppend;
extern bool OpenReplaceLog;

extern UnicodeString UserName;
extern UnicodeString TempPath;
extern UnicodeString TempPathA;
extern UnicodeString TempPathFTP;

extern UnicodeString DownloadPath;
extern UnicodeString LibraryPath;
extern UnicodeString WorkListPath;
extern UnicodeString ResultListPath;
extern UnicodeString RefParamPath;
extern UnicodeString IconFilePath;
extern UnicodeString CmdFilePath;

extern int VersionNo;
extern UnicodeString VersionStr;

extern UnicodeString DirBraStr;
extern UnicodeString DirKetStr;
extern UnicodeString TimeStampFmt;

extern UnicodeString CallHotKey;
extern UnicodeString AppListHotKey;
extern UnicodeString AppListHotPrm;

extern UnicodeString SaveTxtPath;
extern int SaveEncIndex;

extern UnicodeString NoDirHistPath;
extern UnicodeString NoEditHistPath;
extern UnicodeString NoViewHistPath;

extern UnicodeString DirDelimiter;

extern int CurTabIndex;

extern UnicodeString CurPathName;
extern int CurListTag;
extern int OppListTag;
extern int LastCurTag;
extern int WorkingTag;

extern UnicodeString FTPTextModeFExt;
extern bool FTPDlKeepTime;
extern bool FTPUpKeepTime;
extern bool FTPUpToLower;
extern bool FTPLogResponse;
extern int  FTPRemoteSide;
extern int  FTPDisconTimeout;

extern UnicodeString FTPSndConnect;
extern UnicodeString FTPSndDiscon;
extern UnicodeString FTPSndTransfer;

extern TListBox *FileListBox[MAX_FILELIST];
extern TPanel	*FileListPanel[MAX_FILELIST];

extern UnicodeString ViewFileName;
extern UnicodeString ViewFileName2;
extern bool ViewFromArc;

//---------------------------------------------------------------------------
#define GENLST_FILELIST	1
#define GENLST_DRIVE	2
#define GENLST_CMDSLIST	3
#define GENLST_TABLIST	4
#define GENLST_ICON		5
#define GENLST_FONT		6

extern TStringList *GeneralList;

//---------------------------------------------------------------------------
extern TStringList *FileList[MAX_FILELIST];
extern TStringList *ArcFileList[MAX_FILELIST];
extern TStringList *AdsFileList[MAX_FILELIST];
extern TStringList *ResultList[MAX_FILELIST];
extern TStringList *SelMaskList[MAX_FILELIST];
extern TStringList *TmpBufList[MAX_FILELIST];

extern TStringList *DriveInfoList;
extern TStringList *DriveLogList;
extern UnicodeString DriveLogName;

extern TStringList *WatchTailList;
extern UnicodeString LastWatchLog;

extern TStringList *InvalidUncList;

extern TStringList *TabList;
extern TStringList *TabBuff;
extern int FlTabWidth;
extern int FlTabStyle;
extern UnicodeString TabGroupName;

extern TStringList *CachedIcoList;
extern TMultiReadExclusiveWriteSynchronizer *IconRWLock;
extern int  IconCache;

extern TStringList *GeneralIconList;
extern TStringList *MenuBtnIcoList;
extern TStringList *UsrIcoList;
extern TStringList *DrvIcoList;

extern TStringList *BakSetupList;
extern TStringList *SyncDirList;
extern TStringList *AssRenList;
extern TStringList *DistrDefList;

extern TStringList *GrepPathList;
extern TStringList *GrepFileList;
extern TStringList *GrepResultList;
extern TStringList *GrepResultBuff;

extern TStringList *ViewFileList;
extern bool isViewIcon;
extern bool isViewAGif;
extern bool isViewClip;
extern bool isViewFTP;
extern bool rqThumbnail;
extern bool nrmThumbnail;

extern TStringList *LaunchList;

extern UnicodeString PathMask[MAX_FILELIST];
extern UnicodeString DriveInf[MAX_FILELIST];

extern TStringList *WorkList;
extern UnicodeString WorkListName;
extern TDateTime WorkListTime;
extern bool WorkListChanged;
extern bool WorkListFiltered;
extern bool WorkListHasSep;
extern bool rqWorkListDirInf;

extern TStringList *PlayList;
extern UnicodeString PlayListFile;
extern UnicodeString PlayFile;
extern int  PlayStbIdx;
extern bool PlayRepeat;
extern bool PlayShuffle;
extern bool ListShuffled;

extern int  IniPathMode[MAX_FILELIST];
extern UnicodeString InitialPath[MAX_FILELIST];
extern UnicodeString InitialMask[MAX_FILELIST];
extern int  IniSortMode[MAX_FILELIST];

extern int  IniWorkMode;
extern UnicodeString HomeWorkList;

extern TStringList *PopMenuList;
extern TStringList *ToolBtnList;
extern TStringList *ToolBtnListV;
extern TStringList *ToolBtnListI;

extern int  IniWinMode;
extern int  IniWinLeft, IniWinTop, IniWinWidth, IniWinHeight;
extern bool FixWinPos;
extern bool IniPathToTab1;
extern bool IniTabHomeAll;
extern bool ShowSplash;

//---------------------------------------------------------------------------
#define MAX_EVENT_CMD	65
extern UnicodeString OnAppStart;
extern UnicodeString OnAppClose;
extern UnicodeString OnMaximized;
extern UnicodeString OnMinimized;
extern UnicodeString OnRestored;
extern UnicodeString OnCurChange;
extern UnicodeString OnTabChange;
extern UnicodeString OnNewDrive;
extern UnicodeString OnArcOpend;
extern UnicodeString OnArcClosed;
extern UnicodeString OnFindOpend;
extern UnicodeString OnFlCursor;
extern UnicodeString OnFlExDClick;
extern UnicodeString OnFlTbRClick;
extern UnicodeString OnTabDClick;
extern UnicodeString OnTabRClick;
extern UnicodeString OnFlRClick;
extern UnicodeString OnDragStart;
extern UnicodeString OnDragEnd;
extern UnicodeString OnGrepOpen;
extern UnicodeString OnGrepClosed;
extern UnicodeString OnWatchNotify;
extern UnicodeString OnFTPConnect;
extern UnicodeString OnFTPDiscon;
extern UnicodeString OnDirDClick;
extern UnicodeString OnDirRClick;
extern UnicodeString OnRelDClick;
extern UnicodeString OnRelRClick;
extern UnicodeString OnHdrRClick;
extern UnicodeString OnFScrRClick;
extern UnicodeString OnDrvDClick;
extern UnicodeString OnDrvRClick;
extern UnicodeString OnSplDClick;
extern UnicodeString OnSplRClick;
extern UnicodeString OnImgDClick;
extern UnicodeString OnTxtDClick;
extern UnicodeString OnFlIDClick;
extern UnicodeString OnTskDClick;
extern UnicodeString OnTskRClick;
extern UnicodeString OnLogDClick;
extern UnicodeString OnSttDClick;
extern UnicodeString OnSttRClick;
extern UnicodeString OnTimDClick;
extern UnicodeString OnTimRClick;
extern UnicodeString OnTvOpen;
extern UnicodeString OnTvOpened;
extern UnicodeString OnTvClose;
extern UnicodeString OnTvClosed;
extern UnicodeString OnTvTbRClick;
extern UnicodeString OnTvHRClick;
extern UnicodeString OnIvOpened;
extern UnicodeString OnIvClosed;
extern UnicodeString OnFullScr;
extern UnicodeString OnNormScr;
extern UnicodeString OnIvTbRClick;
extern UnicodeString OnIvImgDClick;
extern UnicodeString OnIvImgRClick;
extern UnicodeString OnIvMgnDClick;
extern UnicodeString OnThmDClick;
extern UnicodeString OnThmRClick;
extern UnicodeString OnIvIDClick;
extern UnicodeString OnIvSbRClick;
extern UnicodeString OnDragStartI;
extern UnicodeString OnDragEndI;
extern UnicodeString OnClipText;

struct event_rec {
	UnicodeString *sp;	//�ϐ��̃|�C���^
	const _TCHAR *key;	//�L�[��
	const _TCHAR *dsc;	//����
};

extern const event_rec EventCmdList[MAX_EVENT_CMD];

//---------------------------------------------------------------------------
#define MAX_TIMER_EVENT	2
#define MAX_TIMER_ALARM	6
extern bool Timer_Enabled[MAX_TIMER_EVENT], Timer_NopAct[MAX_TIMER_EVENT];
extern int  Timer_StartCnt[MAX_TIMER_EVENT], Timer_TimeCnt[MAX_TIMER_EVENT], Timer_NopCnt[MAX_TIMER_EVENT];
extern int  Timer_RepeatN[MAX_TIMER_EVENT], Timer_RepeatCnt[MAX_TIMER_EVENT];
extern TStringList  *Timer_AlarmList[MAX_TIMER_EVENT];
extern UnicodeString Timer_Condition[MAX_TIMER_EVENT];
extern UnicodeString OnTimerEvent[MAX_TIMER_EVENT];

//---------------------------------------------------------------------------
extern int  SortMode[MAX_FILELIST];
extern int  DirSortMode[MAX_FILELIST];

extern bool FlOdrNatural[MAX_FILELIST];
extern bool FlOdrDscName[MAX_FILELIST];
extern bool FlOdrSmall[MAX_FILELIST];
extern bool FlOdrOld[MAX_FILELIST];
extern bool FlOdrDscAttr[MAX_FILELIST];
extern bool FlOdrDscPath[MAX_FILELIST];

extern bool NaturalOrder;
extern bool DscNameOrder;
extern bool SmallOrder;
extern bool OldOrder;
extern bool DscAttrOrder;
extern bool DscPathOrder;
extern bool SortBoth;

extern TStringList *OptionList;
extern TStringList *KeyFuncList;
extern TStringList *FKeyLabelList;
extern TStringList *HotKeyList;
extern TStringList *DirStack;
extern TStringList *PathMaskList;
extern TStringList *RegDirList;
extern TStringList *ProtectDirList;
extern TStringList *ColorList;
extern TStringList *ExtColList;
extern TStringList *AssociateList;
extern TStringList *OpenStdCmdList;
extern TStringList *EtcEditorList;
extern TStringList *ExtToolList;
extern TStringList *ExtMenuList;
extern TStringList *CommandList;
extern TStringList *CmdSetList;
extern TStringList *TaskCmdList;
extern TStringList *DriveList;
extern TStringList *NetDriveList;
extern TStringList *AllDirHistory;
extern TStringList *TextViewHistory;
extern TStringList *TextEditHistory;
extern TStringList *WorkListHistory;
extern TStringList *InputDirHistory;
extern TStringList *InputCmdsHistory;
extern TStringList *InputCmdsHistoryV;
extern TStringList *InputCmdsHistoryI;
extern TStringList *IncSeaHistory;
extern TStringList *FilterHistory;
extern TStringList *WebSeaHistory;
extern TStringList *LatLngHistory;
extern TStringList *HeadlineList;
extern TStringList *ZoomRatioList;
extern TStringList *CnvCharList;
extern TStringList *RenCmdFileList;
extern TStringList *RenArcFileList;
extern TStringList *RedrawList;
extern TStringList *CmdRequestList;

extern UnicodeString LogBufStr;
extern TMultiReadExclusiveWriteSynchronizer *LogRWLock;

extern TListBox     *LogWndListBox;
extern TStringList  *LogBufList;
extern UsrScrollPanel *LogWndScrPanel;

extern int  LayoutMode;
extern bool DivFileListUD;
extern bool DivDirInfUD;

extern TFont *ListFont;
extern TFont *FileInfFont;
extern TFont *TxtPrvFont;
extern TFont *LogFont;
extern TFont *ViewerFont;
extern TFont *GrepResFont;
extern TFont *DirInfFont;
extern TFont *DrvInfFont;
extern TFont *LstHdrFont;
extern TFont *ViewHdrFont;
extern TFont *GenListFont;
extern TFont *HintFont;
extern TFont *SttBarFont;
extern TFont *CalcFont;
extern TFont *DialogFont;
extern TFont *ToolBarFont;
extern TFont *TabBarFont;
extern TFont *CharInfFont;
extern TStringList *FontList;

extern TColor col_bgList;
extern TColor col_bgList2;
extern TColor col_fgList;
extern TColor col_Splitter;
extern TColor col_bgArc;
extern TColor col_bgFind;
extern TColor col_bgWork;
extern TColor col_bgFTP;
extern TColor col_bgADS;
extern TColor col_selItem;
extern TColor col_oppItem;
extern TColor col_fgSelItem;
extern TColor col_bgMark;
extern TColor col_matchItem;
extern TColor col_Differ;
extern TColor col_Cursor;
extern TColor col_bgScrBar;
extern TColor col_bgScrKnob;
extern TColor col_frScrKnob;
extern TColor col_lnScrHit;
extern TColor col_Folder;
extern TColor col_SymLink;
extern TColor col_Protect;
extern TColor col_ReadOnly;
extern TColor col_Hidden;
extern TColor col_System;
extern TColor col_fgSpace;
extern TColor col_fgTagNam;
extern TColor col_InvItem;
extern TColor col_bgTabBar;
extern TColor col_bgActTab;
extern TColor col_bgInAcTab;
extern TColor col_frmTab;
extern TColor col_fgTab;
extern TColor col_bgListHdr;
extern TColor col_fgListHdr;
extern TColor col_bgDirInf;
extern TColor col_fgDirInf;
extern TColor col_bgDirRel;
extern TColor col_fgDirRel;
extern TColor col_bgDrvInf;
extern TColor col_fgDrvInf;
extern TColor col_bgInf;
extern TColor col_fgInf;
extern TColor col_fgInfNam;
extern TColor col_fgInfEmp;
extern TColor col_bgTxtPrv;
extern TColor col_fgTxtPrv;
extern TColor col_bgLog;
extern TColor col_fgLog;
extern TColor col_bgTask;
extern TColor col_fgPrgBar;
extern TColor col_bgPrgBar;
extern TColor col_Error;

extern TColor col_bgView;
extern TColor col_fgView;
extern TColor col_Margin;
extern TColor col_bgRuler;
extern TColor col_fgRuler;
extern TColor col_bgLineNo;
extern TColor col_LineNo;
extern TColor col_Mark;
extern TColor col_bdrLine;
extern TColor col_bdrFold;
extern TColor col_bdrFixed;
extern TColor col_Comment;
extern TColor col_Strings;
extern TColor col_Reserved;
extern TColor col_Symbol;
extern TColor col_Numeric;
extern TColor col_fgEmpBin1;
extern TColor col_fgEmpBin2;
extern TColor col_fgEmpBin3;
extern TColor col_Headline;
extern TColor col_URL;
extern TColor col_LocalLink;
extern TColor col_bgImage;
extern TColor col_bgDblPg;
extern TColor col_bgWMF;
extern TColor col_bgHint;
extern TColor col_fgHint;
extern TColor col_bgWarn;
extern TColor col_fgEmp;
extern TColor col_bgEmp;
extern TColor col_Ruby;
extern TColor col_TAB;
extern TColor col_CR;
extern TColor col_HR;
extern TColor col_Ctrl;

extern TColor col_bdrThumb;
extern TColor col_ThumbExif;
extern TColor col_ImgGrid;
extern TColor col_OptFind;
extern TColor col_Invalid;
extern TColor col_Illegal;
extern TColor col_Tim1H;
extern TColor col_Tim3H;
extern TColor col_Tim1D;
extern TColor col_Tim3D;
extern TColor col_Tim7D;
extern TColor col_Tim1M;
extern TColor col_Tim3M;
extern TColor col_Tim6M;
extern TColor col_Tim1Y;
extern TColor col_Tim3Y;
extern TColor col_TimOld;
extern TColor col_Size4G;
extern TColor col_Size1G;
extern TColor col_Size1M;
extern TColor col_Size1K;
extern TColor col_SizeLT;
extern TColor col_Size0;

extern TColor col_GrBack;
extern TColor col_GrLine;
extern TColor col_GrGrid;
extern TColor col_GrText;

extern TColor col_bgTlBar1;
extern TColor col_bgTlBar2;
extern TColor col_fgTlBar;
extern TColor col_htTlBar;
extern TColor col_bgSttBar;
extern TColor col_fgSttBar;
extern TColor col_bgInfHdr;
extern TColor col_fgInfHdr;

extern TColor col_Teal;

extern UnicodeString BgImgName[MAX_BGIMAGE];
extern Graphics::TBitmap *BgImgBuff[MAX_BGIMAGE];

extern int  BgImgMode;
extern int  BgImgSubMode;
extern int  BgColAlpha;
extern bool BgImgGray;
extern bool BgImgHideScr;
extern int  BgHideTime;
extern bool BgImgTileIf;
extern int  BgTileSize;

extern bool AlphaForm;
extern int  AlphaValue;

extern UnicodeString FontSampleTxt;
extern UnicodeString FontSampleSym;
extern int FontSampleSize;
extern TColor FontSampleFgCol;
extern TColor FontSampleBgCol;
extern TColor FontSampleGridCol;
extern bool   FontSampleShowGrid;

extern UnicodeString TextEditor;
extern UnicodeString TextEditorFrmt;
extern UnicodeString ExtTxViewer;
extern UnicodeString ExtTxViewerFrmt;

extern UnicodeString ImageEditor;
extern UnicodeString FExtImgEidt;
extern bool ImageEditSgl;

extern UnicodeString FExtViewTab4;
extern UnicodeString FExtViewTabX;
extern int  ViewTabWidthX;

extern UnicodeString BinaryEditor;
extern UnicodeString SoundTaskFin;
extern UnicodeString SoundFindFin;
extern UnicodeString SoundWarning;
extern UnicodeString SoundWatch;

extern int  FlashCntWarning;
extern int  FlashTimeWarning;
extern int  FlashCntTaskfin;
extern int  FlashTimeTaskfin;

extern int  MaxLogLines;
extern int  MsgHintTime;
extern int  KeyHintTime;
extern int  NotifyTaskTime;
extern int  CmpDelOwCnt;
extern int  ViewTxtInterLn;
extern int  ViewLeftMargin;
extern int  ViewFoldWidth;
extern bool ViewFoldFitWin;
extern bool TvCursorVisible;
extern bool LimitBinCsr;
extern bool TxtColorHint;
extern bool BinMemMaped;
extern int  ViewFixedLimit;
extern int  ViewTxtLimitSize;
extern int  ViewBinLimitSize;
extern int  ListWheelScrLn;
extern int  ViewWheelScrLn;
extern int  PlaySndLimitTime;
extern bool ShowTextPreview;
extern int  PrvTxtInfLn;
extern bool ShowTailPreview;
extern int  PrvTxtTailLn;
extern int  PrvActTailLn;
extern int  WatchInterval;
extern int  LogInterval;
extern int  ListInterLn;
extern int  CursorWidth;
extern int  CursorAlpha;
extern int  CellAlpha;
extern int  SplitterWidth;
extern int  SplitterWidth2;
extern int  SizeFormatMode;
extern int  SizeDecDigits;
extern int  ListPercent;
extern int  ImgFrameMargin;
extern int  ImgFitMaxZoom;
extern int  ImgGridHorzN;
extern int  ImgGridVertN;
extern int  MinShowTime;
extern int  ThumbnailSize;
extern int  ThumbBdrWidth;
extern int  ThumbnailPos;
extern int  ImgDblMargin;

extern bool ShowImgSidebar;
extern bool ImgSidebarIsLeft;

extern bool HasCallHotkey;

extern bool HideSizeTime;

//---------------------------------------------------------------------------
//�t�@�C�����X�g�̍���
//---------------------------------------------------------------------------
struct file_rec {
	UnicodeString f_name;		//�p�X�t�t�@�C����
	UnicodeString p_name;		//�p�X��
	UnicodeString n_name;		//�p�X���t�@�C����
	UnicodeString b_name;		//�t�@�C�����啔
	UnicodeString f_ext;		//�g���q
	UnicodeString attr_str;		//����������
	UnicodeString alias;		//�G�C���A�X
	UnicodeString arc_name;		//�A�[�J�C�u��
	UnicodeString tmp_name;		//�ꎞ�𓀖�
	UnicodeString r_name;		//�\����
	UnicodeString l_name;		//�����N��
	UnicodeString memo;			//�x�}�[�N���ڂ̃���(���e \t �ݒ����)  �x�}�[�N�ꗗ�Ŏg�p
	UnicodeString tags;			//�^�O
	UnicodeString hash;			//�n�b�V��

	int  tag;					//0: ��/ 1: �E
	bool is_up;					//..
	bool is_dir;				//�f�B���N�g��
	bool is_sym;				//���p�[�X�|�C���g
	bool is_jct;				//�W�����N�V����
	bool is_virtual;			//���z�f�B���N�g�����̃t�@�C��
	bool is_ftp;				//FTP
	bool is_ads;				//��փf�[�^�X�g���[��
	bool is_dummy;				//�_�~�[(��̃h���C�u�A���[�N���X�g�̃Z�p���[�^�A��r���ʂ̕s�ݍ��ڂȂ�)
	bool selected;				//�I��
	bool matched;				//�C���N�������^���Ń}�b�`
	bool failed;				//�t�@�C���[: �ꎞ�𓀎��s/  �C���[�W�r���A�[: �Ǎ����s

	__int64 f_size;				//�T�C�Y
	__int64 o_size;				//�f�B�X�N��̐�L�T�C�Y
	__int64 c_size;				//���k�T�C�Y

	int  f_attr;				//����
	TDateTime f_time;			//�^�C���X�^���v
	int  f_count;				//�t�@�C����
	int  d_count;				//�f�B���N�g����
	int  img_ori;				//�摜����
	bool is_video;				//����

	TStringList *inf_list;		//��񃊃X�g
	UnicodeString prv_text;		//�e�L�X�g�v���r���[
	UnicodeString tail_text;	//�e�L�X�g�v���r���[(����)
};

//---------------------------------------------------------------------------
//�t�@�C�����X�g�̏��
//---------------------------------------------------------------------------
struct flist_stt {
	UnicodeString vol_name;		//�{�����[����
	__int64 drive_Used;			//�h���C�u�g�p�e��
	__int64 drive_Free;			//�h���C�u�󂫗e��
	__int64 drive_Total;		//�h���C�u�S�̗e��
	__int64 cur_total;			//�J�����g�̍��v�T�C�Y
	__int64 occ_total;			//�J�����g�̐�L�T�C�Y
	__int64 cmp_total;			//�J�����g�̈��k�T�C�Y
	int clu_size;				//�N���X�^�T�C�Y

	int f_cnt;					//�t�@�C����
	int d_cnt;					//�f�B���N�g����
	int f_cnt_total;
	int d_cnt_total;
	int sel_f_cnt;				//�I���t�@�C����
	int sel_d_cnt;				//�I���f�B���N�g����
	__int64 sel_size;			//�I���T�C�Y

	bool show_f_d_cnt;			//�t�@�C���A�f�B���N�g������\��
	bool dir_graph;				//�f�B���N�g���e�ʂ��O���t�\��(�΃J�����g)
	bool dsk_graph;				//�f�B���N�g���e�ʂ��O���t�\��(�΃h���C�u)
	bool sub_counted;			//�T�u�f�B���N�g���������ׂăJ�E���g�ς�

	int lwd_half;				//"X" �̕�
	int lwd_fext_max;			//".WWWWWWWWWWWW" �̕�

	int lwd_fext;				//�g���q�̕\����
	int lwd_size;				//�T�C�Y�̕\����
	int lwd_time;				//�^�C���X�^���v�̕\����
	int lwd_path;				//�ꏊ�̕\����(�������X�g)

	int lxp_fext;				//�g���q�̕\���ʒu
	int lxp_size;				//�T�C�Y�̕\���ʒu
	int lxp_time;				//�^�C���X�^���v�̕\���ʒu
	int lxp_path;				//�ꏊ�̕\���ʒu
	int lxp_right;				//���[�ʒu

	TColor color_bgDirInf;		//.NyanFi �ɂ��ʐF
	TColor color_fgDirInf;
	TColor color_bgDrvInf;
	TColor color_fgDrvInf;
	TColor color_Cursor;
	TColor color_selItem;

	bool is_TabFixed;			//�^�u�ύX�ɑ΂��ăp�X�Œ�

	bool is_Work;				//���[�N���X�g
	bool is_FTP;				//FTP�����[�g��

	bool is_Arc;				//���z�f�B���N�g��
	UnicodeString arc_DspPath;	//�A�[�J�C�u�̕\���p�X
	UnicodeString arc_SubPath;	//�A�[�J�C�u�ȉ��̃T�u�f�B���N�g��
	UnicodeString arc_Name;		//�A�[�J�C�u�t�@�C����(temp)
	TStringList  *arc_RetList;	//���d�A�[�J�C�u�p�̖߂胊�X�g
	TStringList  *arc_TmpList;	//�ꎞ�𓀃f�B���N�g�����X�g

	bool is_ADS;				//��փf�[�^�X�g���[��
	UnicodeString ads_Name;		//���C���X�g���[���̃t�@�C����

	UnicodeString LibraryInfo;	//���C�u�����t�@�C���� \t �p�X
	UnicodeString LibSubPath;

	bool is_Find;				//�������ʃ��X�g
	bool is_narrow;				//�i�荞��
	bool find_Loaded;			//�t�@�C������ǂݍ��񂾃��X�g

	bool find_Dir;				//�f�B���N�g������
	bool find_Both;				//�t�@�C���E�f�B���N�g������
	bool find_SubDir;			//�T�u�f�B���N�g��������
	bool find_Arc;				//�A�[�J�C�u��������

	bool find_MARK;				//�}�[�N����
	bool find_TAG;				//�^�O����
	bool find_TAG_all;			//���ׂẴ^�O�Ƀ}�b�`
	bool find_DUPL;				//�d���t�@�C���̌���
	bool find_HLINK;			//�n�[�h�����N��

	bool find_RegEx;			//���K�\��
	bool find_And;				//AND����
	bool find_Case;				//�召�������

	bool find_Warn;				//�D�܂����Ȃ��t�@�C����
	bool find_hasAds;			//��փf�[�^�X�g���[��������
	bool find_useProc;			//�ʃv���Z�X���g�p��

	bool find_ResLink;			//���ʃ��X�g���甽�Α��֔��f
	bool find_DirLink;			//�f�B���N�g�����𔽉f
	bool find_PathSort;			//�ꏊ���Ń\�[�g

	UnicodeString find_Path;	//�����p�X
	UnicodeString find_Name;	//������(�n�[�h�����N�p)
	UnicodeString find_Mask;	//�}�X�N
	UnicodeString find_Keywd;	//�L�[���[�h
	UnicodeString find_Tags;	//�^�O

	TStringList  *find_SubList;	//�I���T�u�f�B���N�g��
	int  find_DT_mode;			//���t����
	TDateTime find_DT_value;
	UnicodeString find_DT_str;
	int  find_SZ_mode;			//�T�C�Y����
	__int64 find_SZ_value;
	int  find_CT_mode;			//���e����
	int  find_AT_mode;			//��������
	int  find_AT_value;

	int  find_TM_mode;			//�^�C��
	TTime find_TM_value;

	int  find_codepage;			//�R�[�h�y�[�W
	UnicodeString find_LineBrk;	//���s�R�[�h
	int  find_BOM_mode;			//BOM

	int  find_RT_mode;			//���C�g
	int  find_RT_value;
	int  find_FS_mode;			//�t���[����
	int  find_FS_value;
	int  find_FW_mode;			//�t���[����
	int  find_FW_value;
	int  find_FH_mode;			//�t���[����
	int  find_FH_value;

	int  find_IW_mode;			//�摜�T�C�Y
	unsigned int find_IW_value;
	int  find_IH_mode;
	unsigned int find_IH_value;
	bool find_IWH_max;

	int  find_SR_mode;			//�T���v�����O���[�g
	int  find_SR_value;
	int  find_BT_mode;			//�r�b�g
	int  find_CH_mode;			//�`�����l��

	int  find_IC_mode;			//�A�C�R��
	int  find_IC_value;

	int  find_HL_mode;			//�����N�J�E���g��
	int  find_HL_value;

	UnicodeString find_PrpKwd;
	bool find_PrpRegEx;
	bool find_PrpAnd;
	bool find_PrpCase;

	UnicodeString find_TxtKwd;
	bool find_TxtRegEx;
	bool find_TxtAnd;
	bool find_TxtCase;

	UnicodeString find_ExifKwd;
	bool find_ExifRegEx;
	bool find_ExifAnd;
	bool find_ExifCase;

	UnicodeString find_LatLng;
	double find_GpsLat;
	double find_GpsLng;
	int    find_GpsRange;

	bool is_IncSea;				//�C���N�������^���T�[�`��
	bool is_Migemo;				//Migomo���[�h
	bool is_Filter;				//�t�B���^���[�h
	bool filter_sens;			//�t�B���^�ő召���������
	UnicodeString incsea_Word;
	UnicodeString incsea_Ptn;
	int incsea_MatchCnt;
};

extern flist_stt ListStt[MAX_FILELIST];
extern flist_stt *CurStt;
extern flist_stt *OppStt;

#define DEF_PATH_COLWD	150

//---------------------------------------------------------------------------
//�h���C�u���
//---------------------------------------------------------------------------
struct drive_info {
	UnicodeString drive_str;
	bool		  accessible;
	bool		  ejectable;
	int			  drv_type;
	UnicodeString type_str;
	UnicodeString volume;
	UnicodeString unc;
	UnicodeString f_system;
	UnicodeString bus_type;
	bool		  is_NTFS;
	bool		  is_SSD;
	bool		  is_RAM;
	TIcon		  *small_ico;
	TIcon		  *large_ico;
};

//---------------------------------------------------------------------------
//�^�u���X�g
//---------------------------------------------------------------------------
struct tab_info {
	TRect rc;	//�`��̈�
	TStringList *sel_list[MAX_FILELIST];	//�I�����
	TStringList *dir_hist[MAX_FILELIST];	//�f�B���N�g������
	int			 dir_hist_p[MAX_FILELIST];	//�����ʒu
};

//---------------------------------------------------------------------------
//�R�}���h�t�@�C�����X�g
//---------------------------------------------------------------------------
struct cmdf_rec {
	TDateTime   f_time;			//�^�C���X�^���v
	TStringList *file_buf;		//�t�@�C�����e
	TStringList *cmd_list;		//�R�}���h���X�g
	int exe_count;				//���s��
	bool noreload;				//�ēǂݍ��݂��Ȃ�
};
extern TStringList *CmdFileList;
extern TStringList *XCMD_VarList;

//---------------------------------------------------------------------------
//�C�����C���֐�
//---------------------------------------------------------------------------
inline bool is_AltLnBgCol(int idx)
{
	return (col_bgList2!=Graphics::clNone && idx%2==1);
}

inline bool is_SelFgCol(TOwnerDrawState stt)
{
	return (stt.Contains(odSelected) && col_fgSelItem!=Graphics::clNone);
}
inline bool is_SelFgCol(TGridDrawState stt)
{
	return (stt.Contains(gdSelected) && col_fgSelItem!=Graphics::clNone);
}
inline bool is_SelFgCol(bool sel)
{
	return (sel && col_fgSelItem!=Graphics::clNone);
}

inline bool is_X64()
{
#if defined(_WIN64)
	return true;
#else
	return false;
#endif
}

//---------------------------------------------------------------------------
//�X�P�[�����O���ꂽ�����l���擾
inline int ScaledInt(int n)
{
	return (int)(n * ScrScale);
}

inline int get_IcoWidth()
{
	return (int)(20 * ScrScale);
}

inline int min_ItemHeight(int tag)
{
	return (tag & LBTAG_HAS_SICO)? (int)(20 * ScrScale) : 0;
}

//---------------------------------------------------------------------------
//�\�[�g���[�h
inline int CurSortMode()
{
	return (CurStt->is_Find && CurStt->find_PathSort)? 6 : SortMode[CurListTag];
}

inline int TagSortMode(int tag)
{
	return (ListStt[tag].is_Find && ListStt[tag].find_PathSort)? 6 : SortMode[tag];
}

//---------------------------------------------------------------------------
inline int CompTextN(UnicodeString s0, UnicodeString s1)
{
	if (DscNameOrder) std::swap(s0, s1);	//���O�p
	return NaturalOrder? StrCmpLogicalW(s0.c_str(), s1.c_str()) : CompareText(s0, s1);
}
//---------------------------------------------------------------------------
inline int CompTextN2(UnicodeString s0, UnicodeString s1)
{
	if (DscPathOrder) std::swap(s0, s1);	//�ꏊ�p
	return NaturalOrder? StrCmpLogicalW(s0.c_str(), s1.c_str()) : CompareText(s0, s1);
}

//---------------------------------------------------------------------------
int __fastcall CompDirName(file_rec *fp0, file_rec *fp1);
int __fastcall CompDirTime(file_rec *fp0, file_rec *fp1);
int __fastcall CompDirSize(file_rec *fp0, file_rec *fp1);
int __fastcall CompDirAttr(file_rec *fp0, file_rec *fp1);

int __fastcall SortComp_Name(TStringList *List, int Index1, int Index2);
int __fastcall SortComp_Ext( TStringList *List, int Index1, int Index2);
int __fastcall SortComp_Time(TStringList *List, int Index1, int Index2);
int __fastcall SortComp_Size(TStringList *List, int Index1, int Index2);
int __fastcall SortComp_Attr(TStringList *List, int Index1, int Index2);
int __fastcall SortComp_DirOnly(TStringList *List, int Index1, int Index2);
int __fastcall SortComp_PathName(TStringList *List, int Index1, int Index2);
int __fastcall SortComp_Tags(TStringList *List, int Index1, int Index2);
int __fastcall SortComp_Memo(TStringList *List, int Index1, int Index2);
int __fastcall SortComp_MarkTime(TStringList *List, int Index1, int Index2);

int __fastcall KeyComp_Key(TStringList *List, int Index1, int Index2);
int __fastcall KeyComp_Cmd(TStringList *List, int Index1, int Index2);
int __fastcall KeyComp_Dsc(TStringList *List, int Index1, int Index2);

//---------------------------------------------------------------------------
UnicodeString yen_to_delimiter(UnicodeString s);
UnicodeString get_MiniPathName(UnicodeString pnam, int wd, TFont *font, bool rep_delimiter = false);;

UnicodeString get_dotNaynfi(UnicodeString dnam = EmptyStr);
UnicodeString get_dotNaynfi(UnicodeString dnam, bool inherit, bool force = false);

UnicodeString get_WebSeaCaption(UnicodeString kwd = EmptyStr);

bool is_NewerTime(TDateTime scr_t, TDateTime dst_t);

bool check_if_unc(UnicodeString pnam);

UnicodeString get_cmdfile(UnicodeString s);
UnicodeString get_cmds_prm_file(UnicodeString prm);

UnicodeString make_ResponseFile(TStringList *lst, int arc_t, UnicodeString *files = NULL, bool excl = false);
UnicodeString make_ResponseFile(UnicodeString fnam, int arc_t);

UnicodeString format_CloneName(UnicodeString fmt, UnicodeString fnam, UnicodeString dst_dir, bool is_dir = false,
	TDateTime *ts = NULL, TStringList *lst = NULL);

UnicodeString format_FileName(UnicodeString fmt, UnicodeString fnam);

TStringList *CreStringList(int obj_type = 0);

UnicodeString get_SrcHdrName(UnicodeString fnam);
UnicodeString get_NextSameName(UnicodeString fnam, bool only_text = false);
UnicodeString get_NextSameName(TStringList *lst, int idx, bool only_text = false);

void get_LibraryList(UnicodeString fnam, TStringList *lst, bool get_info = false);
UnicodeString get_LibFile_if_root();

UnicodeString get_SyncDstList(UnicodeString dnam, TStringList *lst, bool del_sw = false, UnicodeString ex_dnam = EmptyStr);
bool has_SyncDir(UnicodeString dnam, bool del_sw = false);
UnicodeString is_SyncDir(UnicodeString dnam1, UnicodeString dnam2);

void SetTempPathA(UnicodeString dnam);
void ClearTempDir(UnicodeString dnam = EmptyStr);
void ClearTempArc(UnicodeString dnam = EmptyStr);
void ClearTempArcList(int tag);

UnicodeString UpdateTempArcList(int tag = -1);
bool SetTmpFile(file_rec *fp, bool not_unpk = false, bool show_prg = false);
UnicodeString ExtractInZipImg(UnicodeString arc_file, UnicodeString img_fext);

void add_PackItem(file_rec *fp, int arc_t, UnicodeString src_dir, TStringList *lst);

bool is_InvalidUnc(UnicodeString dnam, bool del_sw = false);
UnicodeString CheckAvailablePath(UnicodeString dnam, int tag);

TStringList *GetCurBtnList(int scr_mode = ScrMode);

TStringList* GetFileList(int tag);
TStringList* GetCurList(bool only_filer = false);
TStringList* GetOppList();
TColor get_FlBgColor(flist_stt *lst_stt, int idx = 0);

bool ListSelected(TStringList *lst);
int  GetSelCount(TStringList *lst);
void GetSelList(TStringList *lst, TStringList *sel_lst, bool with_path = true, bool with_obj = false);
void ClrSelect(TStringList *lst = NULL);
void SortList(TStringList *lst, int tag = CurListTag);
int  IndexOfFileList(UnicodeString fnam, int tag = CurListTag, int top_idx = -1);
file_rec* ExistsInList(UnicodeString fnam, TStringList *lst);
UnicodeString GetSelFileStr(TStringList *lst, bool use_tmp = false, bool inc_dir = false, TStringList *s_lst = NULL);

file_rec* cre_new_file_rec(file_rec *copy_fp = NULL);
file_rec* cre_new_file_rec(UnicodeString fnam, int tag = -1, bool force = false);
file_rec* cre_new_up_rec(int tag);

void del_file_rec(file_rec *fp);
void inv_file_rec(file_rec *fp);

bool is_selectable(file_rec *fp);
bool set_select(file_rec *fp, bool sw = true);
bool set_select_r(file_rec *fp);

void clear_FileList(TStringList *lst);
void del_FileListItem(TStringList *lst, int idx);

void swap_FileList(TStringList *lst1, TStringList *lst2, bool swap_tag = true);

tab_info* cre_tab_info();
int  add_TabList(UnicodeString item);
void insert_TabList(int idx, UnicodeString item);
void del_tab_info(tab_info *tp);
tab_info *get_TabInfo(int tab_idx = -1);
TStringList *get_DirHistory(int tab_idx = -1, int tag = CurListTag);
int  *get_DirHistPtr(int tab_idx = -1, int tag = CurListTag);
void clear_DirHistory(int tab_idx = -1, int tag = CurListTag);
UnicodeString get_TabWorkList(int tab_idx);
bool save_TagGroup(UnicodeString fnam);

void clear_FindStt(flist_stt *lst_stt);
bool check_int(int v0, int v1, int mode);
bool check_prop(UnicodeString fnam, UnicodeString prop, int v, int mode);
bool check_file_std(UnicodeString fnam, TDateTime f_tm, __int64 f_sz, int f_atr, flist_stt *lst_stt);
bool check_file_ex(UnicodeString fnam, flist_stt *lst_stt);

UnicodeString get_FontInf(UnicodeString fnam, TStringList *lst = NULL);

drive_info *get_DriveInfoList();
drive_info *get_DriveInfo(UnicodeString dstr);
void update_DriveVolume();

void get_DriveLogList(UnicodeString dstr, TStringList *lst, double &r_min, double &r_max);
void update_DriveLog(bool save = false);

void get_ArcList(UnicodeString anam, UnicodeString dnam, TStrings *f_lst, TStrings *d_lst);

void set_ListBoxItemHi(TListBox *lp, TFont *font = NULL);
void set_ListBoxItemHi(TCheckListBox *lp, TFont *font = NULL);

void set_StdListBox(TListBox *lp, int tag = 0, TFont *font = NULL);
void set_StdListBox(TCheckListBox *lp, int tag = 0, TFont *font = NULL);

void set_UsrScrPanel(UsrScrollPanel *sp);
void set_FextWidth(file_rec *fp, int tag);

void assign_FileListBox(TListBox *lp, TStringList *lst, int idx = -1, UsrScrollPanel *sp = NULL);
void update_VirtualFileListBox(TStrings *lst, TListBox *lp, int idx = -1, UsrScrollPanel *sp = NULL);

bool get_Files_objSize(UnicodeString pnam, TStrings *lst, bool exc_sym);
bool get_NameList_objSize(TStringList *lst, TStringList *o_lst, bool sub_sw, bool exc_sym);
void get_FindListF(UnicodeString pnam, flist_stt *lst_stt, TStrings *lst, int tag);
void get_FindListD(UnicodeString pnam, flist_stt *lst_stt, TStrings *lst, int tag);
void get_SubDirs(UnicodeString pnam, TStrings *lst, TStatusBar *stt_bar = NULL, int stt_idx = 0, bool proc_msg = false);

__int64 get_DirSize(UnicodeString dnam, int *f_cnt, int *d_cnt, __int64 *o_size, __int64 *c_size);
__int64 get_ArcDirSize(UnicodeString anam, UnicodeString dnam, int *f_cnt, int *d_cnt);

void del_CachedIcon(UnicodeString fnam);
HICON get_fext_icon(UnicodeString fext = EmptyStr);
bool draw_SmallIcon(file_rec *fp,       TCanvas *cv, int x, int y, bool force_cache = false);
bool draw_SmallIcon2(UnicodeString fnam, TCanvas *cv, int x, int y);
int  add_IconImage(UnicodeString fnam, TImageList *lst);

UnicodeString get_file_from_cmd(UnicodeString s);
void SetExtNameToCtrl(UnicodeString fnam, TWinControl *cp, bool nbt_sw = false);

bool load_MenuFile(UnicodeString fnam, TStringList *lst);

bool load_WorkList(UnicodeString wnam);
bool save_WorkList(UnicodeString wnam, TStringList *lst = NULL);

bool load_FontSample(UnicodeString fnam);
bool save_FontSample(UnicodeString fnam);

int  find_NextFile(TStringList *lst, int idx, UnicodeString fext = EmptyStr, UnicodeString keywd = EmptyStr,
		bool skip_dir = true, bool circular = true, bool case_sns = false, bool regex = true, bool with_tag = false);
int  find_PrevFile(TStringList *lst, int idx, UnicodeString fext = EmptyStr, UnicodeString keywd = EmptyStr,
		bool skip_dir = true, bool circular = true, bool case_sns = false, bool regex = true, bool with_tag = false);

int to_NextFile(TStringList *lst, int idx);
int to_PrevFile(TStringList *lst, int idx);

int  get_ViewCount();

bool delete_File(UnicodeString fnam, bool use_trash = false);
void delete_FileIf(UnicodeString fnam);

TStringDynArray get_AssociatedApps(UnicodeString fext);
void make_AssoMenuList(TStringDynArray app_lst, TStringList *lst);

void InvColIfEmpty(TLabeledEdit *ep);
void InvColIfEmpty(TEdit *ep);

TColor get_FileColor(file_rec *fp, TColor col_x);
TColor get_ExtColor(UnicodeString fext);
TColor get_TimeColor(TDateTime dt, TColor col_def);
TColor get_SizeColor(__int64 size, TColor col_def);

UnicodeString get_DirNwlName(UnicodeString pnam);
UnicodeString get_DispName(file_rec *fp);
UnicodeString get_RegDirName(UnicodeString pnam);
UnicodeString UNC_to_NetDriveName(UnicodeString pnam);
UnicodeString NetDriveName_to_UNC(UnicodeString pnam);
UnicodeString get_RegDirItem(int idx);
UnicodeString get_RegDirItem(WideChar key);
void move_top_RegDirItem(int idx);
UnicodeString get_LRUD_str(int tag = CurListTag, bool both = false);

bool is_ProtectDir(UnicodeString dnam);
void GetFileInfList(file_rec *fp, bool force = false);
UnicodeString get_FileInfValue(file_rec *fp, UnicodeString tit, UnicodeString dlmt = EmptyStr);

void assign_InfListBox(TListBox *lp, TStringList *i_lst, UsrScrollPanel *sp = NULL);
void draw_InfListBox(TListBox *lp, TRect &Rect, int Index, TOwnerDrawState State);
void draw_ColorListBox(TListBox *lp, TRect &Rect, int Index, TOwnerDrawState State, TStringList *col_lst);

void draw_InputPaintBox(TPaintBox *pp, UnicodeString s);

UnicodeString get_FileSizeStr(__int64 sz, bool trim = false);
UnicodeString get_FileInfStr(file_rec *fp, bool with_atr = true);
UnicodeString get_FileInfStr(UnicodeString fnam, bool with_atr = true);
void get_FileNamePathInf(UnicodeString fnam, TStringList *lst, bool get_app = false);

bool get_FileInfList(file_rec *fp, TStringList *lst);

bool is_Processing(file_rec *fp, UnicodeString *err_msg = NULL);
bool is_Processing(UnicodeString fna, bool is_video = false, UnicodeString *err_msg = NULL);

bool is_NoInfPath(file_rec *fp, UnicodeString no_path);

UnicodeString get_StreamLineBreak(TStream *ms, int code_page, bool strict = false);
int  get_FileCodePage(UnicodeString fnam, UnicodeString *line_brk = NULL, bool *has_bom = NULL);
bool is_TextFile(UnicodeString fnam, int *code_page = NULL, UnicodeString *line_brk = NULL, bool *has_bom = NULL);

int  CountListLines(TStringList *lst, UnicodeString fnam, int *rem_cnt, int *blk_cnt);

UnicodeString get_IniTypeStr(file_rec *fp);

bool is_MenuFile(file_rec *fp);
bool is_ResultList(file_rec *fp);
bool is_AudioVideo(UnicodeString fnam);
bool is_ViewableFext(UnicodeString fext);
bool is_Viewable(file_rec *fp);
bool is_ExtractIcon(file_rec *fp);

bool test_ArcExt(UnicodeString fext);
bool test_ArcExt2(UnicodeString fext);
bool is_AvailableArc(UnicodeString fnam);
bool test_TxtFile(UnicodeString fnam);
bool test_NonTxtExt(UnicodeString fext);

UnicodeString get_img_fext();

void add_FExtInfList(TStringList *f_lst, TStringList *lst);

bool get_img_size(UnicodeString fnam, unsigned int *wd, unsigned int *hi);
int  load_ImageFile(UnicodeString fnam, Graphics::TBitmap *o_bmp, int img_type = WICIMG_PREVIEW, TColor trans_bg = Graphics::clNone);

int  ScaledInt(int n);

void InitializeGlobal();
void EndGlobal();

void SetupTimer();
void ClearNopStt();

void LoadOptions();
void SaveOptions();
void UpdateIniFile();

void BringOptionByTag(TForm *fp);
int  GetOptionIntDef(int tag);
void ApplyOptionByTag(TForm *fp);

void InitializeListGrid(TStringGrid *gp, TFont *fnt = NULL);
void InitializeListHeader(THeaderControl *hp, const _TCHAR *hdr, TFont *fnt = NULL);

void set_ComboBox_AutoComp(TForm *frm);
void set_MigemoCheckBox(TCheckBox *cp, const _TCHAR *key, UnicodeString sct = EmptyStr);
void change_ComboBoxHistory(TComboBox *cp, const _TCHAR *nrm_sct, const _TCHAR *reg_sct, bool reg_sw);

void filter_List(TStringList *i_lst, TStringList *o_lst, UnicodeString kwd,
	bool migemo_sw, bool and_or_sw = false, bool csv_sw = false, bool tsv_sw = false, bool tree_sw = false);

UnicodeString get_CmdStr(UnicodeString s);
UnicodeString get_PrmStr(UnicodeString s);

UnicodeString Key_to_CmdF(UnicodeString key);
UnicodeString Key_to_CmdV(UnicodeString key);

UnicodeString get_CmdDesc(UnicodeString cmd, bool only_inf = false,
	TStrings *menu_list = NULL, TStrings *tool_list = NULL, bool is_TV = false);

UnicodeString del_CmdDesc(UnicodeString cmd);

TColor read_ColorList(UnicodeString key, TColor def, TStringList *lst = NULL);
TColor read_ColorList(const _TCHAR *key, TColor def, TStringList *lst = NULL);
void set_col_from_ColorList();

void add_TextEditHistory(UnicodeString fnam);

bool register_HotKey(int id, UnicodeString kstr);

void set_FormTitle(TForm *frm, const _TCHAR *s);

void beep_Warn(UnicodeString fnam = EmptyStr);
void flash_win(int cnt = 0, int tm = 0);

bool mute_Volume(UnicodeString prm);

bool play_sound(UnicodeString fnam);
bool play_sound_ex(UnicodeString fnam, bool limit = true);
bool add_PlayFile(UnicodeString fnam);
bool add_PlayList(UnicodeString lnam);
bool play_PlayList(bool prev = false, bool inh_shfl = false);

void set_CloseButton(bool enabled);

int  get_TabTextWidth(UnicodeString s, TCanvas *cv, int tab_wd);

void out_Text(TCanvas *cv, int x, int y, const _TCHAR *s);
void out_Text(TCanvas *cv, int x, int y, const _TCHAR *s, TColor fg);

int  get_MatchWordList(UnicodeString lbuf, UnicodeString kwd, bool migemo_sw, bool regex_sw, bool and_or_sw, TStringList *lst);

void EmphasisTextOut(UnicodeString s, TStringList *kw_lst, TCanvas *cv, int &x, int y,
	bool case_sns = false, bool only_top = false, TColor fg = col_fgEmp, TColor bg = col_bgEmp);
void EmphasisTextOut(UnicodeString s, UnicodeString kwd, TCanvas *cv, int &x, int y,
	bool case_sns = false, bool only_top = false, TColor fg = col_fgEmp, TColor bg = col_bgEmp);

void draw_TAB(TCanvas *cv, int x, int y, int w, int h);
void draw_CR(TCanvas *cv, int x, int y, int w, int h);
void TabCrTextOut(UnicodeString s, TCanvas *cv, int &x, int y, TColor fg = col_fgList, int max_x = 0);
void RuledLnTextOut(UnicodeString s, TCanvas *cv, TRect &rc, TColor fg, int tab_wd = 8, TStringList *kw_lst = NULL);

void PrvTextOut(TListBox *lp, int idx, TCanvas *cv, TRect &rc, TColor fg,
	int tab_wd, TStringList *kw_lst = NULL, UnicodeString fnam = EmptyStr, bool en_mlt = true);

void LineNoOut(TCanvas *cv, TRect &rc, UnicodeString l_str);
void LineNoOut(TCanvas *cv, TRect &rc, int l_no);

void PathNameOut(UnicodeString s, TStringList *kw_lst, TCanvas *cv, int &x, int y, bool mgn_sw = true);
void PathNameOut(UnicodeString s, TCanvas *cv, int &x, int y, int w = 0);
void FileNameOut(TCanvas *cv, TRect &rc, UnicodeString fnam, bool use_fgsel,
	bool to_slash = false, TStringList *kw_lst = NULL);

void RloPipeTextOut(UnicodeString s, TCanvas *cv, int &x, int y, TColor fg);
void SpaceTextOut(UnicodeString s, TCanvas *cv, int &x, int y, TColor fg);

void Emphasis_RLO_info(UnicodeString fnam, TCanvas *cv, int xp, int yp);

bool draw_SttBarBg(TStatusBar *sp, TMessage &msg);
bool draw_InfHdrBg(TStatusBar *sp, TMessage &msg);

void draw_SortHeader(THeaderControl *hp, THeaderSection *sp, TRect rc, int mk_mode = 0, bool use_syscol = false);
void draw_ListCursor(TListBox *lp, TRect &Rect, int Index, TOwnerDrawState State);
void draw_ListCursor2(TListBox *lp, TRect &Rect, int Index, TOwnerDrawState State);
void draw_GridCursor(TStringGrid *gp, TRect &Rect, int ARow, TGridDrawState State);
void draw_ImgGrid(TCanvas *cv, Graphics::TBitmap *bmp);
void draw_BarGraph(TCanvas *cv, TRect rc, double r);
void draw_ProgressBar(TCanvas *cv, TRect rc, double r);

void draw_BottomTab(TCustomTabControl *Control, int idx, const TRect rc, bool active);

bool saveto_TextUTF8(UnicodeString fnam, TStrings *lst);
bool saveto_TextFile(UnicodeString fnam, TStrings *lst, TEncoding *enc = NULL);
bool saveto_TextFile(UnicodeString fnam, TStrings *lst, int enc_idx);

#define TXLIMIT_MARK "\x03\x03\x03"	//�s�������}�[�N

int  load_text_ex(UnicodeString fnam, TStringList *f_buf, int code_page = 0, int limit_size = 0,
	bool force_txt = false, UnicodeString *line_brk = NULL, bool *has_bom = NULL, double *ave_lsz = NULL);

int  load_text_tail(UnicodeString fnam, TStringList *f_buf, int code_page = 0, int limit_ln = 100,
	bool reverse = false, UnicodeString *line_brk = NULL);
bool check_text_tail(UnicodeString fnam, int &code_page, int size, UnicodeString kwd, TStringList *lst);

void get_xml_inf(UnicodeString fnam, TStringList *lst);

UnicodeString get_autorun_ico(UnicodeString fnam);

bool divide_FileName_LineNo(UnicodeString &fnam, int &lno, UnicodeString rnam, int pos = 0);
UnicodeString get_tags_file(UnicodeString rnam);
int  get_FileNameByTag(UnicodeString tnam, UnicodeString &rnam, TStringList *lst, UnicodeString onam = EmptyStr);

bool open_by_TextEditor(UnicodeString fnam, int lno = 0);
bool open_by_ExtTextViewer(UnicodeString fnam, int lno = 0);

void ini_HtmConv_def(HtmConv *htmcnv, UnicodeString fnam = EmptyStr);

bool Execute_ex(UnicodeString cmd, UnicodeString prm = EmptyStr, UnicodeString wdir = EmptyStr,
		UnicodeString opt = EmptyStr, DWORD *exit_code = NULL, TStringList *o_lst = NULL);
bool Execute_cmdln(UnicodeString cmdln, UnicodeString wdir = EmptyStr,
		UnicodeString opt = EmptyStr, DWORD *exit_code = NULL, TStringList *o_lst = NULL);

int  get_BusyTaskCount();
int  get_MaxTaskCount();
bool has_EmptyTask(bool ex_sw = false);

TTaskThread * CreTaskThread(TaskConfig **cp, bool reserve = true, bool force = false, bool ext_sw = false);
void ActivateTask(TTaskThread *tp, TaskConfig *cp);
void StartReserve();
bool StartReserve(int idx, bool ext_sw = false);
void RequestSlowTask();

UnicodeString get_LogErrMsg(UnicodeString msg = EmptyStr, bool add_cr = true, UnicodeString fnam = EmptyStr);
void set_LogErrMsg(UnicodeString &msg, UnicodeString s = EmptyStr, UnicodeString fnam = EmptyStr);

int get_TopMargin(TCanvas *cv);
int get_TopMargin2(TCanvas *cv);

UnicodeString GetClockStr();

void RenameOptCmdFile();
UnicodeString get_ref_CmdFile(UnicodeString fnam, TStringList *lst = NULL);

UnicodeString get_Alias_KeyStr(UnicodeString alias, TStringList *k_lst = NULL);

UnicodeString extract_ExeParam(UnicodeString prm, UnicodeString *dsc = NULL);

UnicodeString make_PathMask(UnicodeString mask, UnicodeString def_desc = EmptyStr);

UnicodeString make_LogHdr(UnicodeString cmd, UnicodeString fnam = EmptyStr, bool is_dir = false, int wd = 0);
UnicodeString make_LogHdr(const _TCHAR *cmd, UnicodeString fnam = EmptyStr, bool is_dir = false, int wd = 0);
UnicodeString make_LogHdr(const _TCHAR *cmd, file_rec *fp);
UnicodeString make_CreateLog(UnicodeString dnam);
UnicodeString make_RenameLog(UnicodeString o_nam, UnicodeString n_nam);
void set_RenameLog(UnicodeString &msg, UnicodeString fnam);

void UpdateLogListBox();

void StartLog(UnicodeString msg, int task_no = -1);
void StartLog(const _TCHAR *msg, int task_no = -1);
void EndLog(UnicodeString msg, UnicodeString inf = EmptyStr);
void EndLog(const _TCHAR *msg, UnicodeString inf = EmptyStr);
void EndLog(int id, UnicodeString inf = EmptyStr);
void ExeErrLog(UnicodeString fnam, UnicodeString msg);

void AddLog(UnicodeString msg, bool with_t = false, bool raw = false);
void AddLog(const _TCHAR *msg, bool with_t = false);
void AddLogStrings(TStringList *lst);
void AddLogCr();
void AddErr_Highlight();
void AddDebugLog(UnicodeString msg, UnicodeString info, UnicodeString info2);
void FlushLog();

void set_RedrawOff(TWinControl *cp);
void set_RedrawOn(TWinControl *cp);

bool __fastcall SpecialKeyProc(TForm *frm, WORD &Key, TShiftState Shift, const _TCHAR *topic = NULL);
bool __fastcall SpecialKeyProc(TForm *frm, WORD &Key, TShiftState Shift, int hlp_cnt);

bool __fastcall SpecialEditProc(TObject *Sender, WORD &Key, TShiftState Shift);

UnicodeString inputbox_dir(const _TCHAR *tit, const _TCHAR *cmd);

bool is_IniSeaKey(UnicodeString &keystr);

bool update_IncSeaWord(UnicodeString &kwd, UnicodeString keystr, bool fl_sw = false);

UnicodeString get_CsrKeyCmd(UnicodeString KeyStr);

bool is_OneNrmCmd(UnicodeString cmds, bool no_prm = false);

bool MovListBoxFromFilter(TListBox *lp, UnicodeString key_str);
bool MovGridFromFilter(TStringGrid *gp, UnicodeString key_str);

bool ExeCmdListBox(TListBox *lp, UnicodeString cmd, UnicodeString prm = EmptyStr);
bool ExeCmdListBox(TListBox *lp, const _TCHAR *cmd, UnicodeString prm = EmptyStr);

void copy_to_Clipboard(UnicodeString s);
void copy_to_Clipboard(TPicture *pic);
void copy_to_Clipboard(TMetafile *mf);
void copy_to_Clipboard(Graphics::TBitmap *bmp);

bool CloseOtherNyanFi();
int  get_NyanFiList(TStringList *lst);
UnicodeString get_NewTitle(bool primary = false);
HWND get_NyanFiWnd(int rel_idx);
bool activate_NyanFi(int idx, bool rel = true);
bool IsDuplicated();

int  get_ExViewerList(TStringList *lst);
bool focus_ExViewer();
void close_all_ExViewer(TForm *frm = NULL);

HWND get_PrimNyanWnd();
bool IsNyanfiWnd(HWND hWnd);
bool IsNyanfi2Wnd(HWND hWnd);
bool NotifyPrimNyan(UnicodeString msg);

HWND get_ModalWnd();
HWND get_HelpWnd();
HWND get_MenuWnd();

double GetDistance(double lat1, double lng1, double lat2, double lng2);
bool OpenGoogleMaps(double lat, double lng, UnicodeString fnam);

UnicodeString cipher(UnicodeString orgstr);
UnicodeString uncipher(UnicodeString  cipstr);

void AddToRecentFile(UnicodeString fnam);
void AddToRecentFile(TStringList *lst);

int get_ViewTabWidth(UnicodeString fext);

void MakeTreeList(TStringList *lst, UnicodeString pnam, bool chk_sw = false);
bool AddPathToTreeList(TStringList *lst);
//---------------------------------------------------------------------------
#endif