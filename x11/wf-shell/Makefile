PORTNAME=	wf-shell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK3-based panel for wayfire
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		wf-config>=0.7.0:devel/wf-config \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libdbusmenu-gtk3.so:devel/libdbusmenu \
		libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libwayland-client.so:graphics/wayland \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
RUN_DEPENDS=	wayland-logout:x11/wayland-logout

FLAVORS=	default nopulse
default_CONFLICTS_INSTALL=	${PORTNAME}-nopulse
nopulse_CONFLICTS_INSTALL=	${PORTNAME}
nopulse_PKGNAMESUFFIX=		-nopulse

USES=		compiler:c++17-lang gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	GNOME:libgnome-volume-control:468022b:gvc/subprojects/gvc
MESON_ARGS=	-Dgvc:alsa=false -Dwayland-logout=false
DATADIR=	${PREFIX}/share/wayfire

OPTIONS_DEFINE=	PULSEAUDIO
OPTIONS_DEFAULT=PULSEAUDIO
.if ${FLAVOR:U} == nopulse
OPTIONS_EXCLUDE=PULSEAUDIO
.endif

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	pulse

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},' \
		${WRKSRC}/src/dock/toplevel-icon.cpp \
		${WRKSRC}/src/panel/widgets/window-list/toplevel.cpp

.include <bsd.port.mk>
