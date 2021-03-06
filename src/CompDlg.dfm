object FileCompDlg: TFileCompDlg
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #21516#21517#12501#12449#12452#12523#12398#27604#36611
  ClientHeight = 386
  ClientWidth = 434
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
    434
    386)
  PixelsPerInch = 96
  TextHeight = 13
  object CanButton: TButton
    Left = 219
    Top = 352
    Width = 80
    Height = 26
    Anchors = [akLeft, akBottom]
    Cancel = True
    Caption = #12461#12515#12531#12475#12523
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 10
    ExplicitTop = 297
  end
  object OkButton: TButton
    Left = 114
    Top = 352
    Width = 80
    Height = 26
    Action = OkAction
    Anchors = [akLeft, akBottom]
    Default = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    TabOrder = 9
    ExplicitTop = 297
  end
  object CmpDirCheckBox: TCheckBox
    Left = 12
    Top = 288
    Width = 152
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = #12487#12451#12524#12463#12488#12522#12418#27604#36611'(&D)'
    TabOrder = 4
    ExplicitTop = 233
  end
  object TimePanel: TPanel
    Left = 0
    Top = 0
    Width = 434
    Height = 55
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    StyleElements = []
    DesignSize = (
      434
      55)
    object TimeRadioGroup: TRadioGroup
      Left = 8
      Top = 6
      Width = 418
      Height = 41
      Anchors = [akLeft, akTop, akRight]
      Caption = #12479#12452#12512#12473#12479#12531#12503'(&T)'
      Columns = 5
      ItemIndex = 0
      Items.Strings = (
        #28961#35222
        #19981#19968#33268
        #19968#33268
        #26032#12375#12356
        #21476#12356)
      TabOrder = 0
    end
  end
  object SizePanel: TPanel
    Left = 0
    Top = 55
    Width = 434
    Height = 55
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 1
    StyleElements = []
    DesignSize = (
      434
      55)
    object SizeRadioGroup: TRadioGroup
      Left = 9
      Top = 6
      Width = 417
      Height = 41
      Anchors = [akLeft, akTop, akRight]
      Caption = #12469#12452#12474'(&S)'
      Columns = 5
      ItemIndex = 0
      Items.Strings = (
        #28961#35222
        #19981#19968#33268
        #19968#33268
        #22823#12365#12356
        #23567#12373#12356)
      TabOrder = 0
    end
  end
  object HashPanel: TPanel
    Left = 0
    Top = 110
    Width = 434
    Height = 112
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 2
    StyleElements = []
    DesignSize = (
      434
      112)
    object HashRadioGroup: TRadioGroup
      Left = 8
      Top = 6
      Width = 418
      Height = 99
      Anchors = [akLeft, akTop, akRight, akBottom]
      Caption = #12495#12483#12471#12517'(&H)'
      Columns = 5
      ItemIndex = 0
      Items.Strings = (
        #28961#35222
        #19981#19968#33268
        #19968#33268)
      TabOrder = 0
      OnClick = OptRadioGroupClick
    end
    object AlgRadioGroup: TRadioGroup
      Left = 239
      Top = 18
      Width = 180
      Height = 80
      Anchors = [akLeft, akTop, akRight]
      Caption = #12450#12523#12468#12522#12474#12512'(&A)'
      Columns = 2
      ItemIndex = 0
      Items.Strings = (
        'MD5'
        'SHA-1'
        'SHA-256'
        'SHA-384'
        'SHA-512'
        'CRC32')
      TabOrder = 1
    end
  end
  object SelOppCheckBox: TCheckBox
    Left = 12
    Top = 313
    Width = 130
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = #21453#23550#20596#12418#36984#25246'(&O)'
    TabOrder = 6
    ExplicitTop = 258
  end
  object ReverseCheckBox: TCheckBox
    Left = 144
    Top = 313
    Width = 117
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = #32080#26524#12434#21453#36578'(&R)'
    TabOrder = 7
    ExplicitTop = 258
  end
  object SelMaskCheckBox: TCheckBox
    Left = 263
    Top = 313
    Width = 162
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = #36984#25246#38917#30446#12384#12369#12434#27531#12377'(&M)'
    TabOrder = 8
    ExplicitTop = 258
  end
  object CmpArcCheckBox: TCheckBox
    Left = 170
    Top = 288
    Width = 207
    Height = 17
    Anchors = [akLeft, akBottom]
    Caption = #12487#12451#12524#12463#12488#12522#12392#12450#12540#12459#12452#12502#12434#27604#36611'(&P)'
    TabOrder = 5
    ExplicitTop = 233
  end
  object IdPanel: TPanel
    Left = 0
    Top = 222
    Width = 434
    Height = 55
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 3
    StyleElements = []
    ExplicitLeft = 8
    ExplicitTop = 283
    DesignSize = (
      434
      55)
    object IdRadioGroup: TRadioGroup
      Left = 8
      Top = 6
      Width = 418
      Height = 41
      Anchors = [akLeft, akTop, akRight]
      Caption = #12508#12522#12517#12540#12512#12471#12522#12450#12523#30058#21495'/'#12501#12449#12452#12523'ID(&I)'
      Columns = 5
      ItemIndex = 0
      Items.Strings = (
        #28961#35222
        #19981#19968#33268
        #19968#33268)
      TabOrder = 0
      OnClick = OptRadioGroupClick
    end
  end
  object ActionList1: TActionList
    Left = 33
    Top = 342
    object OkAction: TAction
      Caption = 'OK'
      OnUpdate = OkActionUpdate
    end
  end
end
