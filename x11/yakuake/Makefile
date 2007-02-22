# New ports collection makefile for:   yakuake
# Date created:                        1st November, 2005
# Whom:                                decept
#
# $FreeBSD$
#

PORTNAME=	yakuake
PORTVERSION=	2.7.5
CATEGORIES=	x11 kde
MASTER_SITES=	http://www.kde-look.org/CONTENT/content-files/
DISTNAME=	29153-${PORTNAME}-${PORTVERSION}

MAINTAINER=	decept0@gmail.com
COMMENT=	Quake-style terminal emulator based on KDE's Konsole

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	LDFLAGS="${PTHREAD_LIBS}"
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
