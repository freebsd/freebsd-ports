# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXinerama
PORTVERSION=	1.1.3
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 Xinerama library

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	x11 xext xextproto xineramaproto:both
USE_AUTOTOOLS=	libtool

MAN3=		Xinerama.3 \
		XineramaQueryExtension.3 \
		XineramaQueryVersion.3 \
		XineramaIsActive.3 \
		XineramaQueryScreens.3

NO_STAGE=	yes
.include <bsd.port.mk>
