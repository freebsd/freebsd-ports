# New ports collection makefile for:	nvidia-xconfig
# Date created:				10 Dec 2005
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nvidia-xconfig
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_NVIDIA:S,$,XFree86/${PORTNAME}/,} \
		${MASTER_SITE_LOCAL:S,$,bland/,}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Tool to manipulate X configuration files for the NVidia driver

USE_GMAKE=	yes

MAKE_ENV=	ROOT=${PREFIX}

MAN1=		nvidia-xconfig.1
PLIST_FILES=	bin/nvidia-xconfig

.include <bsd.port.mk>
