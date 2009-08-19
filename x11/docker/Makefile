# New ports collection makefile for:	docker
# Date created:				March 15, 2003
# Whom:					Samy Al Bahra <samy@kerneled.org>
#
# $FreeBSD$
#

PORTNAME=	docker
PORTVERSION=	1.5
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://www.kerneled.org/files/FreeBSD-ports/ \
		http://icculus.org/openbox/2/docker/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp with support for GNOME2 and KDE3 tray icons

PLIST_FILES=	bin/docker
USE_GMAKE=	yes
USE_XORG=	x11
USE_GNOME=	glib20

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
