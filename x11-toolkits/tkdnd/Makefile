# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkdnd
PORTVERSION=	2.8
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/${PORTNAME}/TkDND/TkDND%20${PORTVERSION}/
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Native drag and drop capabilities for Tk

USES+=		tk:tea xorg
USE_XORG=	x11 xext

TCL_PKG=	${PORTNAME}${PORTVERSION}
USE_LDCONFIG=	${PREFIX}/lib/${TCL_PKG}
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/tkDND.n ${STAGEDIR}/${PREFIX}/man/mann/${MANN}

.include <bsd.port.mk>
