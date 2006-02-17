# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	20060216
CATEGORIES=	x11-wm
MASTER_SITES=	http://bsd-unix.org/downloads/ \
		http://pekwm.org/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	xcas@cox.net
COMMENT=	A windowmanager based on aewm++

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_AUTOTOOLS=	autoconf:259 autoheader:259 automake:19 aclocal:19

USE_BZIP2=	yes
USE_GCC=	3.4
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-shape --enable-xinerama --enable-xrandr \
		--enable-xft --disable-pcre --enable-image-xpm \
		--enable-image-jpeg  --enable-image-png --disable-debug \
		--disable-pedantic --enable-menus --enable-harbour

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/pekwm

.include <bsd.port.mk>
