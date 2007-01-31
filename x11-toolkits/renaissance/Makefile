# New ports collection makefile for:    renaissance
# Date created:         007 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	renaissance
PORTVERSION=	0.8.0
CATEGORIES=	x11-toolkits gnustep
MASTER_SITES=	http://www.gnustep.it/Renaissance/ \
		${MASTER_SITE_GNUSTEP_CH}
DISTNAME=	Renaissance-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	GNUstep GUI Development Framework

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.mk>
