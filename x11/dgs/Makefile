# New ports collection makefile for:   dgs
# Version required:    0.5.0
# Date created:        22 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.10 1999/01/12 16:50:23 vanilla Exp $
#

DISTNAME=	dgs-0.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	nacai@iname.com

LIB_DEPENDS= 	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff34

WRKSRC=		${WRKDIR}/${DISTNAME}/dgs

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

MAN1=		gs.1 pdf2ps.1 ps2ascii.1 ps2epsi.1 ps2pdf.1

.include <bsd.port.mk>
