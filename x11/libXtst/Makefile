# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXtst
PORTVERSION=	1.2.2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Test extension

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	x11 xext recordproto:both xextproto inputproto:both \
		xi
USE_AUTOTOOLS=	libtool

CONFIGURE_ARGS+=--disable-specs --without-xmlto

MAN3=	XTestCompareCurrentCursorWithWindow.3 \
	XTestCompareCursorWithWindow.3 \
	XTestDiscard.3 \
	XTestFakeButtonEvent.3 \
	XTestFakeKeyEvent.3 \
	XTestFakeMotionEvent.3 \
	XTestFakeRelativeMotionEvent.3 \
	XTestGrabControl.3 \
	XTestQueryExtension.3 \
	XTestSetGContextOfGC.3 \
	XTestSetVisualIDOfVisual.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} '/^SUBDIRS/,/^$$/ \
		s/specs//' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
