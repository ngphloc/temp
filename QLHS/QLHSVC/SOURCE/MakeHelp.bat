@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by QLHS.HPJ. >"hlp\Qlhs.hm"
echo. >>"hlp\Qlhs.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Qlhs.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Qlhs.hm"
echo. >>"hlp\Qlhs.hm"
echo // Prompts (IDP_*) >>"hlp\Qlhs.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Qlhs.hm"
echo. >>"hlp\Qlhs.hm"
echo // Resources (IDR_*) >>"hlp\Qlhs.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Qlhs.hm"
echo. >>"hlp\Qlhs.hm"
echo // Dialogs (IDD_*) >>"hlp\Qlhs.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Qlhs.hm"
echo. >>"hlp\Qlhs.hm"
echo // Frame Controls (IDW_*) >>"hlp\Qlhs.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Qlhs.hm"
REM -- Make help for Project QLHS


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Qlhs.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Qlhs.hlp" goto :Error
if not exist "hlp\Qlhs.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Qlhs.hlp" Debug
if exist Debug\nul copy "hlp\Qlhs.cnt" Debug
if exist Release\nul copy "hlp\Qlhs.hlp" Release
if exist Release\nul copy "hlp\Qlhs.cnt" Release
echo.
goto :done

:Error
echo hlp\Qlhs.hpj(1) : error: Problem encountered creating help file

:done
echo.
