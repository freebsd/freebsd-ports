# New ports collection makefile for:	dxpc
# Date created:		2 May 1998
# Whom:			Bruce A. Mah <bmah@ca.sandia.gov>
#
# $FreeBSD$
#

PORTNAME=	dxpc
PORTVERSION=	3.9.0
CATEGORIES=	x11
MASTER_SITES=	http://www.vigor.nu/dxpc/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compressing X protocol proxy designed to support X11 over slow links

LIB_DEPENDS=	lzo2.2:${PORTSDIR}/archivers/lzo2

USE_X_PREFIX=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo-lib=${LOCALBASE}
MAKE_ARGS=	CPPFLAGS="-I. -I${X11BASE}/include"

MAN1=		dxpc.1
PLIST_FILES=	bin/dxpc

do-install:
	${INSTALL_DATA} ${WRKSRC}/dxpc ${PREFIX}/bin/dxpc
	${INSTALL_MAN} ${WRKSRC}/dxpc.man ${MANPREFIX}/man/man1/dxpc.1

.include <bsd.port.mk>
