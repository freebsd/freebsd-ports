# New ports collection makefile for:    xorg-clients
# Date created:		30 May 2004
# Whom:			anholt@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xorg-clients
PORTVERSION=	6.7.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://freedesktop.org/~xorg/X11R6.7.0/src/
DISTFILES=	X11R6.7.0-src1.tar.gz \
		X11R6.7.0-src2.tar.gz \
		X11R6.7.0-src3.tar.gz

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X client programs and related files from X.Org

RUN_DEPENDS=	xterm-static:${PORTSDIR}/x11/xterm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

CONFLICTS=	XFree86-clients-*

EXTRA_PATCHES=	${CF_PATCHES}

XINCLUDE_DIRS=	lib/xtrans
XBUILD_DIRS=	programs fonts/util
XMAN_DIRS=	programs
USE_XLIB=	yes

XDMCONFDATA=	Xaccess Xresources Xservers xdm-config
XDMCONFSCRIPTS=	GiveConsole TakeConsole Xsession Xsetup_0 Xwilling

.if !defined(WITH_SETUID_LUIT)
pre-everything::
	@${ECHO_MSG} "If you want to use xterm with locales in a secure manner, luit must be installed"
	@${ECHO_MSG} "setuid.  If you want to do this, hit Ctrl-C now and use \"make WITH_SETUID_LUIT=yes\""
.endif

post-install:
	@${LN} -sf ${X11BASE}/bin/resize-static ${X11BASE}/bin/resize
	@${LN} -sf ${X11BASE}/bin/xterm-static ${X11BASE}/bin/xterm
	@${LN} -sf ${X11BASE}/bin/uxterm-static ${X11BASE}/bin/uxterm
	@${LN} -sf ${X11BASE}/lib/X11/app-defaults/UXTerm-static ${X11BASE}/lib/X11/app-defaults/UXTerm
	@${LN} -sf ${X11BASE}/lib/X11/app-defaults/XTerm-static ${X11BASE}/lib/X11/app-defaults/XTerm
	@${LN} -sf ${X11BASE}/lib/X11/app-defaults/XTerm-color-static ${X11BASE}/lib/X11/app-defaults/XTerm-color

.if defined(WITH_SETUID_LUIT)
	${CHOWN} root:wheel ${PREFIX}/bin/luit
	${CHMOD} 04711 ${PREFIX}/bin/luit
.endif
	${INSTALL_DATA} ${WRKSRC}/programs/xinit/xinitrc \
		${PREFIX}/lib/X11/xinit/xinitrc.default
.for i in ${XDMCONFDATA}
	${INSTALL_DATA} ${WRKSRC}/programs/xdm/config/${i} \
		${PREFIX}/lib/X11/xdm/${i}.default
.endfor
.for i in ${XDMCONFSCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/programs/xdm/config/${i} \
		${PREFIX}/lib/X11/xdm/${i}.default
.endfor
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include "${.CURDIR}/../../x11-servers/xorg-server/Makefile.inc"
.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xorg
IGNORE=	is part of X.Org. For switching to X.Org, read UPDATING entry 20040723
.endif

.include "${FILESDIR}/manpages"

.include <bsd.port.post.mk>
