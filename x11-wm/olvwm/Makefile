# New ports collection makefile for:	olvwm
# Version required:	4.1
# Date created:		21 October 1994
# Whom:			smace
#
# $Id: Makefile,v 1.13 1998/08/24 01:28:42 steve Exp $
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

MAINTAINER=	brianfeldman@hotmail.com

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview-lib

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

.include <bsd.port.mk>
