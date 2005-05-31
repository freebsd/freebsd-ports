# New ports collection makefile for:	dxpc
# Date created:		2 May 1998
# Whom:			Bruce A. Mah <bmah@ca.sandia.gov>
#
# $FreeBSD$
#

PORTNAME=	dxpc
PORTVERSION=	3.8.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compressing X protocol proxy designed to support X11 over slow links

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

MAN1=		dxpc.1
PLIST_FILES=	bin/dxpc

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ARGS+=	--with-lzo-lib=${LOCALBASE}

post-install:
	${STRIP_CMD} ${PREFIX}/bin/dxpc

.include <bsd.port.mk>
