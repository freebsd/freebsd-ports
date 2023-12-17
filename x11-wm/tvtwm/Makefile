PORTNAME=	tvtwm
PORTVERSION=	pl11
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	XCONTRIB/window_managers
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Twm with a virtual desktop

LICENSE=	MIT

DEPRECATED=	Upstream last release was in 2001 reconsider using vtwm
EXPIRATION_DATE=	2024-01-17

USES=		imake xorg
USE_XORG=	xbitmaps xpm xmu

CFLAGS+=	-Wno-return-type

WRKSRC=		${WRKDIR}/tvtwm

PLIST_FILES=	bin/tvtwm \
		man/man1/tvtwm.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tvtwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tvtwm.man ${STAGEDIR}${MANPREFIX}/man/man1/tvtwm.1

.include <bsd.port.mk>
