# New ports collection makefile for:    kde3-apireference
# Date created:                         2004/01/02
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kde3-apireference
PORTVERSION=	3.4
CATEGORIES=	x11 kde
MASTER_SITES=	http://developer.kde.org/documentation/library/${PORTVERSION}-api/
DISTNAME=	${PORTVERSION}-api
DIST_SUBDIR=	KDE

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	API reference for KDE 3

IGNOREFILES=	${ALLFILES}
USE_BZIP2=	yes

PLIST=	${WRKDIR}/plist

do-build:
	@cd ${WRKSRC} ; ${FIND} * -type d -delete
	@cd ${WRKSRC} ; ${FIND} * -type f | ${SED} -e "s#^#share/doc/kdeapi3/#" > ${WRKDIR}/plist
	@cd ${WRKSRC} ; ${FIND} * -type l | ${SED} -e "s#^#share/doc/kdeapi3/#" >> ${WRKDIR}/plist
	@cd ${WRKSRC} ; ${FIND} * -type d | ${SORT} -r | ${SED} -e "s#^#@dirrm share/doc/kdeapi3/#" >> ${WRKDIR}/plist
	@${ECHO} "@dirrm share/doc/kdeapi3" >> ${WRKDIR}/plist

do-install:
	@${MKDIR} ${PREFIX}/share/doc/kdeapi3
	@${CP} -r ${WRKSRC}/* ${PREFIX}/share/doc/kdeapi3

.include <bsd.port.mk>
