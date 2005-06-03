# ex:ts=8
# Ports collection makefile for:	movingmotif
# Date created:			Sep 13, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	movingmotif
PORTVERSION=	2.2.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display scientific data as dynamic plot

USE_MOTIF=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
