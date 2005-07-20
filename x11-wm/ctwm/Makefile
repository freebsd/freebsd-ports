# New ports collection makefile for:	ctwm
# Date created:		13 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ctwm
PORTVERSION=	3.7
CATEGORIES=	x11-wm
MASTER_SITES=	http://ctwm.free.lp.se/dist/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	An extension to twm, with support for multiple virtual screens, etc

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		ctwm.1

pre-configure:
	${CP} ${WRKSRC}/Imakefile.local-template ${WRKSRC}/Imakefile.local
	${CAT} ${FILESDIR}/Imakefile.local-additional >> ${WRKSRC}/Imakefile.local

.include <bsd.port.mk>
