# New ports collection makefile for:    xorg-server
# Date created:		7 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libGL
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R6.8.1/tars
DISTFILES=	X11R6.8.1-src1.tar.gz \
		X11R6.8.1-src3.tar.gz
EXTRACT_ONLY=	X11R6.8.1-src1.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL library that renders using GLX or DRI

LIB_DEPENDS=	Xxf86vm.1:${PORTSDIR}/x11/libXxf86

CONFLICTS=	XFree86-libraries-* xorg-libraries-*

EXTRA_PATCHES=	${CF_PATCHES}

PREFIX?=	${X11BASE}
XBUILD_DIRS=	lib/GL
GLHEADERS=	gl.h glext.h glx.h glxext.h glxint.h glxmd.h glxproto.h \
		glxtokens.h
INSTALLS_SHLIB=	yes
USE_GNOME=	pkgconfig

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500043
BROKEN=	Requires libXThrStub, which should be part of libX11
.endif

post-extract:
	(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DIST_SUBDIR}/X11R6.8.1-src3.tar.gz | \
		${TAR} -xf - xc/programs/Xserver/hw/xfree86/os-support \
		xc/programs/Xserver/GL)

post-install:
	${MKDIR} ${PREFIX}/include/GL
.for i in ${GLHEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/GL/${i} ${PREFIX}/include/GL
.endfor

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.post.mk>
