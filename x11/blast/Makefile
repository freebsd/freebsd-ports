# New ports collection makefile for:   blast
# Date created:         9 Jul 1996
# Whom:            searle
#
# $FreeBSD$
#

PORTNAME=	blast
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	ftp://hpux.csc.liv.ac.uk/hpux/X11/Demos/blast-1.0/ \
		ftp://ftp.univie.ac.at/systems/hpux/hpux/X11/Demos/blast-1.0/ \
		ftp://hpftp.cict.fr/hpux/X11/Demos/blast-1.0/
DISTNAME=	${PORTNAME}-${PORTVERSION}-ss-11.00

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blast blows holes through windows

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=	yes
MAN1=		blast.1
PLIST_FILES=	bin/blast

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/blast.c -I${X11BASE}/include -L${X11BASE}/lib -lX11 -lXext -o ${WRKSRC}/blast

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blast ${PREFIX}/bin/blast
	${INSTALL_MAN} ${WRKSRC}/blast.man ${MANPREFIX}/man/man1/blast.1

.include <bsd.port.mk>
