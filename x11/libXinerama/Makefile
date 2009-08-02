# New ports collection makefile for:   libXinerama
# Date Created:			7 May, 2004
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXinerama
PORTVERSION=	1.0.3
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 Xinerama library

XORG_CAT=	lib
USE_XORG=	x11 xext xextproto xineramaproto:both
USE_AUTOTOOLS=	libtool:22

MAN3=		Xinerama.3 \
		XineramaQueryExtension.3 \
		XineramaQueryVersion.3 \
		XineramaIsActive.3 \
		XineramaQueryScreens.3

.include <bsd.port.mk>
