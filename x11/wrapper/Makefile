# New ports collection makefile for:	wrapper
# Date created:				2000-09-18
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	trevor@FreeBSD.org

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-fetch:

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/Xwrapper ${FILESDIR}/wrapper.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xwrapper ${PREFIX}/bin
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
