# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libXxf86vm
PORTVERSION=	1.1.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X Vidmode Extension

LICENSE=	MIT

XORG_CAT=	lib
USE_XORG=	xproto x11 xextproto xext xf86vidmodeproto:both

MAN3=		XF86VM.3 \
		XF86VidModeLockModeSwitch.3 \
		XF86VidModeDeleteModeLine.3 \
		XF86VidModeModModeLine.3 \
		XF86VidModeGetAllModeLines.3 \
		XF86VidModeQueryExtension.3 \
		XF86VidModeGetDotClocks.3 \
		XF86VidModeQueryVersion.3 \
		XF86VidModeGetGamma.3 \
		XF86VidModeSetClientVersion.3 \
		XF86VidModeGetGammaRamp.3 \
		XF86VidModeSetGamma.3 \
		XF86VidModeGetGammaRampSize.3 \
		XF86VidModeSetGammaRamp.3 \
		XF86VidModeGetModeLine.3 \
		XF86VidModeSetViewPort.3 \
		XF86VidModeGetMonitor.3 \
		XF86VidModeSwitchMode.3 \
		XF86VidModeGetPermissions.3 \
		XF86VidModeSwitchToMode.3 \
		XF86VidModeGetViewPort.3 \
		XF86VidModeValidateModeLine.3

NO_STAGE=	yes
.include <bsd.port.mk>
