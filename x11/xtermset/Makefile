# New ports collection makefile for:		xtermset
# Date created:			21 August 1999
# Whom:                 Dominik Rothert <dr@domix.de>
#
# $FreeBSD$
#

PORTNAME=	xtermset
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/clts/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamically change some settings of an xterm

GNU_CONFIGURE=	yes
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}"
USE_GMAKE=	yes
MAN1=		xtermset.1
MAN5=		terms.5

MANCOMPRESSED=	no

post-install:
	${STRIP_CMD} ${PREFIX}/bin/xtermset

.include <bsd.port.mk>
