# New ports collection makefile for:    mxico
# Date created:         25 October 2003
# Whom:                 NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$
#
# NB: Do not delete or wrap post-install section, since we have to provide
#     READMEj and README

PORTNAME=	mxico
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://people.freebsd.org/~maho/mxico/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Rotating Object on the screen (Zalgaller polyhedra)

USE_IMAKE=	yes
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN6=		mxico.6

pre-build:
	@cd ${WRKSRC} && ${MV} Makefile Makefile~  && ${SED} \
	 -e 's: BINDIR .*:BINDIR=${PREFIX}/bin:' \
	 -e 's: MANDIR .*:MANDIR=${PREFIX}/man/man6:' \
	 -e 's: MANSUFFIX .*:MANSUFFIX=6:' <Makefile~ >Makefile

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/man6
	@${MKDIR} ${DOCSDIR}

post-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)
	@(cd ${WRKSRC}; ${INSTALL_DATA} polyhedron/READMEj ${DOCSDIR})
	@(cd ${WRKSRC}; ${INSTALL_DATA} polyhedron/README ${DOCSDIR})
.include <bsd.port.mk>
