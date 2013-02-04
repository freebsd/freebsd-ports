# New ports collection makefile for:	xcoloredit
# Date created:		6 Jun 1997
# Whom:			Satoshi TAOKA
#
# $FreeBSD$
#

PORTNAME=	xcoloredit
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/../R5contrib
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Find colour values by graphical colour mixing

USE_XORG=	ice sm x11 xaw xext xmu xpm xt
USE_IMAKE=	yes
MAKE_JOBS_SAFE=	yes

MANCOMPRESSED=	yes
MAN1=		xcoloredit.1
PLIST_FILES=	bin/xcoloredit

.include <bsd.port.mk>
