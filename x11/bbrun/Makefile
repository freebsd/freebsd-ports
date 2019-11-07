# Created by: Adam Weinberger <adam@vectors.cx>
# $FreeBSD$

PORTNAME=	bbrun
PORTVERSION=	1.6
PORTREVISION=	13
CATEGORIES=	x11
MASTER_SITES=	http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Run box for Blackbox

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${DISTNAME}/bbrun

USES=		gmake gnome pkgconfig xorg
USE_XORG=	x11 xext xpm
USE_GNOME=	gtk20
USE_CSTD=	gnu89

PORTDOCS=	README
PLIST_FILES=	bin/bbrun

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbrun ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
