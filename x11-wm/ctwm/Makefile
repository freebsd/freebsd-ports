# New ports collection makefile for:	ctwm
# Date created:		13 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ctwm
PORTVERSION=	3.5.2b
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://slhp1.epfl.ch/pub/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ctwm-images${EXTRACT_SUFX}

MAINTAINER=	torstenb@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

MAKE_ENV=	LOCALBASE=${LOCALBASE}

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		ctwm.1

post-extract:
	@(cd ${WRKSRC} && ${LN} -s ../xpm xpm)

.include <bsd.port.mk>
