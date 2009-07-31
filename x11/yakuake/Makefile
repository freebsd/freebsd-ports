# New ports collection makefile for:   yakuake
# Date created:                        1st November, 2005
# Whom:                                decept
#
# $FreeBSD$
#

PORTNAME=	yakuake
PORTVERSION=	2.8.1
PORTREVISION=	3
CATEGORIES=	x11 kde
MASTER_SITES=	BERLIOS

MAINTAINER=	decept0@gmail.com
COMMENT=	Quake-style terminal emulator based on KDE's Konsole

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ENV+=	LDFLAGS="${PTHREAD_LIBS}"

.include <bsd.port.mk>
