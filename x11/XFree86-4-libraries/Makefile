# New ports collection makefile for:	XFree86-libraries
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	libraries
PORTVERSION=	4.4.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-4.4.0-src-1.tgz:x \
		XFree86-4.4.0-src-2.tgz:x \
		XFree86-4.4.0-src-3.tgz:x \
		Wraphelp2.gz:local
EXTRACT_ONLY=	XFree86-4.4.0-src-1.tgz \
		XFree86-4.4.0-src-2.tgz \
		XFree86-4.4.0-src-3.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 libraries and headers

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

CONFLICTS=	Mesa-* libX11-* libGL-* libGLU-* libICE-* libSM-* libXau-* \
		libXaw-* libXcursor-* libXdmcp-* libXext-* libXfont-* libXi-* \
		libXinerama-* libXmu-* libXp-* libXpm-* libXrandr-* \
		libXrender-* libXres-* libXt-* libXv-* libXxf86-* libxkbfile-* \
		panoramixext-* printext-* randrext-* renderext-* resourceext-* \
		xextensions-* xf86ext-* xlibs-* xorg-libraries-* xpm-* xproto-*

USE_X_PREFIX=		no
PREFIX?=		${X11BASE}
MTREE_FILE=		/etc/mtree/BSD.x11-4.dist
INSTALLS_SHLIB=		yes
SCRIPTS_ENV=		DebuggableLibraries=${DebuggableLibraries}
MAN3=			FontCacheChangeCacheSettings.3 \
			FontCacheGetCacheSettings.3 \
			FontCacheGetCacheStatistics.3 \
			FontCacheQueryExtension.3 \
			FontCacheQueryVersion.3 \
			XDGA.3 \
			XDGAChangePixmapMode.3 \
			XDGACloseFramebuffer.3 \
			XDGACopyArea.3 \
			XDGACopyTransparentArea.3 \
			XDGACreateColormap.3 \
			XDGAFillRectangle.3 \
			XDGAGetViewportStatus.3 \
			XDGAInstallColormap.3 \
			XDGAKeyEventToXKeyEvent.3 \
			XDGAOpenFramebuffer.3 \
			XDGAQueryExtension.3 \
			XDGAQueryModes.3 \
			XDGAQueryVersion.3 \
			XDGASelectInput.3 \
			XDGASetClientVersion.3 \
			XDGASetMode.3 \
			XDGASetViewport.3 \
			XDGASync.3 \
			XF86DGA.3 \
			XFree86-DGA.3 \
			XRes.3 \
			XResQueryClientPixmapBytes.3 \
			XResQueryClientResources.3 \
			XResQueryClients.3 \
			XResQueryExtension.3 \
			XResQueryVersion.3 \
			XScreenSaverAllocInfo.3 \
			XScreenSaverGetRegistered.3 \
			XScreenSaverQueryExtension.3 \
			XScreenSaverQueryInfo.3 \
			XScreenSaverQueryVersion.3 \
			XScreenSaverRegister.3 \
			XScreenSaverSelectInput.3 \
			XScreenSaverSetAttributes.3 \
			XScreenSaverUnregister.3 \
			XScreenSaverUnsetAttributes.3 \
			Xaw.3 \
			Xcursor.3 \
			Xfontcache.3 \
			Xrandr.3 \
			Xss.3

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

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp2.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

post-patch:
	${CP} ${FILESDIR}/nls::Compose::microsoft-cp1251 ${WRKSRC}/nls/Compose/microsoft-cp1251

post-install:
	${INSTALL_DATA} ${WRKSRC}/programs/proxymngr/PM.h \
		${PREFIX}/include/X11/PM
	${INSTALL_DATA} ${WRKSRC}/programs/proxymngr/PMproto.h \
		${PREFIX}/include/X11/PM
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/lib/Xcursor/xcursor.pc \
		${PREFIX}/libdata/pkgconfig

.include <bsd.port.post.mk>
