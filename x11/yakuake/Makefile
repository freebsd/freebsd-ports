# New ports collection makefile for:   yakuake
# Date created:                        1st November, 2005
# Whom:                                decept
#
# $FreeBSD$
#

PORTNAME=	yakuake
PORTVERSION=	2.8.1
PORTREVISION=	8
CATEGORIES=	x11 kde
MASTER_SITES=	BERLIOS

MAINTAINER=	shanjobe@gmail.com
COMMENT=	Quake-style terminal emulator based on KDE's Konsole

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_GETTEXT=	yes

LDFLAGS+=	${PTHREAD_LIBS}

.include <bsd.port.mk>
