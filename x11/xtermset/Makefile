# New ports collection makefile for:		xtermset
# Date created:			21 August 1999
# Whom:                 Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	xtermset
PORTVERSION=	0.5.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	clts

MAINTAINER=	dr@astorit.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		xtermset.1
MAN5=		terms.5

USE_X_PREFIX=	yes
MANCOMPRESSED=	no

post-install:
	strip ${PREFIX}/bin/xtermset

.include <bsd.port.mk>
