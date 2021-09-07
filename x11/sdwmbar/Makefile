PORTNAME=	sdwmbar
PORTVERSION=	1.3
CATEGORIES=	x11-wm

MAINTAINER=	sakhmatd@darkn.space
COMMENT=	Simple statusbar for the dwm window manager

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dwm:x11-wm/dwm

USES=		xorg
USE_XORG=	x11
MAKE_ENV=	XPREFIX=${LOCALBASE}

USE_GITHUB=	yes
GH_ACCOUNT=	sakhmatd

PLIST_FILES=	bin/sdwmbar

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sdwmbar

.include <bsd.port.mk>
