# New ports collection makefile for:	XFree86-clients
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	clients
PORTVERSION=	4.2.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE} \
		ftp://psych.psy.uq.oz.au/pub/X11R5/:wrap \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/:wrap \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/:wrap
MASTER_SITE_SUBDIR=	${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X${PORTVERSION:S/.//g}src-1.tgz \
		X${PORTVERSION:S/.//g}src-2.tgz Wraphelp.c:wrap
EXTRACT_ONLY=	X${PORTVERSION:S/.//g}src-1.tgz
IGNOREFILES=	Wraphelp.c

MAINTAINER=	anholt@freebsd.org

XFREE86_VERSION=	4
USE_IMAKE=		YES
DIST_SUBDIR=		xc
WRKSRC=			${WRKDIR}/xc
PATCHDIR=		${.CURDIR}/../XFree86-4-libraries/files
SCRIPTS_ENV=		InstallXdmConfig=${InstallXdmConfig} \
			InstallXinitConfig=${InstallXinitConfig} \
			InstallAppDefFiles=${InstallAppDefFiles} \
			HasXdmAuth=${HasXdmAuth} \
			HasSecureRPC=${HasSecureRPC} \
			HasPam=${HasPam}
MAKE_ENV=		PKGNAMEPREFIX=${PKGNAMEPREFIX} \
			PORTNAME=${PORTNAME} \
			PORTVERSION=${PORTVERSION}
ALL_TARGET=		FreeBSDPortsBuild
INSTALL_TARGET=		FreeBSDPortsInstall FreeBSDPortsInstall.man

# ---
# XFree86 User Config:
# Name          Default		Meaning
# ----------------------------------------------------------------------------
# HasXdmAuth	YES		support XDM-AUTHORIZATION-1.
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
HasXdmAuth?=		YES
HasSecureRPC?=		DEFAULT
HasPam?=		DEFAULT

post-extract:
	( cd ${WRKDIR} && \
	 ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	   ${DISTDIR}/${DIST_SUBDIR}/X${PORTVERSION:S/.//g}src-2.tgz \
	    | ${TAR} -xf - xc/fonts/util )

post-patch:
	cd ${WRKSRC}/nls; \
	for i in Compose XI18N_OBJS XLC_LOCALE; do \
		${LN} -s zh_TW.big5 $$i/zh_TW.Big5; \
	done


do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure
	@cd ${WRKSRC}; ${MAKE} FreeBSDPortsConfigure

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"
.include <bsd.port.post.mk>
