# New ports collection makefile for:    gskrab
# Date created:         17 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	gskrab
PORTVERSION=	0.0.1
CATEGORIES=	x11
MASTER_SITES=	http://organact.mine.nu/~wolfgang/gskrab/
DISTNAME=	GSKrab-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	GNUstep Keyboard Grabber

USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=
ALL_TARGET=

ADDITIONAL_OBJCFLAGS+=	-I${X11BASE}/include ${LOCALBASE}/include
ADDITIONAL_LDFLAGS+=	-L${X11BASE}/lib
MAKE_ENV+=	ADDITIONAL_OBJCFLAGS="${ADDITIONAL_OBJCFLAGS}"
MAKE_ENV+=	ADDITIONAL_LDFLAGS="${ADDITIONAL_LDFLAGS}"

.include <bsd.port.mk>
