# Microsoft Developer Studio Project File - Name="qlay2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=qlay2 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "qlay2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "qlay2.mak" CFG="qlay2 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "qlay2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "qlay2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "qlay2 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /G6 /Zp16 /MT /O2 /Ob2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FAcs /Fr /YX /FD /c
# SUBTRACT CPP /u
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x40c /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /profile /nodefaultlib

!ELSEIF  "$(CFG)" == "qlay2 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x40c /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "qlay2 - Win32 Release"
# Name "qlay2 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=".\cfg-win.c"
# End Source File
# Begin Source File

SOURCE=.\debug.c
# End Source File
# Begin Source File

SOURCE=.\exe68k.c
# End Source File
# Begin Source File

SOURCE=.\getopt.c
# End Source File
# Begin Source File

SOURCE=.\keybuf.c
# End Source File
# Begin Source File

SOURCE=.\main.c
# End Source File
# Begin Source File

SOURCE=.\op68k0.c
# End Source File
# Begin Source File

SOURCE=.\op68k1.c
# End Source File
# Begin Source File

SOURCE=.\op68k2.c
# End Source File
# Begin Source File

SOURCE=.\op68k3.c
# End Source File
# Begin Source File

SOURCE=.\op68k4.c
# End Source File
# Begin Source File

SOURCE=.\op68k5.c
# End Source File
# Begin Source File

SOURCE=.\op68k6.c
# End Source File
# Begin Source File

SOURCE=.\op68k7.c
# End Source File
# Begin Source File

SOURCE=.\op68k8.c
# End Source File
# Begin Source File

SOURCE=.\op68k9.c
# End Source File
# Begin Source File

SOURCE=.\op68kA.c
# End Source File
# Begin Source File

SOURCE=.\op68kB.c
# End Source File
# Begin Source File

SOURCE=.\op68kC.c
# End Source File
# Begin Source File

SOURCE=.\op68kD.c
# End Source File
# Begin Source File

SOURCE=.\op68kdefs.c
# End Source File
# Begin Source File

SOURCE=.\op68kE.c
# End Source File
# Begin Source File

SOURCE=.\op68kF.c
# End Source File
# Begin Source File

SOURCE=.\op68kstbl.c
# End Source File
# Begin Source File

SOURCE=.\op68ktbl.c
# End Source File
# Begin Source File

SOURCE=.\os.c
# End Source File
# Begin Source File

SOURCE=.\qldisk.c
# End Source File
# Begin Source File

SOURCE=.\qlio.c
# End Source File
# Begin Source File

SOURCE=.\qlmem.c
# End Source File
# Begin Source File

SOURCE=.\qlvers.c
# End Source File
# Begin Source File

SOURCE=.\readcpu.c
# End Source File
# Begin Source File

SOURCE=".\ser-win.c"
# End Source File
# Begin Source File

SOURCE=".\spc-win.c"
# End Source File
# Begin Source File

SOURCE=.\winmain.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=".\cfg-win.h"
# End Source File
# Begin Source File

SOURCE=.\debug.h
# End Source File
# Begin Source File

SOURCE=.\dx_addon.h
# End Source File
# Begin Source File

SOURCE=.\exe68k.h
# End Source File
# Begin Source File

SOURCE=.\getopt.h
# End Source File
# Begin Source File

SOURCE=.\keybuf.h
# End Source File
# Begin Source File

SOURCE=.\op68ktbl.h
# End Source File
# Begin Source File

SOURCE=.\options.h
# End Source File
# Begin Source File

SOURCE=.\os.h
# End Source File
# Begin Source File

SOURCE=.\pckeys.h
# End Source File
# Begin Source File

SOURCE=.\qlayw.h
# End Source File
# Begin Source File

SOURCE=.\qldisk.h
# End Source File
# Begin Source File

SOURCE=.\qlio.h
# End Source File
# Begin Source File

SOURCE=.\qlkeys.h
# End Source File
# Begin Source File

