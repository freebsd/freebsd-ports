# $FreeBSD$

PORTNAME=	wf-shell
DISTVERSION=	0.3
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK3-based panel for wayfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
		libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libwayland-client.so:graphics/wayland \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		compiler:c++14-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	GNOME:libgnome-volume-control:468022b:gvc/subprojects/gvc
MESON_ARGS=	-Dgvc:alsa=false
DATADIR=	${PREFIX}/share/wayfire

.include <bsd.port.mk>
