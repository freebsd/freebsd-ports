# Created by: jacs
# $FreeBSD$

PORTNAME=	xfishtank
PORTVERSION=	2.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=	jacs@gnome.co.uk
COMMENT=	Make fish swim in the background of your screen

BROKEN=		unfetchable

PLIST_FILES=	bin/xfishtank
USES=		imake xorg
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/xfishtank2.0

post-patch:
	cd  ${WRKDIR}/xfishtank2.0; make clean

.include <bsd.port.mk>
