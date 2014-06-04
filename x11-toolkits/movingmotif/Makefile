# Created by: ijliao
# $FreeBSD$

PORTNAME=	movingmotif
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_2_1/movingmotiv-2.3.1

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Display scientific data as dynamic plot

LICENSE=	GPLv2

USES=		motif libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
CFLAGS+=	-O0
.endif

.include <bsd.port.post.mk>
