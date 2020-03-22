# $FreeBSD$

PORTNAME=	wf-shell
DISTVERSION=	0.4.0
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	d86538344ade1.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK3-based panel for wayfire

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		wf-config>=0.4.0:devel/wf-config \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libwayland-client.so:graphics/wayland \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	GNOME:libgnome-volume-control:468022b:gvc/subprojects/gvc
MESON_ARGS=	-Dgvc:alsa=false
DATADIR=	${PREFIX}/share/wayfire

OPTIONS_DEFINE=	PULSEAUDIO
OPTIONS_DEFAULT=PULSEAUDIO

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulse

.include <bsd.port.mk>
