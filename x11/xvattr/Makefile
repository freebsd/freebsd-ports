# ex:ts=8
# Ports collection makefile for:	xvattr
# Date created:			Jan 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xvattr
PORTVERSION=	1.1
CATEGORIES=	x11
MASTER_SITES=	http://www.dtek.chalmers.se/groups/dvd/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	${PORTNAME}

post-patch:
	@${PERL} -pi -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
