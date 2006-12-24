# New ports collection makefile for:    etoile-azalea
# Date created:         19 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	azalea
PORTVERSION=	0.1.${SNAPSHOT}
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~%%SUBDIR%%/distfiles/
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Azalea is a GNUstep window mamager

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/Azalea
ADDITIONAL_INCLUDE_DIRS+=	-I${X11BASE}/include
ADDITIONAL_LIB_DIRS+=	-L${X11BASE}/lib

XWINDOWSERVERKIT_PORT?=		x11/etoile-xwindowserverkit

.include <bsd.port.mk>
