# New ports collection makefile for:	xforms
# Date created:		28 March 1997
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xforms
PORTVERSION=	1.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/OpenSource/
FULLVERSION=	${PORTVERSION}RC5.2
DISTNAME=	${PORTNAME}-${FULLVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mikeh@FreeBSD.ORG

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_XPM=	yes
USE_IMAKE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

MAN1=		fdesign.1 fd2ps.1

.include <bsd.port.mk>
