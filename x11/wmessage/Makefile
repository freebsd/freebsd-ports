# New ports collection makefile for:	wmessage
# Date created:				Mon Dec 17 20:18:07 EST 2001
# Whom:					Patrick Li <pat@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmessage
PORTVERSION=	0.11
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://members.ozemail.com.au/~crn/wmessage/

MAINTAINER=	pat@FreeBSD.org

BUILD_DEPENDS=	get-wraster-flags:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
USE_XPM=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmessage ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
