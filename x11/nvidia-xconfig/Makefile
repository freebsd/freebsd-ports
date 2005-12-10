# New ports collection makefile for:	nvidia-xconfig
# Date created:				10 Dec 2005
# Whom:					Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nvidia-xconfig
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://download.nvidia.com/XFree86/nvidia-xconfig/ \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=     bland/:local

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Tool to manipulate X configuration files for the NVidia driver

USE_GMAKE=	yes

MAKE_ENV=	ROOT=${PREFIX} \
		CC=${CC}

MAN1=		nvidia-xconfig.1
PLIST_FILES=	bin/nvidia-xconfig

.include <bsd.port.mk>
