# New ports collection makefile for:	tk8.0
# Version required:	8.1a2
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.12 1998/07/12 21:07:21 jdp Exp $
#

DISTNAME=	tk8.1a2
PKGNAME=	tk-8.1.a2
CATEGORIES=	x11 tk81
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_1/

MAINTAINER=	jseger@FreeBSD.ORG

LIB_DEPENDS=	tcl81\\.1\\.0:${PORTSDIR}/lang/tcl81

NO_LATEST_LINK=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PORTSDIR}/x11/tk80/pkg/INSTALL.wish)
	${SH} ${PORTSDIR}/x11/tk80/pkg/INSTALL.wish
.endif

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>

PKG_ARGS+=      -i ${PORTSDIR}/x11/tk80/pkg/INSTALL.wish
