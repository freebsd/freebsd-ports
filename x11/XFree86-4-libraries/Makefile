# New ports collection makefile for:	XFree86-libraries
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	libraries
PORTVERSION=	4.2.1
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	4.2.0/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X420src-1.tgz:x \
		Wraphelp.gz:local
EXTRACT_ONLY=	X420src-1.tgz

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	anholt/patches-4.2.0/
PATCHFILES=		4.2.0-4.2.1-1-freebsd.patch.gz

MAINTAINER=	anholt@freebsd.org

BUILD_DEPENDS=	${X11BASE}/lib/X11/config/version.def:${PORTSDIR}/devel/imake-4
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	mkhtmlindex:${PORTSDIR}/devel/imake-4

XFREE86_VERSION=	4
PREFIX?=		${X11BASE}
MANCOMPRESSED=		yes
XFREE86_HTML_MAN=	yes
MTREE_FILE=		/etc/mtree/BSD.x11-4.dist
INSTALLS_SHLIB=		yes
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
SCRIPTS_ENV=		HasSecureRPC=${HasSecureRPC} \
			BuildPexExt=${BuildPexExt} \
			BuildXinerama=${BuildXinerama} \
			BuildXIE=${BuildXIE} \
			BuildAoutLibraries=${BuildAoutLibraries} \
			ForceNormalLib=${ForceNormalLib} \
			DebuggableLibraries=${DebuggableLibraries} \
			CC="${CC}" \
			CXX="${CXX}" \
			CFLAGS="${CFLAGS}"
MAKE_ENV=		PKGNAMEPREFIX=${PKGNAMEPREFIX} \
			PORTNAME=${PORTNAME} \
			PORTVERSION=${PORTVERSION}
MAN1=			libxrx.1
MAN3=			Xaw.3 Xft.3
XBUILD_DIRS=		lib nls programs/Xserver/include \
			programs/Xserver/hw/xfree86/parser \
			programs/xrx
XINCLUDE_DIRS=		programs/proxymngr
XINSTALL_DIRS=		include lib nls programs/Xserver/include \
			programs/xrx/plugin \
			programs/Xserver/hw/xfree86/parser
XINSTALL_MAN_DIRS=	${XINSTALL_DIRS}

# XFree86 User Config:
# ---
# Name          Default		Meaning
# ----------------------------------------------------------------------------
# HasSecureRPC	YES		build with SecureRPC (require FreeBSD-3 or later)
# BuildPexExt	YES		build PEX extension
# BuildXinerama	YES		build Xinerama extension
# BuildXIE	YES		build XIE extension
# BuildAoutLibraries  NO	build with old Aout libs.
# ForceNormalLib      YES	build with static libs.
# DebuggableLibraries NO	build with debug libs (require FreeBSD-4 or later)
# ----------------------------------------------------------------------------
# DEFAULT means ports will use values which set by ${PORTSDIR}/devel/imake-4
#
HasSecureRPC?=		DEFAULT
BuildPexExt?=		DEFAULT
BuildXinerama?=		DEFAULT
BuildXIE?=		DEFAULT
BuildAoutLibraries?=	DEFAULT
ForceNormalLib?=	DEFAULT
DebuggableLibraries?=	DEFAULT
# End of XFree86 User Config

.ifdef USE_XLIB
.error You have `USE_XLIB' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

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
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

post-patch:
	${CP} ${MASTERDIR}/files/nls::Compose::microsoft-cp1251 ${WRKSRC}/nls/Compose/microsoft-cp1251
	cd ${WRKSRC}/nls; \
	for i in Compose XI18N_OBJS XLC_LOCALE; do \
		${LN} -s zh_TW.big5 $$i/zh_TW.Big5; \
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/programs/proxymngr/PM.h \
		${PREFIX}/include/X11/PM
	${INSTALL_DATA} ${WRKSRC}/programs/proxymngr/PMproto.h \
		${PREFIX}/include/X11/PM
	@${MKHTMLINDEX} ${X11BASE}/lib/X11/doc/html

.include "Makefile.inc"
.include <bsd.port.post.mk>
