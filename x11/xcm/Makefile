# $FreeBSD$

PORTNAME=	xcm
PORTVERSION=	0.5.2
CATEGORIES=	x11
MASTER_SITES=	SF/oyranos/Xcm

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	X Color Management tools

LIB_DEPENDS=	Xcm:${PORTSDIR}/x11/libXcm

XORG_CAT=	app
# xcm should be added to XORG_MODULES at /usr/ports/Mk/bsd.xorg.mk
NO_STAGE=	yes
# and LIB_DEPENDS is replaced by the following line:
#USE_XORG=	xcm

PLIST_FILES=	bin/xcm bin/xcmedid bin/xcmevents

MAN1=		xcm.1 xcmddc.1 xcmedid.1 xcmevents.1

.include <bsd.port.mk>
