# New ports collection makefile for:	tk8.0
# Date created:		19 August 1997
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	8.0.5
CATEGORIES=	x11-toolkits tk80
MASTER_SITES=	${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=	tcl8_0
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@Freebsd.ORG

LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80

NO_LATEST_LINK=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/tk8.0.5/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} TK_LIB_FILE=${TK_LIB_FILE}
PKGINSTALL=	${PKGDIR}/pkg-install.wish
PKGDEINSTALL=	${PKGDIR}/pkg-deinstall.wish

SHLIB_MAJOR=	1
SHLIB_MINOR=	4
MAKEFILE=	makefile
TK_LIB=		libtk80.so

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
TK_LIB_FILE=	${TK_LIB}.${SHLIB_MAJOR}
.else
TK_LIB_FILE=	${TK_LIB}.${SHLIB_MAJOR}.${SHLIB_MINOR}
.endif

post-patch:
	@${CP} ${WRKSRC}/mkLinks ${WRKSRC}/mkLinks.orig
	@${SED} -e 's/\.[3n]/&.gz/g' ${WRKSRC}/mkLinks.orig > ${WRKSRC}/mkLinks

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}
	@${CP} ${FILESDIR}/makefile     ${WRKSRC}

pre-build:
	@cd ${WRKSRC} && ${MAKE} -f Makefile.lib PREFIX=${PREFIX} \
	    SHLIB_MAJOR=${SHLIB_MAJOR} SHLIB_MINOR=${SHLIB_MINOR}

post-install:
	${LN} -sf ${TK_LIB_FILE} ${PREFIX}/lib/${TK_LIB}
.if exists(${PKGINSTALL})
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL}
.endif

test:
	cd ${WRKSRC}; make test

.include <bsd.port.post.mk>
