# New ports collection makefile for:    etoile-azswitch
# Date created:         07 May 2008
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	azswitch
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	x11-wm gnustep
MASTER_SITES=	http://download.gna.org/etoile/
PKGNAMEPREFIX=	etoile-
DISTNAME=	etoile-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project window switching

PORTSCOUT=	limit:^0\.2

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_SYSTEM_LIBS+=	XWindowServerKit:${XWINDOWSERVERKIT_PORT}
USE_GNUSTEP_LOCAL_LIBS+=	EtoileUI:${ETOILE_UI_PORT}

WRKSRC=	${WRKDIR}/Etoile-${PORTVERSION}
USE_GNUSTEP_MAKE_DIRS+=	Services/Private/AZSwitch

XWINDOWSERVERKIT_PORT?=		x11/etoile-xwindowserverkit
ETOILE_UI_PORT?=	deskutils/etoile-ui

.include <bsd.port.mk>
