PORTNAME=	sdwmbar
DISTVERSION=	1.5
CATEGORIES=	x11

MAINTAINER=	sakhmatd@darkn.space
COMMENT=	Simple statusbar for the dwm window manager
WWW=		https://github.com/sakhmatd/sdwmbar

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dwm:x11-wm/dwm

USES=		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sakhmatd
USE_XORG=	x11
MAKE_ENV=	XPREFIX=${LOCALBASE}

PLIST_FILES=	bin/sdwmbar

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/sdwmbar

.include <bsd.port.mk>
