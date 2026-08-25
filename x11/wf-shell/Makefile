PORTNAME=	wf-shell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK3-based panel for wayfire
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols \
		wf-config>=0.7.0:devel/wf-config \
		wayfire>0:x11-wm/wayfire
LIB_DEPENDS=	libdbusmenu-glib.so:devel/libdbusmenu \
		libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libwayland-client.so:graphics/wayland \
		libepoxy.so:graphics/libepoxy \
		libxkbregistry.so:x11/libxkbcommon \
		libyyjson.so:devel/yyjson \
		libdrm.so:graphics/libdrm
RUN_DEPENDS=	wayland-logout:x11/wayland-logout

FLAVORS=	default nopipewire nopulse lite
FLAVOR?=	${FLAVORS:[1]}
${FLAVOR}_PKGNAMESUFFIX=	${FLAVOR:N${FLAVORS:[1]}:C|(.+)|-\1|}

USES=		compiler:c++17-lang gl gnome meson pkgconfig vala:build ssl
USE_GITHUB=	yes
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	wmww:gtk4-layer-shell:v1.3.0:gtk4_layer_shell/subprojects/gtk4-layer-shell \
		GNOME:libgnome-volume-control:5f9768a:gvc/subprojects/gvc \
		WayfireWM:wf-json:70039e1:wf_json/subprojects/wf-json
USE_GL=		gbm
USE_GNOME=	gtkmm40
MESON_ARGS=	-Dgvc:alsa=false -Dwayland-logout=false -Dddcutil=disabled
LDFLAGS+=	-lpam -lpthread

CONFLICTS_INSTALL=	${PORTNAME}*

OPTIONS_DEFINE=		PIPEWIRE PULSEAUDIO
OPTIONS_DEFAULT=	PIPEWIRE PULSEAUDIO
.if ${FLAVOR:U} == nopipewire || ${FLAVOR:U} == lite
OPTIONS_EXCLUDE+=	PIPEWIRE
.endif
.if ${FLAVOR:U} == nopulse || ${FLAVOR:U} == lite
OPTIONS_EXCLUDE+=	PULSEAUDIO
.endif

PIPEWIRE_LIB_DEPENDS=	libwireplumber-0.5.so:multimedia/wireplumber
PIPEWIRE_MESON_ENABLED=	wp-mixer-widget

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_MESON_ENABLED=	volume-widget

post-patch:
	${LN} -s . ${WRKSRC}/subprojects/gtk4-layer-shell/include/gtk4-layer-shell
	${REINPLACE_CMD} 's|/etc/|${LOCALBASE}/etc/|' ${WRKSRC}/data/meson.build

.include <bsd.port.mk>
