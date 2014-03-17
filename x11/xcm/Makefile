# $FreeBSD$

PORTNAME=	xcm
PORTVERSION=	0.5.3
CATEGORIES=	x11
MASTER_SITES=	SF/oyranos/Xcm

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	X Color Management tools

LIB_DEPENDS=	libXcm.so:${PORTSDIR}/x11/libXcm

XORG_CAT=	app
# xcm should be added to XORG_MODULES at /usr/ports/Mk/bsd.xorg.mk
# and LIB_DEPENDS is replaced by the following line:
#USE_XORG=	xcm

PLIST_FILES=	bin/xcm bin/xcmedid bin/xcmevents man/man1/xcm.1.gz \
		man/man1/xcmddc.1.gz man/man1/xcmedid.1.gz \
		man/man1/xcmevents.1.gz

.include <bsd.port.mk>
