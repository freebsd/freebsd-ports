# New ports collection makefile for:	olvwm
# Date created:		21 October 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	olvwm
PORTVERSION=	4.2
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	window_managers
DISTNAME=	${PORTNAME}4
EXTRACT_SUFX=	.tar.Z

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	olvwm4.Patch01.Z \
		olvwm4.Patch02.Z
PATCH_DIST_STRIP=	-p1

MAINTAINER=	green@FreeBSD.org
COMMENT=	OpenLook Virtual Window manager

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		olvwm.1 olvwmrc.1
XFREE86_HTML_MAN=	no

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
