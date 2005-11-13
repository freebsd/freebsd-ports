# New ports collection makefile for:	xterm
# Date created:				24.07.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xterm
PORTVERSION=	206
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://invisible-island.net/xterm/ \
		http://voodoo.bawue.com/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

CONFLICTS=	xorg-clients-6.7* xorg-clients-6.8.[0-1]* xorg-clients-6.8.2 \
		XFree86-clients-4.[0-4]* XFree86-clients-4.5.0 \
		XFree86-3*

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
CONFIGURE_ARGS+=	--enable-wide-chars --enable-luit --with-utempter

MAN1=		resize.1 xterm.1

pre-su-install:
	if [ -L ${PREFIX}/bin/resize ]; then \
		rm ${PREFIX}/bin/resize; \
	fi
	if [ -L ${PREFIX}/bin/uxterm ]; then \
		rm ${PREFIX}/bin/uxterm; \
	fi
	if [ -L ${PREFIX}/bin/xterm ]; then \
		rm ${PREFIX}/bin/xterm; \
	fi
	if [ -L ${PREFIX}/lib/X11/app-defaults/UXTerm ]; then \
		rm ${PREFIX}/lib/X11/app-defaults/UXTerm; \
	fi
	if [ -L ${PREFIX}/lib/X11/app-defaults/XTerm-color ]; then \
		rm ${PREFIX}/lib/X11/app-defaults/XTerm-color; \
	fi
	if [ -L ${PREFIX}/lib/X11/app-defaults/XTerm ]; then \
		rm ${PREFIX}/lib/X11/app-defaults/XTerm; \
	fi

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/xterm

.include <bsd.port.mk>
