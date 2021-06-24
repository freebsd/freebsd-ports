PORTNAME=	wayfire-plugins-extra
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	a8eca14c44b9.patch:-p1 # https://github.com/WayfireWM/wayfire-plugins-extra/pull/106

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Additional plugins for Wayfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-scanner:graphics/wayland \
		wayland-protocols>0:graphics/wayland-protocols \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libwf-config.so:devel/wf-config \
		libwlroots.so:x11-toolkits/wlroots

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo glibmm
GH_ACCOUNT=	WayfireWM

.include <bsd.port.mk>
