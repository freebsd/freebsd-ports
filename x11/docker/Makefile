# New ports collection makefile for:	docker
# Date created:				March 15, 2003
# Whom:					Samy <samy@kerneled.com>
#
# $FreeBSD$
#

PORTNAME=	docker
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.kerneled.com/projects/docker/ \
		http://icculus.org/openbox/docker/

MAINTAINER=	samy@kerneled.com
COMMENT=	A dockapp with support for GNOME2 and KDE3 tray icons

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	glib20

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
