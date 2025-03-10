PORTREVISION=	0
CATEGORIES=	x11

COMMENT=	GStreamer X and Xvideo output plugins

USES=		xorg
USE_XORG=	x11 xext xv

MESON_ARGS+=	-Dxshm=enabled \
		-Dxvideo=enabled

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		base
GST_PLUGIN=	x

BASE_GST_ENABLED_PLUGINS=	ximage \
				xvideo

.include "${MASTERDIR}/Makefile"
