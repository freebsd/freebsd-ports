# New ports collection makefile for:	xforms
# Date created:		28 March 1997
# Whom:			gena
#
# $FreeBSD$
#

PORTNAME=	xforms
PORTVERSION=	0.88
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	ftp://ncmir.ucsd.edu/pub/xforms/${MASTER_SITE_SUBDIR}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gena@NetVision.net.il

USE_X_PREFIX=	yes
USE_XPM=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		fdesign.1 fd2ps.1
MAN5=		xforms.5 forms.5

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
MASTER_SITE_SUBDIR=	freeBSD-alpha
DISTNAME=	bxform-${PORTVERSION:S/.//}
.else
MASTER_SITE_SUBDIR=	freeBSD
DISTNAME=	bxform-${PORTVERSION:S/.//}-elf
.endif

post-install:
	@${LN} -sf ${PREFIX}/lib/libforms.so.0.88 ${PREFIX}/lib/libforms.so.0
	@${LN} -sf ${PREFIX}/lib/libforms.so.0.88 ${PREFIX}/lib/libxforms.so.0
	@${LN} -sf ${PREFIX}/lib/libforms.a ${PREFIX}/lib/libxforms.a

.include <bsd.port.post.mk>
