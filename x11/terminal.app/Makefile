# New ports collection makefile for:    terminal.app
# Date created:         28 Aug 2006
# Whom:                 gurkan@phys.ethz.ch
#
# $FreeBSD$
#

PORTNAME=	terminal.app
PORTVERSION=	0.9.6
DISTVERSIONSUFFIX=	+cvs20051125.orig
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	gap
DISTNAME=	Terminal-${PORTVERSION}


MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Terminal Emulator for GNUstep

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

.include <bsd.port.mk>
