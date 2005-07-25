# New ports collection makefile for:	thinglaunch
# Date created:				22 Jul 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	thinglaunch
PORTVERSION=	1.03
CATEGORIES=	x11
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A very fast launcher program for X

USE_X_PREFIX=	yes

CPPFLAGS=	-I${X11BASE}/include -lX11
LDFLAGS=	-L${X11BASE}/lib

PLIST_FILES=	bin/thinglaunch

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
