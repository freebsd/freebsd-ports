# New ports collection makefile for:		xtermset
# Date created:			21 August 1999
# Whom:                 Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	xtermset
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	clts

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamically change some settings of an xterm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		xtermset.1
MAN5=		terms.5

USE_X_PREFIX=	yes
MANCOMPRESSED=	no

post-install:
	${STRIP_CMD} ${PREFIX}/bin/xtermset

.include <bsd.port.mk>
