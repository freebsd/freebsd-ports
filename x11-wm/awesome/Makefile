# Created by: Nikos Ntarmos <ntarmos@ceid.upatras.gr>
# $FreeBSD$

PORTNAME=	awesome
PORTVERSION=	3.5.8
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://awesome.naquadah.org/download/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Highly configurable, next generation framework window manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
		convert:graphics/ImageMagick \
		pango>=1.19.3:x11-toolkits/pango \
		xmlto:textproc/xmlto \
		xcb-util>=0.3.8:x11/xcb-util \
		xproto>=7.0.11:x11/xproto \
		${LUA_MODLIBDIR}/lgi/corelgilua${LUA_VER_STR}.so:devel/lua-lgi \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS=	${LUA_MODLIBDIR}/lgi/corelgilua${LUA_VER_STR}.so:devel/lua-lgi
LIB_DEPENDS=	libcairo.so:graphics/cairo \
		libev.so:devel/libev \
		libfreetype.so:print/freetype2 \
		libstartup-notification-1.so:x11/startup-notification \
		libxdg-basedir.so:x11/libxdg-basedir \
		libxcb-util.so:x11/xcb-util \
		libxcb-cursor.so:x11/xcb-util-cursor \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-icccm.so:x11/xcb-util-wm \
		libImlib2.so:graphics/imlib2

USES=		cmake execinfo iconv pkgconfig lua tar:xz
CMAKE_ARGS+=	-DSYSCONFDIR=${PREFIX}/etc
USE_GNOME=	glib20 pango gdkpixbuf2
USE_XORG=	pixman x11 xau xcb xdmcp xext xft xinerama xrandr xrender \
		xproto
LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	AUTHORS BUGS LICENSE README

OPTIONS_DEFINE=	DBUS DOCS
OPTIONS_DEFAULT=DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_ON=		-DWITH_DBUS=YES
DBUS_CMAKE_OFF=		-DWITH_DBUS=NO

.include <bsd.port.pre.mk>

.if	(exists(${LOCALBASE}/libdata/pkgconfig/cairo.pc) && \
	!exists(${LOCALBASE}/libdata/pkgconfig/cairo-xcb.pc))
IGNORE=	cannot find dependency: The cairo exists but not with XCB support. Please reinstall graphics/cairo with XCB support
.endif

post-patch:
	@${REINPLACE_CMD} -e "/LUA_EXECUTABLE lua/ s,lua,lua${LUA_VER_STR}," \
		-e '/Lua51/d' \
		-e 's/glib-2.0/lua-${LUA_VER} glib-2.0/g' \
		-e '/LUA51_FOUND/,+2d' \
		${WRKSRC}/awesomeConfig.cmake
	@${REINPLACE_CMD} -e "s,^lua ,${LUA_CMD} ," \
		${WRKSRC}/build-utils/lgi-check.sh

.include <bsd.port.post.mk>
