# New ports collection makefile for:    xlibs
# Date created:         7 May 2004
# Whom:                 anholt
#
# $FreeBSD$
#

PORTNAME=	xlibs
PORTVERSION=	1.0.1
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 core libraries

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/xproto.pc:${PORTSDIR}/x11/xproto \
		${X11BASE}/libdata/pkgconfig/xextensions.pc:${PORTSDIR}/x11/xextensions \
		${X11BASE}/libdata/pkgconfig/ice.pc:${PORTSDIR}/x11/libICE \
		${X11BASE}/libdata/pkgconfig/sm.pc:${PORTSDIR}/x11/libSM \
		${X11BASE}/libdata/pkgconfig/x11.pc:${PORTSDIR}/x11/libX11 \
		${X11BASE}/libdata/pkgconfig/xau.pc:${PORTSDIR}/x11/libXau \
		${X11BASE}/libdata/pkgconfig/xaw.pc:${PORTSDIR}/x11-toolkits/libXaw \
		${X11BASE}/libdata/pkgconfig/xcomposite.pc:${PORTSDIR}/x11/libXcomposite \
		${X11BASE}/libdata/pkgconfig/xcursor.pc:${PORTSDIR}/x11/libXcursor \
		${X11BASE}/libdata/pkgconfig/xdamage.pc:${PORTSDIR}/x11/libXdamage \
		${X11BASE}/libdata/pkgconfig/xdmcp.pc:${PORTSDIR}/x11/libXdmcp \
		${X11BASE}/libdata/pkgconfig/xext.pc:${PORTSDIR}/x11/libXext \
		${X11BASE}/libdata/pkgconfig/xfixes.pc:${PORTSDIR}/x11/libXfixes \
		${X11BASE}/libdata/pkgconfig/xfont.pc:${PORTSDIR}/x11/libXfont \
		${X11BASE}/libdata/pkgconfig/xi.pc:${PORTSDIR}/x11/libXi \
		${X11BASE}/libdata/pkgconfig/xinerama.pc:${PORTSDIR}/x11/libXinerama \
		${X11BASE}/libdata/pkgconfig/xmu.pc:${PORTSDIR}/x11-toolkits/libXmu \
		${X11BASE}/libdata/pkgconfig/xpm.pc:${PORTSDIR}/x11/libXpm \
		${X11BASE}/libdata/pkgconfig/xrender.pc:${PORTSDIR}/x11/libXrender \
		${X11BASE}/libdata/pkgconfig/xrandr.pc:${PORTSDIR}/x11/libXrandr \
		${X11BASE}/libdata/pkgconfig/xres.pc:${PORTSDIR}/x11/libXres \
		${X11BASE}/libdata/pkgconfig/xt.pc:${PORTSDIR}/x11-toolkits/libXt \
		${X11BASE}/libdata/pkgconfig/xv.pc:${PORTSDIR}/x11/libXv
LIB_DEPENDS=	Xp.6:${PORTSDIR}/x11/libXp \
		xkbfile.1:${PORTSDIR}/x11/libxkbfile \
		Xxf86vm.1:${PORTSDIR}/x11/libXxf86 \
		GL.1:${PORTSDIR}/x11/libGL \
		GLU.1:${PORTSDIR}/graphics/libGLU
BUILD_DEPENDS=	${LIB_PC_DEPENDS}
RUN_DEPENDS=	${LIB_PC_DEPENDS}

CONFLICTS=	XFree86-libraries-*

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
