# New ports collection makefile for:	dxpc
# Date created:		2 May 1998
# Whom:			Bruce A. Mah <bmah@ca.sandia.gov>
#
# $FreeBSD$
#

PORTNAME=	dxpc
PORTVERSION=	3.9.2
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compressing X protocol proxy designed to support X11 over slow links

LIB_DEPENDS=	lzo2.2:${PORTSDIR}/archivers/lzo2

LICENSE=	BSD

USE_XORG=	x11
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo-lib=${LOCALBASE}

MAN1=		dxpc.1
PLIST_FILES=	bin/dxpc

post-patch:
	@${REINPLACE_CMD} -e \
		'/bindir/s|(INSTALL)|(INSTALL_PROGRAM)|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
