# New ports collection makefile for:   dgs
# Date created:        22 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	dgs
PORTVERSION= 	0.5.9
CATEGORIES=	x11
#MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITES=	ftp://alpha.gnu.org/gnu/gnustep/
MASTER_SITE_SUBDIR=	dgs

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS= 	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.3:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		glib12.3:${PORTSDIR}/devel/glib12
BUILD_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55

GLIB_CONFIG=	${LOCALBASE}/bin/glib12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIBS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GLIB_CONFIG=${GLIB_CONFIG}
MAKE_ENV=	INSTALL=${INSTALL}

MAN1=		dgs.1 dpsnx.agent.1
MANM=		dpsexec makepsres xepsf

.include <bsd.port.mk>
