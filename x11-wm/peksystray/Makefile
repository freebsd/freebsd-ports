# New ports collection makefile for:	PekSysTray
# Date created:				08 Jul 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	peksystray
PORTVERSION=	0.2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A system tray dockapp similar to the GNOME notification area applet

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

PLIST_FILES=	bin/peksystray

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
