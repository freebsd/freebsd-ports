# New ports collection makefile for:    xsnow
# Date created:         12 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	xsnow
PORTVERSION=	1.40
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jmz@FreeBSD.org

USE_IMAKE=	yes
MAN6=		xsnow.6

pre-build:
	@cd ${WRKSRC} && ${MV} Makefile Makefile~  && ${SED} \
	 -e 's: BINDIR .*:BINDIR=${PREFIX}/bin:' \
	 -e 's: MANDIR .*:MANDIR=${PREFIX}/man/man6:' \
	 -e 's: MANSUFFIX .*:MANSUFFIX=6:' <Makefile~ >Makefile

pre-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/man/man6
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
