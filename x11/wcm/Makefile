PORTNAME=	wcm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayfire Config Manager

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
USE_GNOME=	gtk30 libxml2
GH_ACCOUNT=	WayfireWM
DATADIR=	${PREFIX}/share/wayfire

OPTIONS_DEFINE=	WFSHELL
OPTIONS_DEFAULT=WFSHELL
OPTIONS_SUB=	yes

WFSHELL_DESC=			Build with wf-shell support
WFSHELL_BUILD_DEPENDS=		wf-shell>0:x11/wf-shell
WFSHELL_MESON_ENABLED=		wf_shell

.include <bsd.port.mk>
