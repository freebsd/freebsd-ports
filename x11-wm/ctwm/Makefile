# New ports collection makefile for:	ctwm
# Version required:	3.4
# Date created:		13 November 1994
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	ctwm-3.5
PKGNAME=	ctwm-3.5.2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://slhp1.epfl.ch/pub/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	ctwm-3.5-3.5.1.diffs.gz ctwm-3.5.1-3.5.2.diffs.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	torstenb@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
MAN1=		ctwm.1

.include <bsd.port.mk>
