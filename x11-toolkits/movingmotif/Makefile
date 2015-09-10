# Created by: ijliao
# $FreeBSD$

PORTNAME=	movingmotif
PORTVERSION=	2.3.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}_2_1/movingmotiv-2.3.1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display scientific data as dynamic plot

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		motif libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS_sparc64=	-O0

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
