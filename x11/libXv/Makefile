# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXv
PORTVERSION=	1.0.10
PORTEPOCH=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Video Extension library

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	x11 xext xextproto videoproto:both xproto:both

MAN3=	Xv.3 \
	XvFreeAdaptorInfo.3 \
	XvFreeEncodingInfo.3 \
	XvCreateImage.3 \
	XvGetPortAttribute.3 \
	XvGetStill.3 \
	XvGetVideo.3 \
	XvGrabPort.3 \
	XvListImageFormats.3 \
	XvPutImage.3 \
	XvPortNotify.3 \
	XvPutStill.3 \
	XvPutVideo.3 \
	XvQueryAdaptors.3 \
	XvQueryBestSize.3 \
	XvQueryEncodings.3 \
	XvQueryExtension.3 \
	XvQueryPortAttributes.3 \
	XvSelectPortNotify.3 \
	XvSelectVideoNotify.3 \
	XvSetPortAttribute.3 \
	XvShmCreateImage.3 \
	XvShmPutImage.3 \
	XvStopVideo.3 \
	XvUngrabPort.3 \
	XvVideoNotify.3

NO_STAGE=	yes
.include <bsd.port.mk>
