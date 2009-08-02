# ex:ts=8
# Ports collection makefile for:	movingmotif
# Date created:			Sep 13, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	movingmotif
PORTVERSION=	2.3.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Display scientific data as dynamic plot

USE_MOTIF=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
CONFIGURE_ENV+=	CFLAGS="-O0"
.endif

.include <bsd.port.post.mk>
