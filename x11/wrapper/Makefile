# New ports collection makefile for:	wrapper
# Date created:				2000-09-18
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	x11
DISTNAME=	# intentionally left blank
EXTRACT_SUFX=	# intentionally left blank

MAINTAINER=	ports@FreeBSD.org

CONFLICTS=	XFree86-3.3.6*
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/Xwrapper
USE_XORG=	x11

.include <bsd.port.pre.mk>

XSERVER=	-DXSERVER_PATH=\"${X11BASE}/bin/Xorg\"
PKGNAMEPREFIX=	xorg-
COMMENT=	Wrapper for X.org X11 server

do-fetch:

do-build:
	${CC} ${CFLAGS} ${XSERVER} -o ${WRKSRC}/Xwrapper ${FILESDIR}/wrapper.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Xwrapper ${PREFIX}/bin
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
