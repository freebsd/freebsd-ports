# New ports collection makefile for:	xforms
# Date created:		28 March 1997
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xforms
PORTVERSION= 	0.89
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/${MASTER_SITE_SUBDIR}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gena@NetVision.net.il

USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		fdesign.1 fd2ps.1
MAN5=		xforms.5

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
PORTVERSION=	0.88
DISTNAME=	bxform-${PORTVERSION:S/.//}
MASTER_SITE_SUBDIR=	freeBSD-alpha
PATCHDIR=	${MASTERDIR}/patches.alpha
.else
DISTNAME=	bxform-${PORTVERSION:S/.//}-elf
MASTER_SITE_SUBDIR=	freeBSD
PATCHDIR=       ${MASTERDIR}/patches.i386
MAN1+=		iconvert.1
.endif

.include <bsd.port.post.mk>
