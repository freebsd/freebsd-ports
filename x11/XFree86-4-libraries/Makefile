# New ports collection makefile for:	XFree86-libraries
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	libraries
PORTVERSION=	4.2.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE:S/$/:x/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	${PORTVERSION}/:x \
			anholt/:local
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-1.tgz:x Wraphelp.gz:local
EXTRACT_ONLY=	X${PORTVERSION:S/.//g}src-1.tgz

PATCH_SITES=		${MASTER_SITE_XFREE:S/source//g:S/$/:x/} \
			${MASTER_SITE_LOCAL:S/$/:patch420/}
PATCH_SITE_SUBDIR=	${PORTVERSION}/fixes/:x \
			anholt/patches-4.2.0/:patch420
PATCHFILES=		patch-XlcDL.c.gz:patch420 \
			4.2.0-libGLU-bad-extern.patch:x
PATCH_DIST_STRIP=	-p1

MAINTAINER=	anholt@freebsd.org

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4
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
			DebuggableLibraries=${DebuggableLibraries}
MAKE_ENV=		PKGNAMEPREFIX=${PKGNAMEPREFIX} \
			PORTNAME=${PORTNAME} \
			PORTVERSION=${PORTVERSION}
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET=	FreeBSDPortsInstall FreeBSDPortsInstall.man installXlib
MAN1=		libxrx.1
MAN3=		Xaw.3 Xft.3

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

.include <bsd.port.pre.mk>

# BuildXF86DRI is false for FreeBSD < 4.1
.if ${OSVERSION} < 410000
PLIST_SUB+=	OSMESA:="@comment "
.else
PLIST_SUB+=	OSMESA:=""
.endif

post-extract:
	${GUNZIP_CMD} -c ${DISTDIR}/${DIST_SUBDIR}/Wraphelp.gz > \
		${WRKSRC}/lib/Xdmcp/Wraphelp.c

post-patch:
	cd ${WRKSRC}/nls; \
	for i in Compose XI18N_OBJS XLC_LOCALE; do \
		${LN} -s zh_TW.big5 $$i/zh_TW.Big5; \
	done

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@cd ${WRKSRC}; ${MAKE} FreeBSDPortsConfigure

post-install:
	@${MKHTMLINDEX} ${X11BASE}/lib/X11/doc/html

.include <bsd.port.post.mk>
