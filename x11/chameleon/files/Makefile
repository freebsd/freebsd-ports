#
# $FreeBSD$
#
PROG=	chameleon
SRCS=	chameleon.c info.c setfile.c setname.c setrgb.c
LDADD=	`imlib-config --libs` `gtk-config --libs`
CFLAGS+=	`imlib-config --cflags` `gtk-config --cflags`

PREFIX?=	/usr/X11R6
DESTDIR=	${PREFIX}
BINDIR=		/bin
MANDIR=		/man/man
NOMANCOMPRESS=	yes

FILES=	cham.xpm
FILESDIR=	/share/pixmaps

.include <bsd.prog.mk>
