# New ports collection makefile for:	wrapper
# Date created:				2000-09-18
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	XFree86:${PORTSDIR}/x11-servers/XFree86-4-Server

NO_WRKSUBDIR=	yes
PLIST=		${WRKDIR}/pkg-plist
USE_X_PREFIX=	yes

do-fetch:

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/Xwrapper-4 ${FILESDIR}/wrapper.c

pre-install:
	${ECHO_CMD} bin/Xwrapper-4 > ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xwrapper-4 ${PREFIX}/bin
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
