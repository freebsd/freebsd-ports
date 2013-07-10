# Created by: Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
# $FreeBSD$

PORTNAME=	Xbae
PORTVERSION=	4.60.4
PORTREVISION=	1
CATEGORIES=	x11-toolkits math
MASTER_SITES=	SF
DISTNAME=	xbae-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif-based widget which displays a grid of cells as a spreadsheet

USES=		motif
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=--enable-production --enable-static

MAN3=		XbaeCaption.3 XbaeInput.3 XbaeMatrix.3

.include <bsd.port.mk>
