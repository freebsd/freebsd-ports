# New ports collection makefile for:    renaissance
# Date created:         007 Sep 2006
# Whom:                 gurkan@linuks.mine.nu
#
# $FreeBSD$
#

PORTNAME=	renaissance
PORTVERSION=	0.8.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.gnustep.it/Renaissance/ \
		http://io.debian.net/~tar/ports/distfiles/
DISTNAME=	Renaissance-${PORTVERSION}

MAINTAINER=	gurkan@linuks.mine.nu
COMMENT=	GNUstep GUI Development Framework

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
# broken:
#USE_LDCONFIG=	yes
INSTALL_SHLIBS=	yes
MAKEFILE=	GNUmakefile

.include <bsd.port.mk>
