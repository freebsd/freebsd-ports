# New ports collection makefile for:	olvwm
# Version required:	4.1
# Date created:		21 October 1994
# Whom:			smace
#
# $id: Makefile,v 1.0 1994/10/21 00:00:00 smace Exp $
#

DISTNAME=	olvwm4
PKGNAME=	olvwm-4.1
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
DISTFILES=	olvwm4.tar.Z

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	olvwm4.Patch01.Z
PATCH_DIST_STRIP=	-p1

LIB_DEPENDS=	xview\\.3\\.:${PORTSDIR}/x11/xview-lib

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes

.include <bsd.port.mk>
