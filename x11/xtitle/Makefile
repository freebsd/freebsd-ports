PORTNAME=	xtitle
DISTVERSION=	0.4.4
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Outputs X window titles
WWW=		https://github.com/baskerville/xtitle

LICENSE=	UNLICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-ewmh.so:x11/xcb-util-wm

USES=		gmake localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	baskerville
USE_XORG=	xcb

PLIST_FILES=	bin/xtitle

.include <bsd.port.mk>
