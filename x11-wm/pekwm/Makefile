# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	20050227
CATEGORIES=	x11-wm
MASTER_SITES=	http://bsd-unix.org/downloads/ \
		http://pekwm.org/files/
DISTNAME=	${PORTNAME}-dev-${PORTVERSION}

MAINTAINER=	xcas@cox.net
COMMENT=	A windowmanager based on aewm++

LIB_DEPENDS=	Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_BZIP2=	yes
USE_GCC=	3.4
USE_GMAKE=	yes
USE_X_PREFIX=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-shape --enable-xinerama --enable-xrandr \
		--disable-pcre --enable-xft --enable-imlib2 --disable-debug \
		--enable-menus --enable-harbour

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/pekwm

.include <bsd.port.mk>
