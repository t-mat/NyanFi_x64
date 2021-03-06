object FindTextDlg: TFindTextDlg
  Left = 0
  Top = 0
  HelpContext = 65
  BorderStyle = bsDialog
  Caption = #25991#23383#21015#26908#32034
  ClientHeight = 126
  ClientWidth = 524
  Color = clBtnFace
  ParentFont = True
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesigned
  ShowHint = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  DesignSize = (
    524
    126)
  PixelsPerInch = 96
  TextHeight = 13
  object KwdLabel: TLabel
    Left = 20
    Top = 11
    Width = 50
    Height = 13
    Alignment = taRightJustify
    Caption = #26908#32034#35486'(&S)'
    FocusControl = FindComboBox
  end
  object FindComboBox: TComboBox
    Left = 74
    Top = 8
    Width = 339
    Height = 21
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    OnChange = FindComboBoxChange
    OnKeyDown = FindComboBoxKeyDown
    OnKeyPress = FindComboBoxKeyPress
  end
  object FindBtn: TButton
    Left = 421
    Top = 7
    Width = 97
    Height = 26
    Action = FindNextAction
    Anchors = [akTop, akRight]
    Default = True
    TabOrder = 1
  end
  object CalcelBtn: TButton
    Left = 421
    Top = 48
    Width = 97
    Height = 26
    Anchors = [akTop, akRight]
    Cancel = True
    Caption = #12461#12515#12531#12475#12523
    ModalResult = 2
    TabOrder = 2
  end
  object UpDownGroup: TRadioGroup
    Left = 232
    Top = 42
    Width = 181
    Height = 44
    Caption = #26908#32034#26041#21521
    Columns = 2
    Items.Strings = (
      #19978#12408'(&U)'
      #19979#12408'(&D)')
    TabOrder = 3
    OnClick = SubOptClick
  end
  object CaseCheckBox: TCheckBox
    Left = 12
    Top = 42
    Width = 211
    Height = 18
    Caption = #22823#25991#23383#12539#23567#25991#23383#12434#21306#21029'(&C)'
    TabOrder = 4
    OnClick = FindOptChangedClick
  end
  object RegExCheckBox: TCheckBox
    Left = 12
    Top = 68
    Width = 111
    Height = 17
    Caption = #27491#35215#34920#29694'(&R)'
    TabOrder = 5
    OnClick = RegExCheckBoxClick
  end
  object MigemoCheckBox: TCheckBox
    Left = 128
    Top = 68
    Width = 94
    Height = 17
    Caption = '&Migemo'
    TabOrder = 6
    OnClick = MigemoCheckBoxClick
  end
  object HighlightCheckBox: TCheckBox
    Left = 236
    Top = 95
    Width = 148
    Height = 17
    Caption = #24375#35519#34920#31034#12434#32173#25345'(&H)'
    TabOrder = 9
    OnClick = SubOptClick
  end
  object BytesCheckBox: TCheckBox
    Left = 12
    Top = 95
    Width = 91
    Height = 17
    Caption = #12496#12452#12488#21015'(&B)'
    TabOrder = 7
    OnClick = FindOptChangedClick
  end
  object CodePageComboBox: TComboBox
    Left = 105
    Top = 93
    Width = 115
    Height = 21
    Style = csDropDownList
    DropDownCount = 12
    TabOrder = 8
    OnChange = FindOptChangedClick
  end
  object CloseCheckBox: TCheckBox
    Left = 386
    Top = 95
    Width = 132
    Height = 17
    Caption = #26908#32034#24460#12395#38281#12376#12427'(&X)'
    TabOrder = 10
    OnClick = SubOptClick
  end
  object ActionList1: TActionList
    Left = 480
    Top = 40
    object FindNextAction: TAction
      Caption = #27425#12434#26908#32034'(&F)'
      OnExecute = FindNextActionExecute
      OnUpdate = FindNextActionUpdate
    end
  end
end
