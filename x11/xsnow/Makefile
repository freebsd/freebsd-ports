# New ports collection makefile for:    xsnow
# Date created:         12 November 1994
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	xsnow
PORTVERSION=	1.42
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	http://www.euronet.nl/~rja/Xsnow/

MAINTAINER=	jmz@FreeBSD.org
COMMENT=	Create a snowy and Santa-y desktop

USE_IMAKE=	yes
USE_XPM=	yes
MAN6=		xsnow.6
PLIST_FILES=	bin/xsnow

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
