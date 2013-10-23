# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	thinglaunch
PORTVERSION=	1.8
CATEGORIES=	x11
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Very fast launcher program for X

USE_XORG=	x11 xproto

CPPFLAGS+=	-I${LOCALBASE}/include -lX11
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/thinglaunch

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
