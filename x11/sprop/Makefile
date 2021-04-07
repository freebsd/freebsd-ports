PORTNAME=	sprop
PORTVERSION=	0.1
CATEGORIES=	x11
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	kfv@kfv.io
COMMENT=	Simple X property utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_XORG=	x11

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}"
PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
