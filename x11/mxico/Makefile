# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

# NB: Do not delete or wrap post-install section, since we have to provide
#     READMEj and README

PORTNAME=	mxico
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://people.freebsd.org/~maho/mxico/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Rotating Object on the screen (Zalgaller polyhedra)

USES=		imake
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		mxico.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} polyhedron/READMEj ${DOCSDIR})
	@(cd ${WRKSRC}; ${INSTALL_DATA} polyhedron/README ${DOCSDIR})
.endif

.include <bsd.port.mk>
