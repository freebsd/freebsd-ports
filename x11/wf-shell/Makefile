# $FreeBSD$

PORTNAME=	wf-shell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1-13
DISTVERSIONSUFFIX=	-gefe1fd4
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK3-based panel for wayfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libwayland-client.so:graphics/wayland

USES=		compiler:c++11-lib meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	WayfireWM

.include <bsd.port.mk>
