# New ports collection makefile for:	XFree86-libraries
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	libraries
PORTVERSION=	4.3.0
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X430src-1.tgz:x \
		X430src-2.tgz:x \
		X430src-3.tgz:x \
		Wraphelp2.gz:local
EXTRACT_ONLY=	X430src-1.tgz \
		X430src-2.tgz \
		X430src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 libraries and headers

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

CONFLICTS=	libX11-* libGL-* libGLU-* libICE-* libSM-* libXau-* libXaw-* \
		libXcursor-* libXdmcp-* libXext-* libXfont-* libXi-* \
		libXinerama-* libXmu-* libXp-* libXpm-* libXrandr-* \
		libXrender-* libXres-* libXt-* libXv-* libXxf86-* libxkbfile-* \
		panoramixext-* printext-* randrext-* renderext-* resourceext-* \
		xextensions-* xf86ext-* xlibs-* xorg-libraries-* xproto-*

USE_X_PREFIX=		no
PREFIX?=		${X11BASE}
MTREE_FILE=		/etc/mtree/BSD.x11-4.dist
INSTALLS_SHLIB=		yes
SCRIPTS_ENV=		DebuggableLibraries=${DebuggableLibraries}
MAN3=			Xaw.3 Xcursor.3 Xrandr.3
XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINCLUDE_DIRS=		programs/proxymngr
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

# XFree86 User Config:
# DebuggableLibraries NO	build with debug libs (require FreeBSD-4 or later)
# ----------------------------------------------------------------------------
DebuggableLibraries?=	NO
# End of XFree86 User Config

.ifdef USE_XLIB
.error You have `USE_XLIB' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include "Makefile.inc"
.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif

# BuildXF86DRI is false for FreeBSD < 4.1
.if ${OSVERSION} < 410000
PLIST_SUB+=	OSMESA:="@comment "
.else
PLIST_SUB+=	OSMESA:=""
.endif

# sparc64 doesn't have a working libc_r yet, and -current doesn't need libXThrStub.
.if ${MACHINE_ARCH} == "sparc64" || ${OSVERSION} >= 500043
PLIST_SUB+=	XTHRSTUB:="@comment "
.else
PLIST_SUB+=	XTHRSTUB:=""
.endif

# amd64 also supplies libxkbfile.so*
.if ${MACHINE_ARCH} == "amd64"
PLIST_SUB+=	AMD64:=""
.else
PLIST_SUB+=	AMD64:="@comment "
.endif

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp2.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

post-patch:
	${CP} ${FILESDIR}/nls::Compose::microsoft-cp1251 ${WRKSRC}/nls/Compose/microsoft-cp1251
	${MKDIR} ${WRKSRC}/exports/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/programs/proxymngr/PM.h \
		${PREFIX}/include/X11/PM
	${INSTALL_DATA} ${WRKSRC}/programs/proxymngr/PMproto.h \
		${PREFIX}/include/X11/PM
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/lib/Xcursor/xcursor.pc \
		${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
