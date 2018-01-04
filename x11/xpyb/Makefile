# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	xpyb
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	http://xcb.freedesktop.org/dist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Python bindings to access X Window System protocol via libxcb

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xcb-proto.pc:x11/xcb-proto \
		xcb-proto>=1.7.1:x11/xcb-proto

USES=		libtool pathfix pkgconfig python:2.7 tar:bzip2
USE_PYTHON=	flavors
USE_XORG=	xcb
PORTDOCS=	README COPYING INSTALL NEWS XcbPythonBinding.txt

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
