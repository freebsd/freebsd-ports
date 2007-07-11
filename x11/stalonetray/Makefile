# New ports collection makefile for:	stalonetray
# Date created:		Apr 6 2006
# Whom:			Stepan Zastupov [RedChrom] <redchrom@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	stalonetray
PORTVERSION=	0.6.5
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	STAnd-aLONE system tray

USE_BZIP2=	yes
USE_XPM=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man \
		--disable-native-kde \
		--disable-debug

MAN1=		stalonetray.1
PLIST_FILES=	bin/stalonetray

.include <bsd.port.mk>
