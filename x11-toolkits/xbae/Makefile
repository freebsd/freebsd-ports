# New ports collection makefile for:	Xbae
# Date created:		11 December 96
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.de>
# With some
# modifications from:	Andreas Klemm <andreas@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	Xbae
PORTVERSION=	4.60.4
CATEGORIES=	x11-toolkits math
MASTER_SITES=	SF
DISTNAME=	xbae-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Motif-based widget which displays a grid of cells as a spreadsheet

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_MOTIF=	yes
CONFIGURE_ARGS=--enable-production --enable-static

MAN3=		XbaeCaption.3 XbaeInput.3 XbaeMatrix.3

.include <bsd.port.mk>
