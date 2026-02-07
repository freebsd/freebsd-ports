PORTNAME=	xcb-proto
PORTVERSION=	1.17.0
CATEGORIES=	x11 python
MASTER_SITES=	XORG/individual/proto

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) protocol
WWW=		https://xcb.freedesktop.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gnome python tar:xz
USE_GNOME=	libxml2:build
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/xcb

.include <bsd.port.mk>
