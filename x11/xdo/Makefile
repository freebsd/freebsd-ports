PORTNAME=	xdo
PORTVERSION=	0.5.7
CATEGORIES=	x11

MAINTAINER=	casnix@gmail.com
COMMENT=	Utility to perform elementary actions on windows
WWW=		https://github.com/baskerville/xdo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util \
		libxcb-icccm.so:x11/xcb-util-wm

USES=		gmake localbase:ldflags xorg
USE_XORG=	xcb
USE_GITHUB=	yes
GH_ACCOUNT=	baskerville
MAKE_ARGS=	MANPREFIX="${PREFIX}/share/man"

PLIST_FILES=	bin/xdo share/man/man1/xdo.1.gz

.include <bsd.port.mk>
