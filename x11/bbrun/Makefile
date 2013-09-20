# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	bbrun
PORTVERSION=	1.6
PORTREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A Run box for Blackbox

WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun

USE_XORG=	xpm
USE_GNOME=	gtk20
USES=		gmake pkgconfig
USE_CSTD=	gnu89

PORTDOCS=	README
PLIST_FILES=	bin/bbrun

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
