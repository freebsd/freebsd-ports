# New ports collection makefile for:	PekSysTray
# Date created:				08 Jul 2004
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	peksystray
PORTVERSION=	0.2.1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	stefan.tell@crashmail.de
COMMENT=	A system tray dockapp similar to the GNOME notification area applet

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/peksystray

.include <bsd.port.mk>
