# $FreeBSD$

PORTNAME=	xcb-util-xrm
PORTVERSION=	1.0
CATEGORIES=	x11 devel
MASTER_SITES=	http://github.com/Airblader/xcb-util-xrm/releases/download/v${PORTVERSION}/ \
		https://github.com/Airblader/xcb-util-xrm/releases/download/v${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XCB utility functions for the X resource manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxcb-util.so:x11/xcb-util

USES=		libtool pathfix pkgconfig tar:bzip2
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
USE_XORG=	xcb
USE_LDCONFIG=	yes

.include <bsd.port.mk>
