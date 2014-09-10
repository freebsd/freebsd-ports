# Created by: gena
# $FreeBSD$

PORTNAME=	xforms
DISTVERSION=	1.2.4
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Graphical user interface toolkit for X Window System

LICENSE=	LGPL21

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff

USES=		libtool
USE_XORG=	xpm
USE_GL=		gl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BROKEN_ia64=	Does not compile on ia64

.include <bsd.port.mk>
