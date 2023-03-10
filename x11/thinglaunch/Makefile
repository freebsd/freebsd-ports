PORTNAME=	thinglaunch
PORTVERSION=	1.8
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Very fast launcher program for X
WWW=		http://unix.freecode.com/projects/thinglaunch/

LICENSE=	MIT

DEPRECATED=	Abandonware, please use x11/thingylaunch instead
EXPIRATION_DATE=	2023-06-10

USES=		xorg
USE_XORG=	x11 xorgproto

CPPFLAGS+=	-I${LOCALBASE}/include -lX11
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/thinglaunch

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
