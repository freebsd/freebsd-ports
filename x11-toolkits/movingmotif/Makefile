# ex:ts=8
# Ports collection makefile for:	movingmotif
# Date created:			Sep 13, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	movingmotif
PORTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display scientific data as dynamic plot

USE_MOTIF=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
.if ${ARCH} == "sparc64"
BROKEN=		Does not compile with GCC 4.2
.endif
.endif

.include <bsd.port.post.mk>
