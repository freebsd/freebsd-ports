# New ports collection makefile for:	XFree86 aout libs
# Date created:		28 Feburary 2000
# Whom:			Jeremy Lea <reg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XFree86-aoutlibs
PORTVERSION=	3.3.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/3.3.3/binaries/FreeBSD-2.2.x/
DISTNAME=	Xbin
EXTRACT_SUFX=	.tgz

MAINTAINER=	reg@FreeBSD.org

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/lib
NO_BUILD=	yes
PORTOBJFORMAT=	aout

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

pre-extract:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SH} ${PKGINSTALL} foo PRE-INSTALL || ${FALSE}
.endif

pre-configure:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
	@${MKDIR} ${PREFIX}/lib/aout
	cd ${WRKSRC}; \
	for l in $$(ls lib*); do \
		${SETENV} OBJFORMAT=${PORTOBJFORMAT} \
		${INSTALL_PROGRAM} $$l ${PREFIX}/lib/aout; \
	done
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/aout

.include <bsd.port.post.mk>
