# New ports collection makefile for:	XFree86-clients
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	clients
PORTVERSION=	4.4.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
MASTER_SITE_SUBDIR= ${PORTVERSION}
PKGNAMEPREFIX=	XFree86-
DISTFILES=	XFree86-4.4.0-src-1.tgz \
		XFree86-4.4.0-src-2.tgz \
		XFree86-4.4.0-src-3.tgz \
		XFree86-4.4.0-src-4.tgz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	XFree86-4 client programs and related files

CONFLICTS=	xorg-clients-*

RUN_DEPENDS=	xterm-static:${PORTSDIR}/x11/xterm
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		expat.5:${PORTSDIR}/textproc/expat2 \
		Xcursor.1:${PORTSDIR}/x11/XFree86-4-libraries \
		png.5:${PORTSDIR}/graphics/png \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

SCRIPTS_ENV=		InstallXdmConfig=${InstallXdmConfig} \
			InstallXinitConfig=${InstallXinitConfig} \
			InstallAppDefFiles=${InstallAppDefFiles}

MAKE_ENV=		PKGNAMEPREFIX=${PKGNAMEPREFIX} \
			PORTNAME=${PORTNAME} \
			PORTVERSION=${PORTVERSION}
XBUILD_DIRS=		lib/xtrans lib/lbxutil programs fonts/util
XINSTALL_DIRS=		programs fonts/util
XINSTALL_MAN_DIRS=	programs

.for pf in patch-bdftruncate.pl patch-ucs2any.pl \
	   patch-programs::fonttosfnt::read.c \
	   patch-programs::Imakefile \
	   patch-programs::xdm::Imakefile \
	   patch-programs::xdm::session.c \
	   patch-programs::xdm::socket.c
EXTRA_PATCHES+=		${FILESDIR}/${pf}
.endfor

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

.if !defined(WITH_SETUID_LUIT)
pre-everything::
	@${ECHO_MSG} "If you want to use xterm with locales in a secure manner, luit must be installed"
	@${ECHO_MSG} "setuid.  If you want to do this, hit Ctrl-C now and use \"make WITH_SETUID_LUIT=yes\""
.endif

post-install:
	@${LN} -sf ${X11BASE}/bin/resize-static ${X11BASE}/bin/resize
	@${LN} -sf ${X11BASE}/bin/xterm-static ${X11BASE}/bin/xterm
	@${LN} -sf ${X11BASE}/bin/uxterm-static ${X11BASE}/bin/uxterm
	@${LN} -sf ${X11BASE}/lib/X11/app-defaults/UXTerm-static \
		   ${X11BASE}/lib/X11/app-defaults/UXTerm
	@${LN} -sf ${X11BASE}/lib/X11/app-defaults/XTerm-static \
		   ${X11BASE}/lib/X11/app-defaults/XTerm
	@${LN} -sf ${X11BASE}/lib/X11/app-defaults/XTerm-color-static \
		   ${X11BASE}/lib/X11/app-defaults/XTerm-color
.if defined(WITH_SETUID_LUIT)
	${CHOWN} root:wheel ${PREFIX}/bin/luit
	${CHMOD} 04711 ${PREFIX}/bin/luit
.endif
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include "${.CURDIR}/../../x11/XFree86-4-libraries/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif

.include "${FILESDIR}/manpages"

.include <bsd.port.post.mk>
