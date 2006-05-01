# New ports collection makefile for:	xterm
# Date created:				24.07.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xterm
PORTVERSION=	213
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/ \
		http://voodoo.bawue.com/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
CONFIGURE_ARGS+=--enable-wide-chars --enable-luit --with-utempter \
		--enable-narrowproto

MAN1=		resize.1 xterm.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/xterm

.include <bsd.port.mk>
