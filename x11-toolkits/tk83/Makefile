# New ports collection makefile for:	tk8.0
# Version required:	tk8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.5 1997/10/08 10:48:52 asami Exp $
#

DISTNAME=	tk8.0p1
PKGNAME=	tk-8.0.1
CATEGORIES=	x11 tk80
MASTER_SITES=	ftp://ftp.sunlabs.com/pub/tcl/

MAINTAINER=	jkh@Freebsd.ORG

LIB_DEPENDS=	tcl80\\.1\\.1:${PORTSDIR}/lang/tcl80

WRKSRC=		${WRKDIR}/tk8.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>
