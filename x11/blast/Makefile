# New ports collection makefile for:   blast
# Date created:         9 Jul 1996
# Whom:            searle
#
# $FreeBSD$
#

PORTNAME=	blast
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/b/blast
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blast blows holes through windows

WRKSRC=		${WRKDIR}/${PORTNAME}-1.1.orig
USE_X_PREFIX=	yes
MAN1=		blast.1
PLIST_FILES=	bin/blast

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/blast.c -I${X11BASE}/include -L${X11BASE}/lib -lX11 -lXext -o ${WRKSRC}/blast

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blast ${PREFIX}/bin/blast
	${INSTALL_MAN} ${WRKSRC}/blast.man ${MANPREFIX}/man/man1/blast.1

.include <bsd.port.mk>
