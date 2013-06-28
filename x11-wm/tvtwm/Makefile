# Created by: gpalmer
# $FreeBSD$

PORTNAME=	tvtwm
PORTVERSION=	pl11
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	window_managers
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Twm with a virtual desktop

WRKSRC=		${WRKDIR}/tvtwm
USES=		imake
USE_XORG=	xbitmaps xpm xmu
MAN1=		tvtwm.1
MANCOMPRESSED=	no
PLIST_FILES=	bin/tvtwm

CFLAGS+=	-Wno-return-type

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tvtwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tvtwm.man ${MANPREFIX}/man/man1/tvtwm.1

.include <bsd.port.mk>
