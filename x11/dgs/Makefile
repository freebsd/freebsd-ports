# New ports collection makefile for:   dgs
# Version required:    0.5.0
# Date created:        22 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.7 1998/10/05 05:20:08 steve Exp $
#

DISTNAME=	dgs-0.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	Nakai@technologist.com

LIB_DEPENDS= 	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.2:${PORTSDIR}/graphics/png \
		tiff.1:${PORTSDIR}/graphics/tiff34

WRKSRC=		${WRKDIR}/${DISTNAME}/dgs

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

MAN1=		gs.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1

.include <bsd.port.mk>
