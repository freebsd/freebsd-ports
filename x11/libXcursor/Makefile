# New ports collection makefile for:   libXcursor
# Date Created:			22 Nov, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXcursor
PORTVERSION=	1.1.8
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X client-side cursor loading library

XORG_CAT=	lib
USE_XORG=	xrender x11 xfixes renderproto fixesproto xproto:both

CONFIGURE_ARGS=	--with-icondir=${PREFIX}/lib/X11/icons

MAN3=		Xcursor.3

.include <bsd.port.mk>
