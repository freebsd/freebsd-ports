# Created by: gena
# $FreeBSD$

PORTNAME=	xforms
DISTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A graphical user interface toolkit for X Window System

LICENSE=	LGPL21

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff

USE_XORG=	xpm
USE_GL=		gl
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

.include <bsd.port.post.mk>
