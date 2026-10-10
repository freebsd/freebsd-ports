PORTNAME=	bhotkeys-media
DISTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Media-key hotkeys for bhotkeys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus
RUN_DEPENDS=	bhotkeys:x11/bhotkeys

USES=		pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD

PLIST_FILES=	bin/mpris-control \
		share/bhotkeys/plugins.d/fn-next \
		share/bhotkeys/plugins.d/fn-play \
		share/bhotkeys/plugins.d/fn-prev \
		share/man/man1/mpris-control.1.gz

pre-build:
	${MKDIR} ${WRKSRC}/bin

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mpris-control

.include <bsd.port.mk>
