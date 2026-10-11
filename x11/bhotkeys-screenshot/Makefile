PORTNAME=	bhotkeys-screenshot
DISTVERSION=	1.1
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Screenshot hotkeys for bhotkeys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bhotkeys:x11/bhotkeys \
		bosd:x11/bosd \
		ffmpeg:multimedia/ffmpeg \
		gm:graphics/GraphicsMagick \
		xdpyinfo:x11/xdpyinfo \
		xprop:x11/xprop \
		xrandr:x11/xrandr

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
NO_ARCH=	yes

.include <bsd.port.mk>
