# New ports collection makefile for:	wrapper
# Date created:				2000-09-18
# Whom:					Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	wrapper
PORTVERSION= 	1.0
CATEGORIES=	x11
MASTER_SITES=	http://jpj.net/~trevor/freebsd/ports/
EXTRACT_SUFX=	.c.gz

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	XFree86:${PORTSDIR}/x11-servers/XFree86-4-Server

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-extract:
	${MKDIR} ${WRKDIR}
	${GUNZIP_CMD} -c ${_DISTDIR}${DISTFILES} > ${WRKSRC}/wrapper.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o Xwrapper wrapper.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xwrapper ${PREFIX}/bin
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
