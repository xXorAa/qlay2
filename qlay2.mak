# Makefile - qlay2.dsp

ifndef CFG
CFG=qlay2 - Win32 Debug
endif
CC=i686-w64-mingw32-gcc
CFLAGS=
CXX=g++
CXXFLAGS=$(CFLAGS)
RC?=i686-w64-mingw32-windres
RCFLAGS=-O COFF
ifeq "$(CFG)"  "qlay2 - Win32 Release"
CFLAGS+=-O2 -finline-functions -DWIN32 -DNDEBUG -D_WINDOWS -D_MBCS
LD=$(CC) $(CFLAGS)
LDFLAGS=
LDFLAGS+=-Wl,--subsystem,windows
LIBS+=-lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32
else
ifeq "$(CFG)"  "qlay2 - Win32 Debug"
CFLAGS+=-W -fexceptions -g -O0 -DWIN32 -D_DEBUG -D_WINDOWS -D_MBCS
LD=$(CC) $(CFLAGS)
LDFLAGS=
LDFLAGS+=-Wl,--subsystem,windows
LIBS+=-lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lodbc32 -lodbccp32
endif
endif

ifndef TARGET
TARGET=qlay2.exe
endif

.PHONY: all
all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

%.o: %.cxx
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ -c $<

%.res: %.rc
	$(RC) $(RCFLAGS) -o $@ -i $<

SOURCE_FILES= \
	cfg-win.c \
	debug.c \
	exe68k.c \
	getopt.c \
	keybuf.c \
	main.c \
	op68k0.c \
	op68k1.c \
	op68k2.c \
	op68k3.c \
	op68k4.c \
	op68k5.c \
	op68k6.c \
	op68k7.c \
	op68k8.c \
	op68k9.c \
	op68kA.c \
	op68kB.c \
	op68kC.c \
	op68kD.c \
	op68kdefs.c \
	op68kE.c \
	op68kF.c \
	op68kstbl.c \
	op68ktbl.c \
	os.c \
	qldisk.c \
	qlio.c \
	qlmem.c \
	qlvers.c \
	readcpu.c \
	ser-win.c \
	spc-win.c \
	winmain.c

HEADER_FILES= \
	cfg-win.h \
	debug.h \
	dx_addon.h \
	exe68k.h \
	getopt.h \
	keybuf.h \
	op68ktbl.h \
	options.h \
	os.h \
	pckeys.h \
	qlayw.h \
	qldisk.h \
	qlio.h \
	qlkeys.h \
	qlmem.h \
	qlvers.h \
	readcpu.h \
	roms.h \
	ser-os.h \
	spc-os.h \
	sysconfig.h \
	sysdeps.h \
	winmain.h

RESOURCE_FILES= \
	arrow.cur \
	BMPRES/bmp_span.bmp \
	BMPRES/engl.bmp \
	engl.bmp \
	BMPRES/engl_s.bmp \
	engl_s.bmp \
	BMPRES/fren.BMP \
	fren.BMP \
	BMPRES/fren_s.bmp \
	fren_s.bmp \
	BMPRES/germ.bmp \
	germ.bmp \
	BMPRES/germ_s.bmp \
	germ_s.bmp \
	ico00001.ico \
	BMPRES/ital.bmp \
	ital.bmp \
	BMPRES/ital_s.bmp \
	ital_s.bmp \
	QL2K1.BMP \
	QL2K2.BMP \
	qlay.ico \
	qlay2.cur \
	QLAY2.cur \
	qlay2.ico \
	qlay21.BMP \
	qlay22.BMP \
	qlaycfg.ico \
	qlayw.rc \
	BMPRES/qlphoto.bmp \
	qlphoto.bmp \
	BMPRES/span.bmp \
	span.bmp \
	BMPRES/span_s.BMP \
	span_s.BMP \
	timy_de_flag.BMP \
	tiny_es_flag.BMP \
	tiny_fr_flag.BMP \
	tiny_it_flag.BMP \
	tiny_uk_flag.BMP

SRCS=$(SOURCE_FILES) $(HEADER_FILES) $(RESOURCE_FILES)  \
	LIB/DDRAW.LIB

OBJS=$(patsubst %.rc,%.res,$(patsubst %.cxx,%.o,$(patsubst %.cpp,%.o,$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(filter %.c %.cc %.cpp %.cxx %.rc,$(SRCS)))))))

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS) $(LIBS)

.PHONY: clean
clean:
	-rm -f $(OBJS) $(TARGET) qlay2.dep

.PHONY: depends
depends:
	-$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MM $(filter %.c %.cc %.cpp %.cxx,$(SRCS)) > qlay2.dep

-include qlay2.dep

