# New ports collection makefile for:	tk8.0
# Version required:	tk8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.3 1997/08/27 05:03:11 asami Exp $
#

DISTNAME=	tk8.0
PKGNAME=	tk-8.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/

MAINTAINER=	jkh@Freebsd.ORG

LIB_DEPENDS=	tcl80\\.1\\.:${PORTSDIR}/lang/tcl80

WRKSRC=		${WRKDIR}/${DISTNAME}/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>
