## Build Guide

### Prerequisite

- Windows 10 (x64, 64-bit)
  - x86 (32bit) については確認していません
- [C++Builder - Community Edition](https://www.embarcadero.com/jp/products/cbuilder/starter/)
  - インストール時に「C++Builder Windows 64-bit Community」を選択してください
- [Git for Windows (64-bit)](https://git-scm.com/download/win)

### Building

コマンドプロンプト内で下記のコマンドを入力すると、 NyanFi_x64 リポジトリの clone とビルドができます

```bat
cmd.exe
cd /d "%USERPROFILE%\Documents"
if exist NyanFi_x64 ( rd /s /q NyanFi_x64 )
git clone https://github.com/Nekomimi1958/NyanFi_x64.git
cd NyanFi_x64
.\build.cmd
exit
```
