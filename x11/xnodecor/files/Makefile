# $FreeBSD$
CFLAGS=		-I${X11BASE}/include
LDFLAGS=	-L${X11BASE}/lib
LIBS=		-lX11

all:	xnodecor

xnodecor:
	$(CC) -o xnodecor xnodecor.c $(CFLAGS) $(LDFLAGS) $(LIBS)

install:
	${BSD_INSTALL_PROGRAM} xnodecor ${X11BASE}/bin

clean:
	rm -f *.rej a.out core xnodecor
