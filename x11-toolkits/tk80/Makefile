# New ports collection makefile for:	tk8.0
# Version required:	tk8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $Id: Makefile,v 1.14 1998/11/14 09:43:32 asami Exp $
#

DISTNAME=	tk8.0p2
PKGNAME=	tk-8.0.2
CATEGORIES=	x11-toolkits tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/tcl8_0/

MAINTAINER=	jkh@Freebsd.ORG

LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/tk8.0/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=  PORTSDIR=${PORTSDIR}
PKGINSTALL=	${PKGDIR}/INSTALL.wish

SHLIB_MAJOR=    1
SHLIB_MINOR=    2
MAKEFILE=       makefile
TK_LIB=		libtk80.so

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
TK_LIB_FILE=  ${TK_LIB}.${SHLIB_MAJOR}
.else
TK_LIB_FILE=  ${TK_LIB}.${SHLIB_MAJOR}.${SHLIB_MINOR}
.endif

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	    SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

post-install:
	${LN} -sf ${TK_LIB_FILE} ${PREFIX}/lib/${TK_LIB}
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC}; make test

.include <bsd.port.post.mk>
