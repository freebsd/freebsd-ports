# New ports collection makefile for:	XFree86-clients
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	clients
PORTVERSION=	4.1.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR=	4.1.0
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X410src-1.tgz X410src-2.tgz
EXTRACT_ONLY=	X410src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

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
HasXdmAuth?=		DEFAULT
HasSecureRPC?=		DEFAULT
HasPam?=		DEFAULT

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
.endif	# HasXdmAuth

post-extract:
	( cd ${WRKDIR} && \
	 ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
	   ${DISTDIR}/${DIST_SUBDIR}/X410src-2.tgz \
	    | ${TAR} -xf - xc/fonts/util )

do-configure:
	cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"
.include <bsd.port.post.mk>
