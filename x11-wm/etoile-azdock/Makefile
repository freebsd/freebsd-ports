# New ports collection makefile for:    etoile-azdock
# Date created:         19 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	azdock
PORTVERSION=	0.2
CATEGORIES=	x11-wm gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project AZDock is a wm-dock

USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	BookmarkKit:${BOOKMARKKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	IconKit:${ICONKIT_PORT}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/AZDock
ADDITIONAL_OBJCFLAGS+=	-I${LOCALBASE}/include
ADDITIONAL_LDFLAGS+=	-L${LOCALBASE}/lib

XWINDOWSERVERKIT_PORT?=		x11/etoile-xwindowserverkit
BOOKMARKKIT_PORT?=	www/etoile-bookmarkkit
ICONKIT_PORT?=	x11-themes/etoile-iconkit

.include <bsd.port.mk>
