# New ports collection makefile for:	XFree86 aout libs
# Version required:	3.3.6
# Date created:		28 Feburary 2000
# Whom:			Jeremy Lea <reg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	Xbin
PKGNAME=	XFree86-aoutlibs-3.3.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.3/binaries/FreeBSD-2.2.x/
EXTRACT_SUFX=	.tgz

MAINTAINER=	reg@FreeBSD.org

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/lib
NO_BUILD=	yes
PORTOBJFORMAT=	aout

USE_X_PREFIX=	yes

pre-configure:
	@${SETENV} ${SCRIPTS_ENV} ${SH} \
		${PKGDIR}/REQ ${PKGNAME} INSTALL

do-install:
	@${MKDIR} -p ${PREFIX}/lib/aout
	cd ${WRKSRC}; \
	for l in $$(ls lib*); do \
		${SETENV} OBJFORMAT=${PORTOBJFORMAT} \
		${INSTALL_PROGRAM} $$l ${PREFIX}/lib/aout; \
	done
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/aout

.include <bsd.port.mk>
