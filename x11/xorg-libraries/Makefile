# New ports collection makefile for:    xorg-libraries
# Date created:		29 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libraries
PORTVERSION=	6.7.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/:xorg \
		${MASTER_SITE_XORG:S/$/:xorg/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	R6.7/tars/:xorg \
			anholt/:local
PKGNAMEPREFIX=	xorg-
DISTFILES=	X11R6.7.0-src1.tar.gz:xorg \
		X11R6.7.0-src3.tar.gz:xorg \
		Wraphelp2.gz:local
EXTRACT_ONLY=	X11R6.7.0-src1.tar.gz \
		X11R6.7.0-src3.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 libraries and headers from X.Org

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

CONFLICTS=	XFree86-libraries-* \
		libX11-* libGL-* libGLU-* libICE-* libSM-* libXau-* libXaw-* \
		libXcursor-* libXdmcp-* libXext-* libXfont-* libXi-* \
		libXinerama-* libXmu-* libXp-* libXpm-* libXrandr-* \
		libXrender-* libXres-* libXt-* libXv-* libXxf86-* libxkbfile-* \
		panoramixext-* printext-* randrext-* renderext-* resourceext-* \
		xextensions-* xf86ext-* xlibs-* xproto-*

EXTRA_PATCHES=	${CF_PATCHES}

XBUILD_DIRS=	lib nls programs/Xserver/include \
		programs/Xserver/hw/xfree86/parser
XINSTALL_DIRS=	include lib nls programs/Xserver/include \
		programs/Xserver/hw/xfree86/parser

INSTALLS_SHLIB=	yes

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp2.gz > ${WRKSRC}/lib/Xdmcp/Wraphelp.c

post-patch:
	${CP} ${FILESDIR}/nls-Compose-microsoft-cp1251 ${WRKSRC}/nls/Compose/microsoft-cp1251

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/lib/Xcursor/xcursor.pc \
		${PREFIX}/libdata/pkgconfig

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>
 
.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE= is part of X.Org
.endif

# BuildXF86DRI is false for FreeBSD < 4.1
.if ${OSVERSION} < 410000
PLIST_SUB+=	OSMESA:="@comment "
.else
PLIST_SUB+=	OSMESA:=""
.endif

# sparc64 doesn't have a working libc_r yet, and -current doesn't need libXThrStub.
.if ${ARCH} == "sparc64" || ${OSVERSION} >= 500043
PLIST_SUB+=	XTHRSTUB:="@comment "
.else
PLIST_SUB+=	XTHRSTUB:=""
.endif

.include <bsd.port.post.mk>
