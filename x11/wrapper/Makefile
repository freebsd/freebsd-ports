# New ports collection makefile for:	wrapper
# Date created:				2000-09-18
# Whom:					Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11
DISTNAME=	# intentionally left blank
EXTRACT_SUFX=	# intentionally left blank

MAINTAINER=	trevor@FreeBSD.org

CONFLICTS=	XFree86-3.3.6*
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/Xwrapper
USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} == xorg
XSERVER=	-DXSERVER_PATH=\"/usr/X11R6/bin/Xorg\"
PKGNAMEPREFIX=	xorg-
COMMENT=	Wrapper for X.org X11 server
BROKEN=		Incomplete pkg-plist
.elif ${X_WINDOW_SYSTEM:L} == xfree86-4
XSERVER=	-DXSERVER_PATH=\"/usr/X11R6/bin/XFree86\"
RUN_DEPENDS=	XFree86:${PORTSDIR}/x11-servers/XFree86-4-Server
PKGNAMEPREFIX=	XFree86-4-
COMMENT=	Wrapper for XFree86-4 server
.endif

do-fetch:

do-build:
	${CC} ${CFLAGS} ${XSERVER} -o ${WRKSRC}/Xwrapper ${FILESDIR}/wrapper.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/Xwrapper ${PREFIX}/bin
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
