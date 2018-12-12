# Created by: Nikos Ntarmos <ntarmos@ceid.upatras.gr>
# $FreeBSD$

PORTNAME=	awesome
PORTVERSION=	4.2
PORTREVISION=	3
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES=	x11-wm

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Highly configurable, next generation framework window manager

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	convert:graphics/ImageMagick6 \
		${LUA_MODLIBDIR}/lgi/corelgilua${LUA_VER_STR}.so:devel/lua-lgi
RUN_DEPENDS=	${LUA_MODLIBDIR}/lgi/corelgilua${LUA_VER_STR}.so:devel/lua-lgi \
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

CONFLICTS_INSTALL=	awesome3-[0-9]*

USES=		cmake:outsource compiler:c11 gettext iconv pkgconfig lua shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	awesomewm
SHEBANG_FILES=	utils/awesome-client
CMAKE_ARGS=	-DSYSCONFDIR=${PREFIX}/etc \
		-DAWESOME_MAN_PATH=${MANPREFIX}/man \
		-DGENERATE_DOC=OFF
USE_GNOME=	glib20 pango gdkpixbuf2
USE_XORG=	pixman x11 xau xcb xdmcp xext xft xinerama xrandr xrender \
		xorgproto

OPTIONS_DEFINE=	DBUS DOCS MANPAGES
OPTIONS_DEFAULT=DBUS MANPAGES
OPTIONS_SUB=	yes

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_CMAKE_OFF=		-DWITH_DBUS:BOOL=OFF

MANPAGES_BUILD_DEPENDS=	asciidoc:textproc/asciidoc \
			xmlto:textproc/xmlto
MANPAGES_CMAKE_OFF=	-DGENERATE_MANPAGES:BOOL=OFF

.include <bsd.port.pre.mk>

.if	(exists(${LOCALBASE}/libdata/pkgconfig/cairo.pc) && \
	!exists(${LOCALBASE}/libdata/pkgconfig/cairo-xcb.pc))
IGNORE=	cannot find dependency: The cairo exists but not with XCB support. Please reinstall graphics/cairo with XCB support
.endif

post-patch:
	# Ref https://github.com/awesomeWM/awesome/issues/1377
	@${REINPLACE_CMD} -e "/COMMAND lua/ s,lua,${LUA_CMD}," \
		${WRKSRC}/awesomeConfig.cmake
	@${REINPLACE_CMD} -e "s,^lua ,${LUA_CMD} ," \
		${WRKSRC}/build-utils/lgi-check.sh

.include <bsd.port.post.mk>
