# Created by: Nikos Ntarmos <ntarmos@ceid.upatras.gr>
# $FreeBSD$

PORTNAME=	awesome
PORTVERSION=	3.5.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://awesome.naquadah.org/download/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A highly configurable, next generation framework window manager

LICENSE=	GPLv2

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		convert:${PORTSDIR}/graphics/ImageMagick \
		pango>=1.19.3:${PORTSDIR}/x11-toolkits/pango \
		xmlto:${PORTSDIR}/textproc/xmlto \
		xcb-util>=0.3.8:${PORTSDIR}/x11/xcb-util \
		xproto>=7.0.11:${PORTSDIR}/x11/xproto \
		${LUA_MODLIBDIR}/lgi/corelgilua51.so:${PORTSDIR}/devel/lua-lgi \
		${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml-450
RUN_DEPENDS=	${LUA_MODLIBDIR}/lgi/corelgilua51.so:${PORTSDIR}/devel/lua-lgi
LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libev.so:${PORTSDIR}/devel/libev \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification \
		libxdg-basedir.so:${PORTSDIR}/x11/libxdg-basedir \
		libxcb-util.so:${PORTSDIR}/x11/xcb-util \
		libxcb-cursor.so:${PORTSDIR}/x11/xcb-util-cursor \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms \
		libxcb-icccm.so:${PORTSDIR}/x11/xcb-util-wm \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo

USE_XZ=		yes
USES=		cmake iconv pkgconfig
CMAKE_ARGS+=	-DSYSCONFDIR=${PREFIX}/etc
USE_EFL=	imlib2
USE_GNOME=	glib20 pango gdkpixbuf2
USE_LUA=	5.1+
USE_XORG=	pixman x11 xau xcb xdmcp xext xft xinerama xrandr xrender \
		xproto
LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	AUTHORS BUGS LICENSE README

OPTIONS_DEFINE=	DBUS DOCS
OPTIONS_DEFAULT=DBUS DOCS

DBUS_LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus
DBUS_CMAKE_ON=		-DWITH_DBUS=YES
DBUS_CMAKE_OFF=		-DWITH_DBUS=NO

.include <bsd.port.pre.mk>

.if	(exists(${LOCALBASE}/libdata/pkgconfig/cairo.pc) && \
	!exists(${LOCALBASE}/libdata/pkgconfig/cairo-xcb.pc))
IGNORE=	cannot find dependency: The cairo exists but not with XCB support. Please reinstall graphics/cairo with XCB support
.endif

post-patch:
	@${REINPLACE_CMD} -e "/LUA_EXECUTABLE lua/ s,lua,lua-${LUA_VER}," \
		${WRKSRC}/awesomeConfig.cmake
	@${REINPLACE_CMD} -e "s,^lua ,${LUA_CMD} ," \
		${WRKSRC}/build-utils/lgi-check.sh

.include <bsd.port.post.mk>
