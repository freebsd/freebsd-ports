# New ports collection makefile for:	tvtwm
# Date created:		5th December 1994
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	tvtwm
PORTVERSION=	pl11
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	window_managers
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Twm with a virtual desktop

WRKSRC=		${WRKDIR}/tvtwm
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		tvtwm.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/tvtwm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tvtwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tvtwm.man ${MANPREFIX}/man/man1/tvtwm.1

.include <bsd.port.mk>
