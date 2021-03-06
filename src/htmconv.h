//----------------------------------------------------------------------//
// HTML→テキスト変換処理クラス											//
//																		//
//----------------------------------------------------------------------//
#ifndef htmconvH
#define htmconvH

//---------------------------------------------------------------------------
#define DEF_LINE_WIDTH		80
#define DEF_BLANK_LN_LIMIT	3				//連続空行制限

//---------------------------------------------------------------------------
class HtmConv
{
private:
	UnicodeString TxtLineBuf;
	bool Skip;
	bool fPRE, fXMP;

	UnicodeString rel_to_abs(UnicodeString fnam, UnicodeString rnam);

	UnicodeString int_to_alpha(int n);
	UnicodeString int_to_roman(int n);
	void del_tag_block(TStringList *lst, const _TCHAR *start_wd, const _TCHAR *end_wd);

	UnicodeString GetTag(UnicodeString s);
	void FlushText(UnicodeString s = EmptyStr);
	void AddHR();

public:
	HtmConv();
	~HtmConv();

	UnicodeString FileName;
	TStringList *HtmBuf;		//HTML文書入力バッファ
	TStringList *TxtBuf;		//テキスト出力バッファ

	int  CodePage;				//出力コードページ

	bool ToMarkdown;			//Markdown に変換

	int  LineWidth;				//桁数
	UnicodeString HeaderStr;	//見出し文字(;区切り)
	UnicodeString UlMarkStr;	//ULマーク
	UnicodeString InsHrClass;	//指定クラスのDIVの前に罫線挿入

	bool InsHdrInf;				//ヘッダ情報を挿入
	bool InsHrSection;			//<section>の前に罫線挿入
	bool InsHrArticle;			//<article>の前に罫線挿入
	bool InsHrNav;				//<nav>の前に罫線挿入

	UnicodeString DelBlkCls;	//削除部分の class リスト
	UnicodeString DelBlkId;		//削除部分の id リスト

	UnicodeString Title;
	UnicodeString Description;
	UnicodeString Keywords;

	void DelAtrBlock(TStringList *lst, UnicodeString anam, UnicodeString aval);
	UnicodeString GetTagAtr(UnicodeString s, UnicodeString t, const _TCHAR *a);
	UnicodeString RefEntity(UnicodeString s);
	void Convert();
};
//---------------------------------------------------------------------------
#endif
