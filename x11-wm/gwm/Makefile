# New ports collection makefile for:	gwm
# Date created:		14 November 1996
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	gwm
PORTVERSION=	1.8d
CATEGORIES=	x11-wm
MASTER_SITES=	http://koala.ilog.fr/ftp/pub/gwm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Window Manager

USE_IMAKE=	yes
USE_XPM=	yes
MAN1=		gwm.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

.include <bsd.port.post.mk>
