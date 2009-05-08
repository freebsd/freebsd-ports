# New ports collection makefile for:   awesome
# Date created:                September 26, 2007
# Whom:                        Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	awesome
DISTVERSION=	3.3-rc2
CATEGORIES=	x11-wm
MASTER_SITES=	http://awesome.naquadah.org/download/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	A highly configurable, next generation framework window manager

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		gperf>=3.0.3:${PORTSDIR}/devel/gperf \
		pango>=1.19.3:${PORTSDIR}/x11-toolkits/pango \
		xmlto:${PORTSDIR}/textproc/xmlto \
		xcb-util>=0.3.4:${PORTSDIR}/x11/xcb-util \
		xproto>=7.0.11:${PORTSDIR}/x11/xproto
LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		ev.3:${PORTSDIR}/devel/libev \
		freetype.9:${PORTSDIR}/print/freetype2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		xdg-basedir.1:${PORTSDIR}/x11/libxdg-basedir \
		xcb.2:${PORTSDIR}/x11/libxcb \
		xcb-event.1:${PORTSDIR}/x11/xcb-util

USE_ICONV=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=yes
CMAKE_ARGS+=	-DSYSCONFDIR=${PREFIX}/etc
USE_EFL=	imlib2
USE_GNOME=	glib20 pango
USE_LUA=	5.1+
USE_XORG=	pixman x11 xau xdmcp xext xft xinerama xrandr xrender xproto

MAN1=	awesome.1 \
	awesome-client.1 \
	awsetbg.1
MAN5=	awesomerc.5
MANCOMPRESSED=	yes
PORTDOCS=	AUTHORS BUGS LICENSE README

OPTIONS+=	DBUS "Enable D-BUS support" On

.include <bsd.port.pre.mk>

.if	(exists(${LOCALBASE}/libdata/pkgconfig/cairo.pc) && \
	!exists(${LOCALBASE}/libdata/pkgconfig/cairo-xcb.pc))
IGNORE=	cannot find dependency: The cairo exists but not with XCB support. Please reinstall graphics/cairo with XCB support
.endif

.ifdef(WITH_DBUS)
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
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} \
		-e 's/"install port docs" ON/\"install port docs" OFF/g' \
		${WRKSRC}/awesomeConfig.cmake
.endif

.include <bsd.port.post.mk>
