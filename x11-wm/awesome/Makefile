# New ports collection makefile for:   awesome
# Date created:                September 26, 2007
# Whom:                        Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	awesome
PORTVERSION=	3.4.13
CATEGORIES=	x11-wm
MASTER_SITES=	http://awesome.naquadah.org/download/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A highly configurable, next generation framework window manager

LICENSE=	GPLv2

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		convert:${PORTSDIR}/graphics/ImageMagick \
		gperf>=3.0.3:${PORTSDIR}/devel/gperf \
		pango>=1.19.3:${PORTSDIR}/x11-toolkits/pango \
		xmlto:${PORTSDIR}/textproc/xmlto \
		xcb-util>=0.3.8:${PORTSDIR}/x11/xcb-util \
		xproto>=7.0.11:${PORTSDIR}/x11/xproto \
		${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml-450
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		ev:${PORTSDIR}/devel/libev \
		freetype:${PORTSDIR}/print/freetype2 \
		startup-notification-1:${PORTSDIR}/x11/startup-notification \
		xdg-basedir:${PORTSDIR}/x11/libxdg-basedir \
		xcb:${PORTSDIR}/x11/libxcb \
		xcb-util:${PORTSDIR}/x11/xcb-util \
		xcb-image:${PORTSDIR}/x11/xcb-util-image \
		xcb-keysyms:${PORTSDIR}/x11/xcb-util-keysyms \
		xcb-icccm:${PORTSDIR}/x11/xcb-util-wm \
		execinfo:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USE_ICONV=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DSYSCONFDIR=${PREFIX}/etc
USE_EFL=	imlib2
USE_GNOME=	glib20 pango
USE_LUA=	5.1+
USE_XORG=	pixman x11 xau xdmcp xext xft xinerama xrandr xrender xproto

MAN1=	awesome.1 \
	awesome-client.1 \
	awsetbg.1
MAN5=	awesomerc.5
MANLANG=	"" de es fr
MANCOMPRESSED=	yes
PORTDOCS=	AUTHORS BUGS LICENSE README

OPTIONS_DEFINE=	DBUS DOCS
OPTIONS_DEFAULT=DBUS DOCS

.include <bsd.port.pre.mk>

.if	(exists(${LOCALBASE}/libdata/pkgconfig/cairo.pc) && \
	!exists(${LOCALBASE}/libdata/pkgconfig/cairo-xcb.pc))
IGNORE=	cannot find dependency: The cairo exists but not with XCB support. Please reinstall graphics/cairo with XCB support
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS += dbus-1.3:${PORTSDIR}/devel/dbus
CMAKE_ARGS += -DWITH_DBUS=YES
.else
CMAKE_ARGS += -DWITH_DBUS=NO
.endif

pre-configure:
	@${REINPLACE_CMD} \
	-e 's/"generate luadoc" ON/\"generate luadoc" OFF/g' \
		${WRKSRC}/awesomeConfig.cmake
	@${REINPLACE_CMD} \
	-e 's,tr ,env LC_ALL="C" ${TR} ,g' \
	-e 's,gperf,${LOCALBASE}/bin/gperf,g' \
		${WRKSRC}/build-utils/gperf.sh
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} \
		-e 's/"install port docs" ON/\"install port docs" OFF/g' \
		${WRKSRC}/awesomeConfig.cmake
.endif

post-patch:
	@${RM} -f ${WRKSRC}/lib/awful/placement.lua.in.orig

.include <bsd.port.post.mk>
