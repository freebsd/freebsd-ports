# New ports collection Makefile for:	sxpc
# Date created:		22nd March 1995
# Whom:			jkh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sxpc
PORTVERSION=	1.4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.shar.Z

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	The Simple X Protocol Compressor

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=		${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SH}

MAN1=		sxpc.1

.include <bsd.port.mk>
