# New ports collection makefile for:   dgs
# Date created:        22 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	dgs
PORTVERSION=	0.5.9
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	dgs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A display ghostscript system

USE_GHOSTSCRIPT_RUN=	yes

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_GNOME=	glib12
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

MAN1=		dgs.1 dpsnx.agent.1
MANN=		dpsexec.man makepsres.man xepsf.man

.ifdef USE_DGS
.error You have `USE_DGS' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

pre-patch:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|manm|mann|g'

.include <bsd.port.mk>
