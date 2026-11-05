PORTNAME=	awesome-devel
DISTVERSION=	4.3.20260828
CATEGORIES=	x11-wm

MAINTAINER=	wa1t5@proton.me
COMMENT=	Highly configurable, next generation framework window manager (devel)
WWW=		https://awesomewm.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LUA_REFMODLIBDIR}/lgi/corelgilua${LUA_VER_STR}.so:devel/lua-lgi@${LUA_FLAVOR}
RUN_DEPENDS=	${LUA_REFMODLIBDIR}/lgi/corelgilua${LUA_VER_STR}.so:devel/lua-lgi@${LUA_FLAVOR} \
		bash:shells/bash
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libstartup-notification-1.so:x11/startup-notification \
		libxdg-basedir.so:x11/libxdg-basedir \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-util.so:x11/xcb-util \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-xrm.so:x11/xcb-util-xrm \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c11 gettext gnome iconv magick:build pkgconfig lua \
		shebangfix xorg
USE_GNOME=	glib20 pango gdkpixbuf librsvg2
USE_XORG=	pixman x11 xau xcb xdmcp xext xft xinerama xrandr xrender \
		xorgproto

CONFLICTS_INSTALL=	awesome awesome3

USE_GITHUB=	yes
GH_ACCOUNT=	awesomewm
GH_PROJECT=	awesome
GH_TAGNAME=	0a5e50cf7ee214fae47159e0e976ab4a78d2ed4f

SHEBANG_FILES=	utils/awesome-client
CMAKE_ARGS=	-DSYSCONFDIR=${PREFIX}/etc \
		-DAWESOME_MAN_PATH=${PREFIX}/share/man \
		-DGENERATE_DOC=OFF \
		-DLUA_INCLUDE_DIR=${LUA_INCDIR} \
		-DLUA_EXECUTABLE=${LOCALBASE}/bin/lua${LUA_VER_STR}

OPTIONS_DEFINE=	DBUS DOCS MANPAGES
OPTIONS_DEFAULT=DBUS MANPAGES
OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_OFF=		-DWITH_DBUS:BOOL=OFF

MANPAGES_BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
MANPAGES_CMAKE_OFF=	-DGENERATE_MANPAGES:BOOL=OFF

DOCSDIR=	${PREFIX}/share/doc/awesome

.include <bsd.port.pre.mk>

.if	(exists(${LOCALBASE}/libdata/pkgconfig/cairo.pc) && \
	!exists(${LOCALBASE}/libdata/pkgconfig/cairo-xcb.pc))
IGNORE=	cannot find dependency: The cairo exists but not with XCB support. Please reinstall graphics/cairo with XCB support
.endif

post-patch:
	# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=267119
	# Fix build with clang14
	@${REINPLACE_CMD} -e "s/-export-dynamic/\"-Xlinker -E\"/" \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
