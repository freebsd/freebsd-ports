# Ports collection makefile for:	pekwm
# Date created:			Nov 1, 2002
# Whom:				anders@hack.org
#
# $FreeBSD$
#

PORTNAME=	pekwm
PORTVERSION=	0.1.3
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://pekwm.org/files/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A windowmanager based on aewm++

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-shape --disable-xft --disable-xinerama \
		--disable-debug --enable-menus --enable-keygrabber \
		--enable-harbour --disable-pcre

MAN1=		pekwm.1

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/pekwm

.include <bsd.port.mk>
