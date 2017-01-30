# $FreeBSD$

PORTNAME=	libinput
PORTVERSION=	1.4.0
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Generic input library

BUILD_DEPENDS=	v4l_compat>=0:multimedia/v4l_compat
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libepoll-shim.so:devel/libepoll-shim \
		libwacom.so:x11/libwacom \
		libudev.so:devel/libudev-devd \
		libmtdev.so:devel/libmtdev

USE_GITHUB=	yes
GH_ACCOUNT=	FreeBSDDesktop
GH_TAGNAME=	67c9796

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
