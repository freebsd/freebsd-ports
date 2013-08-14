# New ports collection makefile for:	lsw
# Date created:		2011-07-03
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	lsw
PORTVERSION=	0.2
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Lists the titles of all running X windows to stdout, similar to ls(1)

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${LOCALBASE}/lib" \
		X11INC="${LOCALBASE}/include" CC="${CC}"
PLIST_FILES=	bin/lsw

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

MAN1=	lsw.1
USE_XORG=	x11 xt xproto xext

post-patch:
	@${REINPLACE_CMD} -e 's|-I/usr/include||;s|-L/usr/lib||;s|= -Os|+=|'\
		-e 's|-DHAVE_SHADOW_H||' ${WRKSRC}/config.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
