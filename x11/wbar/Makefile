# New ports collection makefile for:	wbar
# Date created:		2007-01-16
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wbar
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.tecapli.com.ar/rodolfo/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
EXTRACT_SUFX=	.tbz2

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A quick launch bar for fluxbox, WindowMaker, Xfce, etc

BUILD_DEPENDS=	imlib2-config:${PORTSDIR}/graphics/imlib2

SUB_FILES=	pkg-message

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11

post-patch:
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR} && ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
