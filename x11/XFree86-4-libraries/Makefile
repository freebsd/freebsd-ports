# New ports collection makefile for:	XFree86-libraries
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	libraries
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.1.0
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X410src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4
LIB_DEPENDS=	freetype.7:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	mkhtmlindex:${PORTSDIR}/devel/imake-4

XFREE86_VERSION=	4
PREFIX?=		${X11BASE}
MANCOMPRESSED=		yes
XFREE86_HTML_MAN=	yes
MTREE_FILE=		/etc/mtree/BSD.x11-4.dist
INSTALLS_SHLIB=		yes
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
SCRIPTS_ENV=		HasXdmAuth=${HasXdmAuth} \
			HasSecureRPC=${HasSecureRPC} \
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
# HasXdmAuth	YES		support XDM-AUTHORIZATION-1.
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
HasXdmAuth?=		DEFAULT
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

.if ${HasXdmAuth} == DEFAULT || ${HasXdmAuth} == YES
.if defined(USA_RESIDENT) && ${USA_RESIDENT} == YES
pre-everything::
	@${ECHO_MSG} "Assuming that you have fetched a USA-Legal Wraphelp.c."
.else
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X410src-1.tgz
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif	# USA_RESIDENT
.endif	# HasXdmAuth != NO

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include <bsd.port.post.mk>
