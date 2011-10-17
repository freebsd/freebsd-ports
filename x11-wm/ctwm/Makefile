# New ports collection makefile for:	ctwm
# Date created:		13 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ctwm
PORTVERSION=	3.8a
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://ctwm.free.lp.se/dist/ \
		http://distfiles.over-yonder.net/ctwm/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	An extension to twm, with support for multiple virtual screens, etc

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USE_IMAKE=	yes
USE_XORG=	xpm xmu
MAN1=		ctwm.1

.include <bsd.port.pre.mk>

pre-configure:
	${CP} ${WRKSRC}/Imakefile.local-template ${WRKSRC}/Imakefile.local
	${CAT} ${FILESDIR}/Imakefile.local-additional >> ${WRKSRC}/Imakefile.local

.include <bsd.port.post.mk>
