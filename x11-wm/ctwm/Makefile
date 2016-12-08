# Created by: torstenb
# $FreeBSD$

PORTNAME=	ctwm
PORTVERSION=	3.8.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.ctwm.org/dist/ \
		http://distfiles.over-yonder.net/ctwm/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Extension to twm, with support for multiple virtual screens, etc

LICENSE=	MIT

USES=		imake jpeg tar:xz
USE_XORG=	xpm xmu

pre-configure:
	${CP} ${WRKSRC}/Imakefile.local-template ${WRKSRC}/Imakefile.local
	${CAT} ${FILESDIR}/Imakefile.local-additional >> ${WRKSRC}/Imakefile.local

.include <bsd.port.mk>
