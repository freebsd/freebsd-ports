# New ports collection makefile for:	ctwm
# Version required:	3.4
# Date created:		13 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	ctwm-3.5.2b
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://slhp1.epfl.ch/pub/
DISTFILES+=	ctwm-3.5.2b.tar.gz ctwm-images.tar.gz

MAINTAINER=	torstenb@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
BUILD_DEPENDS=  gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=    gm4:${PORTSDIR}/devel/m4

MAKE_ENV+=	LOCALBASE=${LOCALBASE}

USE_IMAKE=	yes
MAN1=		ctwm.1

post-extract:
	@(cd ${WRKSRC} && ${LN} -s ../xpm xpm)

.include <bsd.port.mk>
