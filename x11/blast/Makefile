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
DISTNAME=	${PORTNAME}-${PORTVERSION}-ss-10.20

MAINTAINER=	jseger@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_X_PREFIX=	yes
MAN1=		blast.1

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/blast.c -I${X11BASE}/include -L${X11BASE}/lib -lX11 -lXext -o ${WRKSRC}/blast

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blast ${PREFIX}/bin/blast
	${INSTALL_MAN} ${WRKSRC}/blast.man ${MANPREFIX}/man/man1/blast.1

.include <bsd.port.mk>
