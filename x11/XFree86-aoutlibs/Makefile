# New ports collection makefile for:	XFree86 aout libs
# Date created:		28 Feburary 2000
# Whom:			Jeremy Lea <reg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XFree86-aoutlibs
PORTVERSION=	3.3.6.9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XFree86 a.out compatibility libraries

ONLY_FOR_ARCHS=	i386

NO_BUILD=	yes
PORTOBJFORMAT=	aout

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

pre-configure:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install:
	@${MKDIR} ${PREFIX}/lib/aout
	cd ${WRKSRC}; \
	for l in $$(${LS} lib*); do \
		${SETENV} OBJFORMAT=${PORTOBJFORMAT} \
		${INSTALL_PROGRAM} $$l ${PREFIX}/lib/aout; \
	done
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib/aout

.include <bsd.port.post.mk>
