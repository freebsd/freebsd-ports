# New ports collection makefile for:	xterm
# Date created:				24.07.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xterm
PORTVERSION=	193
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

CONFLICTS=	XFree86-clients-*

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"

MAN1=		resize.1 xterm.1

post-install:
	@${MV} ${X11BASE}/bin/resize ${X11BASE}/bin/resize-static
	@${MV} ${X11BASE}/bin/xterm ${X11BASE}/bin/xterm-static
	@${MV} ${X11BASE}/bin/uxterm ${X11BASE}/bin/uxterm-static
	@${MV} ${X11BASE}/lib/X11/app-defaults/UXTerm ${X11BASE}/lib/X11/app-defaults/UXTerm-static
	@${MV} ${X11BASE}/lib/X11/app-defaults/XTerm ${X11BASE}/lib/X11/app-defaults/XTerm-static
	@${MV} ${X11BASE}/lib/X11/app-defaults/XTerm-color ${X11BASE}/lib/X11/app-defaults/XTerm-color-static

.include <bsd.port.mk>
