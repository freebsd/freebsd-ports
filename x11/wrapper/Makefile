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

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

do-extract:
	${MKDIR} ${WRKDIR}
	${GUNZIP_CMD} -c ${_DISTDIR}${DISTFILES} > ${WRKSRC}/wrapper.c

do-build:
	${CC} -o ${WRKDIR}/Xwrapper ${WRKDIR}/wrapper.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Xwrapper ${PREFIX}/bin/
	${LN} -sf ${PREFIX}/bin/Xwrapper ${PREFIX}/bin/X
	${CHMOD} -s ${PREFIX}/bin/XFree86
	${CHMOD} +s ${PREFIX}/bin/Xwrapper

.include <bsd.port.mk>
