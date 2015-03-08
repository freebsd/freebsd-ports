# Created by: gurkan@phys.ethz.ch
# $FreeBSD$

PORTNAME=	terminal.app
PORTVERSION=	0.9.8
PORTREVISION=	3
CATEGORIES=	x11 gnustep
MASTER_SITES=	SAVANNAH/gap
DISTNAME=	Terminal-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal Emulator for GNUstep

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Terminal.app/Terminal

.include <bsd.port.mk>
