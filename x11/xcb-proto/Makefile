# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	xcb-proto
PORTVERSION=	1.11
CATEGORIES=	x11 python
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) protocol

USE_GNOME=	libxml2:build
XORG_CAT=	proto
USES=		python

DATADIR=	${PREFIX}/share/xcb

.include <bsd.port.pre.mk>

.if ${PYTHON_MAJOR_VER} == 3
PLIST_SUB+=	PYTHON_SUFFIX=${PYTHON_SUFFIX} PY3="" PY2="@comment "
.else
PLIST_SUB+=	PY2="" PY3="@comment "
.endif

.include <bsd.port.post.mk>
