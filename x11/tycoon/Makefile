# New ports collection makefile for:	tycoon
# Date created:		19 September 1997
# Whom:			steve@farrell.org
#
# $FreeBSD$
#

PORTNAME=	tycoon
PORTVERSION=	1.07o	
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	xforms:${PORTSDIR}/x11-toolkits/xforms

USE_IMAKE=	yes
USE_XPM=	yes

post-build:
	${RM} -f ${WRKSRC}/xbackdrop/backdrops/index~ ;\
	${PERL} -pi -e 's,/usr/lib,${PREFIX}/lib,' \
		${WRKSRC}/xbackdrop/backdrops/index

.include <bsd.port.mk>
