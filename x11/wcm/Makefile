PORTNAME=	wcm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wayfire Config Manager
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>0:graphics/wayland-protocols \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libwf-config.so:devel/wf-config \
		libwayland-client.so:graphics/wayland \
		libfmt.so:devel/libfmt \
		libxkbregistry.so:x11/libxkbcommon
RUN_DEPENDS=	wayfire>0:x11-wm/wayfire

USES=		compiler:c++17-lang gettext gnome meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	WayfireWM
USE_GNOME=	gtk30 gtkmm30 libxml2

CONFLICTS_INSTALL=	wcmcommander # bin/wcm

OPTIONS_DEFINE=		WDISPLAYS WFSHELL
OPTIONS_DEFAULT=	WDISPLAYS WFSHELL
OPTIONS_SUB=		yes

WDISPLAYS_DESC=		Configure outputs via wdisplays
WFSHELL_DESC=		Build with wf-shell support

WDISPLAYS_RUN_DEPENDS=	wdisplays>0:x11/wdisplays
WFSHELL_BUILD_DEPENDS=	wf-shell>0:x11/wf-shell
WFSHELL_MESON_ENABLED=	wf_shell

.include <bsd.port.mk>
