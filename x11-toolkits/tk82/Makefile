# New ports collection makefile for:	tk8.0
# Version required:	8.1a1
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.7 1997/12/01 16:50:58 pst Exp $
#

DISTNAME=	tk8.1a1
PKGNAME=	tk-8.1.a1
CATEGORIES=	x11 tk81
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/

MAINTAINER=	jseger@FreeBSD.ORG

LIB_DEPENDS=	tcl81\\.1\\.0:${PORTSDIR}/lang/tcl81

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>
