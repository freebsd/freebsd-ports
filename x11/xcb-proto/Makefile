# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	xcb-proto
PORTVERSION=	1.13
PORTREVISION=	1
CATEGORIES=	x11 python
MASTER_SITES=	https://xcb.freedesktop.org/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome python xorg-cat:proto
USE_GNOME=	libxml2:build
USE_PYTHON=	py3kplist
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/xcb

.include <bsd.port.mk>
