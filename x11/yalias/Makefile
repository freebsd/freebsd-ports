PORTNAME=	yalias
PORTVERSION=	0.7
PORTREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	http://offog.org/files/ \
		http://ftp.i-scream.org/pub/offog.org/files/

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Enhanced execution box with regex pattern matching
WWW=		https://offog.org/code/

DEPRECATED=	No longer developed upstream
EXPIRATION_DATE=	2026-07-01

USES=		gnome pkgconfig
USE_GNOME=	gtk20

ALL_TARGET=	yalias
MAKE_ARGS=	prefix=${PREFIX} YALIASDIR=${DATADIR}

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
