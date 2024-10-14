PORTNAME=	picom
DISTVERSIONPREFIX=	v
DISTVERSION=	12.3
CATEGORIES=	x11-wm

MAINTAINER=	yukiteruamano@volfread.xyz
COMMENT=	Lightweight X11 compositor
WWW=		https://github.com/yshui/picom

LICENSE=	MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash
LIB_DEPENDS=	libev.so:devel/libev \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-util.so:x11/xcb-util
RUN_DEPENDS=	xprop:x11/xprop \
		xwininfo:x11/xwininfo

USES=		compiler:c11 desktop-file-utils localbase meson pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	yshui
GH_PROJECT=	picom

USE_XORG=	pixman x11 xcb xext

MESON_ARGS=	-Dcompton=false -Dunittest=true
TEST_TARGET=	test
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-inspect \
		bin/${PORTNAME}-trans \
		"@sample etc/xdg/${PORTNAME}.conf.sample" \
		etc/xdg/autostart/${PORTNAME}.desktop \
		libdata/pkgconfig/${PORTNAME}-api.pc \
		share/applications/${PORTNAME}.desktop

OPTIONS_DEFINE=		CONFIG DBUS DOCS DRM OPENGL PCRE
OPTIONS_DEFAULT=	CONFIG DBUS OPENGL PCRE

CONFIG_DESC=	Configuration file parsing support
DRM_DESC=	DRM VSync fallback (deprecated)

CONFIG_LIB_DEPENDS=	libconfig.so:devel/libconfig

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_TRUE=	dbus

DOCS_BUILD_DEPENDS=	a2x:textproc/asciidoc \
			asciidoctor:textproc/rubygem-asciidoctor
DOCS_MESON_TRUE=	with_docs
DOCS_PLIST_FILES=	share/man/man1/${PORTNAME}-inspect.1.gz \
			share/man/man1/${PORTNAME}-trans.1.gz \
			share/man/man1/${PORTNAME}.1.gz

DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_MESON_TRUE=		vsync_drm

OPENGL_LIB_DEPENDS=	libepoxy.so:graphics/libepoxy
OPENGL_MESON_TRUE=	opengl

PCRE_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
PCRE_MESON_TRUE=	regex

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/man/${PORTNAME}.1.adoc \
		${WRKSRC}/src/config.c

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.sample.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}.conf.sample

.include <bsd.port.mk>
