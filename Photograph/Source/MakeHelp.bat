@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by PHOTO.HPJ. >"hlp\Photo.hm"
echo. >>"hlp\Photo.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Photo.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Photo.hm"
echo. >>"hlp\Photo.hm"
echo // Prompts (IDP_*) >>"hlp\Photo.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Photo.hm"
echo. >>"hlp\Photo.hm"
echo // Resources (IDR_*) >>"hlp\Photo.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Photo.hm"
echo. >>"hlp\Photo.hm"
echo // Dialogs (IDD_*) >>"hlp\Photo.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Photo.hm"
echo. >>"hlp\Photo.hm"
echo // Frame Controls (IDW_*) >>"hlp\Photo.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Photo.hm"
REM -- Make help for Project PHOTO


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Photo.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Photo.hlp" goto :Error
if not exist "hlp\Photo.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Photo.hlp" Debug
if exist Debug\nul copy "hlp\Photo.cnt" Debug
if exist Release\nul copy "hlp\Photo.hlp" Release
if exist Release\nul copy "hlp\Photo.cnt" Release
echo.
goto :done

:Error
echo hlp\Photo.hpj(1) : error: Problem encountered creating help file

:done
echo.
