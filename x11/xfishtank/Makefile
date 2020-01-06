# Created by: jacs
# $FreeBSD$

PORTNAME=	xfishtank
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://cyber.dabamos.de/pub/distfiles/

MAINTAINER=	kidon@posteo.de
COMMENT=	Make fish swim in the background of your screen

PLIST_FILES=	bin/xfishtank
USES=		imake xorg
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/xfishtank2.0

post-patch:
	cd  ${WRKDIR}/xfishtank2.0; make clean

.include <bsd.port.mk>
