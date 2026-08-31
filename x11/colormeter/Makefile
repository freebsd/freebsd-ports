PORTNAME=	colormeter
DISTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	X11 pixel magnifier with live RGB readout
WWW=		https://github.com/FrauBSD/colormeter

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		localbase pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
USE_XORG=	x11 xft

PLIST_FILES=	bin/colormeter \
		share/man/man1/colormeter.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/colormeter

.include <bsd.port.mk>
