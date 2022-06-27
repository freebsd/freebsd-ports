# Created by: Ashish Shukla <wahjava@gmail.com>

PORTNAME=	xcb-proto
PORTVERSION=	1.15.2
CATEGORIES=	x11 python

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome python tar:xz xorg-cat:proto
USE_GNOME=	libxml2:build
USE_PYTHON=	py3kplist
NO_ARCH=	yes
MAKE_ARGS=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

DATADIR=	${PREFIX}/share/xcb

.include <bsd.port.mk>
