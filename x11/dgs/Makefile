# New ports collection makefile for:   dgs
# Date created:        22 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	dgs
PORTVERSION=	0.5.9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	dgs

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS= 	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GLIB=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

MAN1=		dgs.1 dpsnx.agent.1
MANN=		dpsexec.man makepsres.man xepsf.man

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|manm|mann|g'



.include <bsd.port.mk>
