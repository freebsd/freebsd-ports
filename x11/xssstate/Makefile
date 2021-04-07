PORTNAME=	xssstate
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	kfv@kfv.io
COMMENT=	Simple tool to retrieve the X screensaver state

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase:ldflags xorg
USE_XORG=	x11 xscrnsaver

MAKE_ARGS=	LDFLAGS="${LDFLAGS}" CFLAGS="${CFLAGS}" CC="${CC}"

CFLAGS+=	-std=c99 -Wall -DVERSION=\\\"${PORTVERSION}\\\"
LDFLAGS+=	-lX11 -lXss

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
