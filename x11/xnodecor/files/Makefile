# $FreeBSD$
CFLAGS=		-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
LIBS=		-lX11

all:	xnodecor

xnodecor:
	$(CC) -o xnodecor xnodecor.c $(CFLAGS) $(LDFLAGS) $(LIBS)

install:
	${BSD_INSTALL_PROGRAM} xnodecor ${PREFIX}/bin

clean:
	rm -f *.rej a.out core xnodecor
