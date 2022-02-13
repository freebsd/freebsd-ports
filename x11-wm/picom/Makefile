PORTNAME=	picom
DISTVERSIONPREFIX=	v
DISTVERSION=	9.1
CATEGORIES=	x11-wm

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Lightweight X11 compositor

LICENSE=	MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSES/MIT

BUILD_DEPENDS=	${LOCALBASE}/include/uthash.h:devel/uthash
LIB_DEPENDS=	libev.so:devel/libev \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-render-util.so:x11/xcb-util-renderutil
RUN_DEPENDS=	xprop:x11/xprop \
		xwininfo:x11/xwininfo

USES=		compiler:c11 meson localbase pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	x11 xcb xext pixman
GH_ACCOUNT=	yshui
MESON_ARGS=	-Dcompton=false -Dunittest=true
TEST_TARGET=	test
PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-trans \
		"@sample etc/xdg/${PORTNAME}.conf.sample" \
		share/applications/${PORTNAME}.desktop

OPTIONS_DEFINE=	CONFIG DBUS DOCS DRM OPENGL PCRE
OPTIONS_DEFAULT=CONFIG DBUS OPENGL PCRE

CONFIG_DESC=		Configuration file parsing support
CONFIG_LIB_DEPENDS=	libconfig.so:devel/libconfig
CONFIG_MESON_TRUE=	config_file

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_MESON_TRUE=	regex

DRM_DESC=		DRM VSync fallback (deprecated)
DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_MESON_TRUE=		vsync_drm

OPENGL_USES=		gl
OPENGL_USE=		GL=gl
OPENGL_MESON_TRUE=	opengl

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MESON_TRUE=	dbus

DOCS_BUILD_DEPENDS=	a2x:textproc/asciidoc
DOCS_MESON_TRUE=	with_docs
DOCS_PLIST_FILES=	man/man1/${PORTNAME}.1.gz \
			man/man1/${PORTNAME}-trans.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/config_libconfig.c
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e "/project_version/s/=.*/= '${DISTVERSIONFULL}'/" \
		${WRKSRC}/meson.build

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.sample.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/${PORTNAME}.conf.sample

.include <bsd.port.mk>
