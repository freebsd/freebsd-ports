# New ports collection makefile for:    xorg-libraries
# Date created:		29 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-libraries
PORTVERSION=	6.8.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
MASTER_SITE_SUBDIR=	X11R${PORTVERSION}/src
DISTFILES=	X11R${PORTVERSION}-src1.tar.gz \
		X11R${PORTVERSION}-src3.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X11 libraries and headers from X.Org

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

CONFLICTS=	Mesa-* XFree86-libraries-* \
		libX11-* libGL-* libGLU-* libICE-* libSM-* libXau-* libXaw-* \
		libXcursor-* libXdmcp-* libXext-* libXfont-* libXi-* \
		libXinerama-* libXmu-* libXp-* libXpm-* libXrandr-* \
		libXrender-* libXres-* libXt-* libXv-* libXxf86-* libxkbfile-* \
		panoramixext-* printext-* randrext-* renderext-* resourceext-* \
		xextensions-* xf86ext-* xlibs-* xpm-* xproto-*

EXTRA_PATCHES=	${CF_PATCHES}

XBUILD_DIRS=	lib nls programs/Xserver/include \
		programs/Xserver/hw/xfree86/parser
XINSTALL_DIRS=	include lib nls programs/Xserver/include \
		programs/Xserver/hw/xfree86/parser

INSTALLS_SHLIB=	yes

post-patch:
	${CP} ${FILESDIR}/nls-Compose-microsoft-cp1251 ${WRKSRC}/nls/Compose/microsoft-cp1251
	${MKDIR} ${WRKSRC}/lib/XThrStub
	${CP} ${FILESDIR}/XThrStub-Imakefile ${WRKSRC}/lib/XThrStub/Imakefile

post-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/lib/Xcursor/xcursor.pc \
		${PREFIX}/libdata/pkgconfig

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org. For switching to X.Org, read UPDATING entry 20040723
.endif

# BuildXF86DRI is false for FreeBSD < 4.1
.if ${OSVERSION} < 410000
PLIST_SUB+=	OSMESA:="@comment "
.else
PLIST_SUB+=	OSMESA:=""
.endif

.if ${OSVERSION} >= 500043
PLIST_SUB+=	XTHRSTUB:="@comment "
.else
PLIST_SUB+=	XTHRSTUB:=""
.endif

.include <bsd.port.post.mk>
