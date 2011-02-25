# New ports collection makefile for:   libXext
# Date Created:			29 Oct, 2003
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXcomposite
PORTVERSION=	0.4.3
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Composite extension library

XORG_CAT=	lib
USE_XORG=	compositeproto:both x11 xfixes xext fixesproto xproto:both
MAN3=		Xcomposite.3 \
		XCompositeQueryExtension.3 \
		XCompositeQueryVersion.3 \
		XCompositeVersion.3 \
		XCompositeRedirectWindow.3 \
		XCompositeRedirectSubwindows.3 \
		XCompositeUnredirectWindow.3 \
		XCompositeUnredirectSubwindows.3 \
		XCompositeCreateRegionFromBorderClip.3 \
		XCompositeNameWindowPixmap.3 \
		XCompositeGetOverlayWindow.3 \
		XCompositeReleaseOverlayWindow.3

.include <bsd.port.mk>