SOURCE=.\qlmem.h
# End Source File
# Begin Source File

SOURCE=.\qlvers.h
# End Source File
# Begin Source File

SOURCE=.\readcpu.h
# End Source File
# Begin Source File

SOURCE=.\roms.h
# End Source File
# Begin Source File

SOURCE=".\ser-os.h"
# End Source File
# Begin Source File

SOURCE=".\spc-os.h"
# End Source File
# Begin Source File

SOURCE=.\sysconfig.h
# End Source File
# Begin Source File

SOURCE=.\sysdeps.h
# End Source File
# Begin Source File

SOURCE=.\winmain.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\arrow.cur
# End Source File
# Begin Source File

SOURCE=.\BMPRES\bmp_span.bmp
# End Source File
# Begin Source File

SOURCE=.\BMPRES\engl.bmp
# End Source File
# Begin Source File

SOURCE=.\engl.bmp
# End Source File
# Begin Source File

SOURCE=.\BMPRES\engl_s.bmp
# End Source File
# Begin Source File

SOURCE=.\engl_s.bmp
# End Source File
# Begin Source File

SOURCE=.\BMPRES\fren.BMP
# End Source File
# Begin Source File

SOURCE=.\fren.BMP
# End Source File
# Begin Source File

SOURCE=.\BMPRES\fren_s.bmp
# End Source File
# Begin Source File

SOURCE=.\fren_s.bmp
# End Source File
# Begin Source File

SOURCE=.\BMPRES\germ.bmp
# End Source File
# Begin Source File

SOURCE=.\germ.bmp
# End Source File
# Begin Source File

SOURCE=.\BMPRES\germ_s.bmp
# End Source File
# Begin Source File

SOURCE=.\germ_s.bmp
# End Source File
# Begin Source File

SOURCE=.\ico00001.ico
# End Source File
# Begin Source File

SOURCE=.\BMPRES\ital.bmp
# End Source File
# Begin Source File

SOURCE=.\ital.bmp
# End Source File
# Begin Source File

SOURCE=.\BMPRES\ital_s.bmp
# End Source File
# Begin Source File

SOURCE=.\ital_s.bmp
# End Source File
# Begin Source File

SOURCE=.\QL2K1.BMP
# End Source File
# Begin Source File

SOURCE=.\QL2K2.BMP
# End Source File
# Begin Source File

SOURCE=.\qlay.ico
# End Source File
# Begin Source File

SOURCE=.\qlay2.cur
# End Source File
# Begin Source File

SOURCE=.\QLAY2.cur
# End Source File
# Begin Source File

SOURCE=.\qlay2.ico
# End Source File
# Begin Source File

SOURCE=.\qlay21.BMP
# End Source File
# Begin Source File

SOURCE=.\qlay22.BMP
# End Source File
# Begin Source File

SOURCE=.\qlaycfg.ico
# End Source File
# Begin Source File

SOURCE=.\qlayw.rc
# End Source File
# Begin Source File

SOURCE=.\BMPRES\qlphoto.bmp
# End Source File
# Begin Source File

SOURCE=.\qlphoto.bmp
# End Source File
# Begin Source File

SOURCE=.\BMPRES\span.bmp
# End Source File
# Begin Source File

SOURCE=.\span.bmp
# End Source File
# Begin Source File

SOURCE=.\BMPRES\span_s.BMP
# End Source File
# Begin Source File

SOURCE=.\span_s.BMP
# End Source File
# Begin Source File

SOURCE=.\timy_de_flag.BMP
# End Source File
# Begin Source File

SOURCE=.\tiny_es_flag.BMP
# End Source File
# Begin Source File

SOURCE=.\tiny_fr_flag.BMP
# End Source File
# Begin Source File

SOURCE=.\tiny_it_flag.BMP
# End Source File
# Begin Source File

SOURCE=.\tiny_uk_flag.BMP
# End Source File
# End Group
# Begin Source File

SOURCE=.\LIB\DDRAW.LIB
# End Source File
# End Target
# End Project
