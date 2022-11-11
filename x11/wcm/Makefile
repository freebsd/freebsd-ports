PORTNAME=	wcm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	x11 wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	aade4224e23e.patch:-p1 # https://github.com/WayfireWM/wcm/pull/69

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayfire Config Manager
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwf-config.so:devel/wf-config \
		libwayland-client.so:graphics/wayland
RUN_DEPENDS=	wayfire>0:x11-wm/wayfire

CONFLICTS_INSTALL=	wcmcommander # bin/wcm

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf2 gtk30 libxml2
GH_ACCOUNT=	WayfireWM
MESON_ARGS=	-Denable_wdisplays=false # use package
DATADIR=	${PREFIX}/share/wayfire

OPTIONS_DEFINE=	WDISPLAYS WFSHELL
OPTIONS_DEFAULT=WDISPLAYS WFSHELL
OPTIONS_SUB=	yes

WDISPLAYS_DESC=			Configure outputs via wdisplays
WDISPLAYS_RUN_DEPENDS=		wdisplays>0:x11/wdisplays

WFSHELL_DESC=			Build with wf-shell support
WFSHELL_BUILD_DEPENDS=		wf-shell>0:x11/wf-shell
WFSHELL_MESON_ENABLED=		wf_shell

.include "${.CURDIR:H:H}/x11-toolkits/wlroots016/override.mk"
.include <bsd.port.mk>
