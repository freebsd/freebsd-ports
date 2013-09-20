# $FreeBSD$

PORTNAME=	libXcm
PORTVERSION=	0.5.2
CATEGORIES=	x11
MASTER_SITES=	SF/oyranos/${PORTNAME}/${PORTNAME}-${PORTVERSION:C|(.*)\.[0-9]*$|\1|}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	X Colour Management Library

LICENSE=	MIT

XORG_CAT=	lib
USES=		pkgconfig
USE_XORG=	xfixes xmu

MAN3=		Xcm.3 XcmDDC.3 XcmEdidParse.3 XcmEvents.3 XcolorProfile.3 \
		XcolorRegion.3 libXcm.3

NO_STAGE=	yes
post-patch:
	@${SED} -I.bak -e 's:{libdir}/pkgconfig:{prefix}/libdata/pkgconfig:g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
