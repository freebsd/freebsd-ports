# New ports collection makefile for:    kde_api_reference_31
# Date created:                         2004/01/02
# Whom:                                 Heiner <h.eichmann@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kde31-apireference
PORTVERSION=	3.1
CATEGORIES=	x11 kde
MASTER_SITES=	http://developer.kde.org/documentation/library/3.1-api/
DISTNAME=	3.1-api

MAINTAINER=	h.eichmann@gmx.de
COMMENT=	API reference for KDE 3.1

IGNOREFILES=	${ALLFILES}
USE_BZIP2=	yes

PLIST=	${WRKDIR}/plist

do-build:
	@cd ${WRKSRC} ; ${FIND} * -type f | ${SED} -e "s#^#share/doc/kdeapi31/#" > ${WRKDIR}/plist
	@cd ${WRKSRC} ; ${FIND} * -type d | sort -r | ${SED} -e "s#^#@dirrm share/doc/kdeapi31/#" >> ${WRKDIR}/plist
	@${ECHO} "@dirrm share/doc/kdeapi31" >> ${WRKDIR}/plist

do-install:
	@${MKDIR} ${PREFIX}/share/doc/kdeapi31
	@${CP} -r ${WRKSRC}/* ${PREFIX}/share/doc/kdeapi31

.include <bsd.port.mk>
