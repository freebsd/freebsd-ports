# New ports collection makefile for:	xterm
# Date created:				24.07.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xterm
PORTVERSION=	243
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/ \
		http://voodoo.bawue.com/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

BUILD_DEPENDS=	luit:${PORTSDIR}/x11/luit
LIB_DEPENDS=	utempter.0:${PORTSDIR}/sysutils/libutempter

USE_XORG=	xaw xft
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--with-utempter --enable-narrowproto

.if defined(WITH_WIDE_CHARS)
CONFIGURE_ARGS+=	--enable-wide-chars --enable-luit
.endif

.if defined(WITH_256_COLOR)
CONFIGURE_ARGS+=	--enable-256-color
.endif

MAN1=		resize.1 koi8rxterm.1 uxterm.1 xterm.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/xterm

.include <bsd.port.mk>
