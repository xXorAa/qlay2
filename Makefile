# Makefile - QLAY2.dsw

.PHONY: all
all: \
	QLAY2

.PHONY: QLAY2
QLAY2:
	$(MAKE) -f qlay2.mak

.PHONY: clean
clean:
	$(MAKE) -f qlay2.mak clean

.PHONY: depends
depends:
	$(MAKE) -f qlay2.mak depends

