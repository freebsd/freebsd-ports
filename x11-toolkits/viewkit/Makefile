#
# ports collection makefile for: Viewkit from Hungry Programming.
# Date created:   Aug 2000
# Whom:           peterho@ned.dem.csiro.au
#
# $FreeBSD$
#
#
#

PORTNAME=       viewkit
PORTVERSION=    0.00
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/viewkit/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner
DISTNAME=       libvk-Apr19-2243

MAINTAINER=	peterho@ned.dem.csiro.au

BUILD_DEPENDS=   ${AUTOCONFIG}:${PORTSDIR}/devel/${AUTOCONFIG}

AUTOCONFIG=      autoconf

MOTIFPACKAGE?=   open-motif
USE_X_PREFIX=   yes
USE_MOTIF = yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-${MOTIFPACKAGE}

pre-configure:
	@cd ${WRKSRC}; ${CHMOD} +w configure; ${AUTOCONFIG}

.include <bsd.port.mk>
