# New ports collection Makefile for:	sxpc
# Version required:	1.4
# Date created:		22nd March 1995
# Whom:			jkh@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	sxpc-1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=		${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	|sh

MAN1=		sxpc.1

.include <bsd.port.mk>
