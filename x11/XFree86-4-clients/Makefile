# New ports collection makefile for:	XFree86-clients
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	clients
PORTVERSION=	4.2.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.2.0
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X420src-1.tgz X420src-2.tgz
EXTRACT_ONLY=	X420src-1.tgz

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	anholt/patches-4.2.0/
PATCHFILES=		4.2.0-4.2.1-1-freebsd.patch.gz

MAINTAINER=	anholt@freebsd.org

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		GLU.1:${PORTSDIR}/x11/XFree86-4-libraries

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../XFree86-4-libraries/files
SCRIPTS_ENV=		InstallXdmConfig=${InstallXdmConfig} \
			InstallXinitConfig=${InstallXinitConfig} \
			InstallAppDefFiles=${InstallAppDefFiles} \
			HasSecureRPC=${HasSecureRPC} \
			HasPam=${HasPam} \
			CC="${CC}" \
			CXX="${CXX}" \
			CFLAGS="${CFLAGS}"
MAKE_ENV=		PKGNAMEPREFIX=${PKGNAMEPREFIX} \
			PORTNAME=${PORTNAME} \
			PORTVERSION=${PORTVERSION}
XBUILD_DIRS=		lib/xtrans lib/lbxutil programs fonts/util
XINSTALL_DIRS=		programs fonts/util
XINSTALL_MAN_DIRS=	programs

# ---
# XFree86 User Config:
# Name          Default		Meaning
# ----------------------------------------------------------------------------
# HasSecureRPC	YES		build with SecureRPC (require FreeBSD-3 or later)
# HasPam	YES		support PAM (require FreeBSD-3.1 or later)
# InstallXdmConfig      YES     install config files for xdm.
# InstallXinitConfig    YES     install config files for xinit.
# InstallAppDefFiles    YES	install resource files.
# ----------------------------------------------------------------------------
# DEFAULT means ports will use values which set by ${PORTSDIR}/devel/imake-4
#
InstallXdmConfig?=	DEFAULT
InstallXinitConfig?=	DEFAULT
InstallAppDefFiles?=	DEFAULT
HasSecureRPC?=		DEFAULT
HasPam?=		DEFAULT

post-extract:
	( cd ${WRKDIR} && \
	 ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	   ${DISTDIR}/${DIST_SUBDIR}/X420src-2.tgz \
	    | ${TAR} -xf - xc/fonts/util )

post-patch:
	cd ${WRKSRC}/nls; \
	for i in Compose XI18N_OBJS XLC_LOCALE; do \
		${LN} -s zh_TW.big5 $$i/zh_TW.Big5; \
	done

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"
.include <bsd.port.post.mk>
