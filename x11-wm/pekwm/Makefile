# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	0.1.6
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/~tournoij/distfiles/ \
		http://www.rwxrwxrwx.net/distfiles/

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	A windowmanager based on aewm++

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	xft xpm x11
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=--enable-shape --enable-xinerama --enable-xrandr \
		--enable-xft --disable-pcre --enable-image-xpm \
		--enable-image-jpeg --enable-image-png --disable-debug \
		--disable-pedantic --enable-menus --enable-harbour
MAN1=		pekwm.1
MANCOMPRESSED=	no

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/pekwm

.include <bsd.port.mk>
