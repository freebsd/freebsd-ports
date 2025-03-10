PORTREVISION=	0
CATEGORIES=	x11

COMMENT=	GStreamer X source plugin

USES=		xorg
USE_XORG=	x11 xdamage xext xfixes

MASTERDIR=	${.CURDIR:H:H}/multimedia/gstreamer1-plugins

PLIST=		${.CURDIR}/pkg-plist

DIST=		good
GST_PLUGIN=	ximagesrc

GOOD_GST_ENABLED_PLUGINS=	ximagesrc \
				ximagesrc-xdamage \
				ximagesrc-xfixes \
				ximagesrc-xshm

.include "${MASTERDIR}/Makefile"
