# New ports collection makefile for:	olvwm
# Version required:	4.1
# Date created:		21 October 1994
# Whom:			smace
#
# $FreeBSD$
#

DISTNAME=	olvwm4
PKGNAME=	olvwm-4.2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	window_managers
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	olvwm4.Patch01.Z \
		olvwm4.Patch02.Z
PATCH_DIST_STRIP=	-p1

MAINTAINER=	green@FreeBSD.org

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview \
		Xpm.4:${PORTSDIR}/graphics/xpm

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MAN1=		olvwm.1 olvwmrc.1

.include <bsd.port.mk>
