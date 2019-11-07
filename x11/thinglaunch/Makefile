# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	thinglaunch
PORTVERSION=	1.8
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Very fast launcher program for X

LICENSE=	MIT

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
