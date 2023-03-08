PORTNAME=	thingylaunch
PORTVERSION=	3.0.1
CATEGORIES=	x11
MASTER_SITES=	https://code.ptrcrt.ch/${PORTNAME}/tarball/${PORTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight launcher for X
WWW=		https://code.ptrcrt.ch/${PORTNAME}

LICENSE=	BSD2CLAUSE

USES=		compiler:c++11-lib pkgconfig xorg
USE_XORG=	xorgproto xcb
LIB_DEPENDS+=	libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms
USE_CXXSTD=	c++11

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
