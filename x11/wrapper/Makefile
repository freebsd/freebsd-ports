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
COMMENT=	Wrapper for XFree86-4 server

RUN_DEPENDS=	XFree86:${PORTSDIR}/x11-servers/XFree86-4-Server

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/Xwrapper-4
USE_X_PREFIX=	yes

do-fetch:

do-build:
	${CC} ${CFLAGS} -DXSERVER_PATH=\"${X11BASE}/bin/XFree86\" -o ${WRKSRC}/Xwrapper-4 ${FILESDIR}/wrapper.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xwrapper-4 ${PREFIX}/bin
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.pre.mk>
.if ${X_WINDOW_SYSTEM:L} != xfree86-4
IGNORE= is part of XFree86-4
.endif
.include <bsd.port.post.mk>
