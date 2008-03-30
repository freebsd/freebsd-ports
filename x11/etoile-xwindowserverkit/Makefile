# New ports collection makefile for:    etoile-xwindowserverkit
# Date created:         18 Nov 2006
# Whom:                 dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	xwindowserverkit
PORTVERSION=	0.1.${SNAPSHOT}
PORTREVISION=	1
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
PKGNAMEPREFIX=	etoile-
DISTNAME=	Etoile-${SNAPSHOT}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Etoile Project XWindowServerKit frameowrk

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
USE_GNUSTEP_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

SNAPSHOT=	20061221
WRKSRC=	${WRKDIR}/Etoile/
USE_GNUSTEP_MAKE_DIRS+=	Frameworks/XWindowServerKit
ADDITIONAL_OBJCFLAGS+=	-I${LOCALBASE}/include
ADDITIONAL_LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR="${GNUSTEP_SYSTEM_ROOT}"

.include <bsd.port.mk>
