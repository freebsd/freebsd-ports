# New ports collection makefile for:    etoile-idle
# Date created:         07 May 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	idle
PORTVERSION=	0.4.1
CATEGORIES=	x11 gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project Idle event generator

BUILD_DEPENDS=	${LOCALBASE}/include/X11/extensions/scrnsaver.h:${PORTSDIR}/x11/scrnsaverproto

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}
USE_XORG=	xscrnsaver

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/Idle
PLIST_FILES=	System/Tools/Idle

XWINDOWSERVERKIT_PORT?=		x11/etoile-xwindowserverkit

.include <bsd.port.mk>
