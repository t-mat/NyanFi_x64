@echo off
call rsvars.bat
if %ERRORLEVEL% neq 0 ( 
  echo Build script can't find Embarcadero Studio script "rsvars.bat".
  echo Please install "C++Builder - Community Edition" from the following URL
  echo https://www.embarcadero.com/jp/products/cbuilder/starter/
  pause && exit 1
)

pushd src
msbuild /m NyanFi.cbproj /p:Config=Release /t:build
popd

echo Build script has successfully built "%~dp0src\NyanFi.exe"
pause
