# $FreeBSD$

all:
	cd xmove;xmkmf -DBuildHtmlManPages=0 && make
	cd xmovectrl;xmkmf -DBuildHtmlManPages=0 && make
install:
	cd xmove;make install
	cd xmovectrl;make install
