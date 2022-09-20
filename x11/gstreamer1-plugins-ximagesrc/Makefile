PORTREVISION=	0
CATEGORIES=	x11
PKGNAMESUFFIX=	1-plugins-ximagesrc

COMMENT=	GStreamer X source plugin

GST_PLUGIN=	ximagesrc
DIST=		good

GOOD_GST_ENABLED_PLUGINS=	ximagesrc \
													ximagesrc-xshm \
													ximagesrc-xfixes \
													ximagesrc-xdamage

MASTERDIR=	${.CURDIR}/../../multimedia/gstreamer1-plugins

PLIST=  ${.CURDIR}/pkg-plist

USES=   xorg
USE_XORG=   x11 xfixes xdamage xext

.include "${MASTERDIR}/Makefile"
