# New ports collection makefile for:    terminal.app
# Date created:         28 Aug 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	terminal.app
PORTVERSION=	0.9.4
DISTVERSIONSUFFIX=	+cvs20051125.orig
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	Terminal Emulator for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:C/\.app//}-${DISTVERSION}${DISTVERSIONSUFFIX:C/\.orig//}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not compile on 4.x
.endif

.include <bsd.port.post.mk>
