# New ports collection makefile for:	dxpc
# Date created:		2 May 1998
# Whom:			Bruce A. Mah <bmah@ca.sandia.gov>
#
# $FreeBSD$
#

PORTNAME=	dxpc
PORTVERSION=	3.8.0
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/3.8.0/

MAINTAINER=	bmah@freebsd.org

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

MAN1=		dxpc.1

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS+=	--with-lzo-lib=${LOCALBASE}

post-install:
	strip ${PREFIX}/bin/dxpc

.include <bsd.port.mk>
