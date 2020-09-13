# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	xcb-proto
PORTVERSION=	1.14
CATEGORIES=	x11 python
MASTER_SITES=	https://xcb.freedesktop.org/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) protocol

PATCH_SITES=	https://gitlab.freedesktop.org/xorg/proto/xcbproto/-/commit/
PATCHFILES+=	2b3559c10c18eb63e61efdc8a030765d624a0fba.diff:-p1
PATCHFILES+=	426ae35bee1fa0fdb8b5120b1dcd20cee6e34512.diff:-p1
PATCHFILES+=	7d58eed95f796fc764741d7549ee2214bbbcc64c.diff:-p1
PATCHFILES+=	029d5b5d705a27a9bb16fb7fb9b0d2b03dab424a.diff:-p1

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome python tar:xz xorg-cat:proto
USE_GNOME=	libxml2:build
USE_PYTHON=	py3kplist
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/xcb

.include <bsd.port.mk>
