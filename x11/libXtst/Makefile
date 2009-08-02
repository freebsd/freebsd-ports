# New ports collection makefile for:   libXtst
# Date Created:			8 Feb 2006
# Whom:				Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libXtst
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Test extension

XORG_CAT=	lib
USE_XORG=	x11 xext recordproto:both xextproto inputproto:both
USE_AUTOTOOLS=	libtool:22

MAN3=		XTestQueryExtension.3 \
		XTestCompareCursorWithWindow.3 \
		XTestCompareCurrentCursorWithWindow.3 \
		XTestFakeKeyEvent.3 \
		XTestFakeButtonEvent.3 \
		XTestFakeMotionEvent.3 \
		XTestFakeRelativeMotionEvent.3 \
		XTestGrabControl.3 \
		XTestSetGContextOfGC.3 \
		XTestSetVisualIDOfVisual.3 \
		XTestDiscard.3

.include <bsd.port.mk>
