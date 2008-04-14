# New ports collection makefile for:	slock
# Date created:		18 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=       slock
PORTVERSION=	0.8
CATEGORIES=	x11
MASTER_SITES=	http://www.suckless.org/download/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Simple X screen locker

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${X11BASE}/lib" \
		X11INC="${X11BASE}/include" CC="${CC}" \
		MANPREFIX="${MANPREFIX}/man"
PLIST_FILES=	bin/slock

USE_XLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include||;s|-L/usr/lib||;s|= -Os|+=|'\
		-e 's|-DHAVE_SHADOW_H||' ${WRKSRC}/config.mk

.include <bsd.port.mk>
