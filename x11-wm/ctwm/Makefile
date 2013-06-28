# Created by: torstenb
# $FreeBSD$

PORTNAME=	ctwm
PORTVERSION=	3.8.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://ctwm.free.lp.se/dist/ \
		http://distfiles.over-yonder.net/ctwm/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Extension to twm, with support for multiple virtual screens, etc

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg

USES=		imake
USE_XORG=	xpm xmu
MAN1=		ctwm.1

pre-configure:
	${CP} ${WRKSRC}/Imakefile.local-template ${WRKSRC}/Imakefile.local
	${CAT} ${FILESDIR}/Imakefile.local-additional >> ${WRKSRC}/Imakefile.local

.include <bsd.port.mk>
