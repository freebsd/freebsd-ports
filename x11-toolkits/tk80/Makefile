# New ports collection makefile for:	tk8.0
# Version required:	tk8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.9 1998/07/03 23:07:13 steve Exp $
#

DISTNAME=	tk8.0p2
PKGNAME=	tk-8.0.2
CATEGORIES=	x11 tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=	jkh@Freebsd.ORG

LIB_DEPENDS=	tcl80\\.1\\.2:${PORTSDIR}/lang/tcl80

WRKSRC=		${WRKDIR}/tk8.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}

SHLIB_MAJOR=    1
SHLIB_MINOR=    2
MAKEFILE=       makefile

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	    SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGDIR}/INSTALL.wish)
	${SH} ${PKGDIR}/INSTALL.wish
.endif

test:
	cd ${WRKSRC}; make test

.include <bsd.port.mk>

PKG_ARGS+=	-i ${PKGDIR}/INSTALL.wish
