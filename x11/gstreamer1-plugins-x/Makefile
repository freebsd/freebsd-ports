PORTREVISION=	0
CATEGORIES=	x11

COMMENT=	GStreamer X and Xvideo output plugins

GST_PLUGIN=	x

BASE_GST_ENABLED_PLUGINS=	ximage \
											xvideo
DIST=		base

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

USES=   xorg
USE_XORG=   x11 xv xext
CONFIGURE_ARGS= -Dxvideo=enabled -Dxshm=enabled

.include "${MASTERDIR}/Makefile"
