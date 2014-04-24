# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	xpyb
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	http://xcb.freedesktop.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	dist
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Python bindings to access X Window System protocol via libxcb

OPTIONS_DEFINE=	DOCS

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-proto.pc:${PORTSDIR}/x11/xcb-proto \
		xcb-proto>=1.7.1:${PORTSDIR}/x11/xcb-proto

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_XORG=	xcb
USES=	pathfix pkgconfig
PORTDOCS=	README COPYING INSTALL NEWS XcbPythonBinding.txt

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
