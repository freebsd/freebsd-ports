# New ports collection makefile for:   deskmenu
# Date created:                        17 February 2002
# Whom:                                Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	deskmenu
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://matt.peterson.org/FreeBSD/ports/ \
		http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=	matt@peterson.org
COMMENT=	X11 application launcher

PLIST_FILES=	bin/deskmenu
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes

post-install:
	${STRIP_CMD} ${X11BASE}/bin/deskmenu

.include <bsd.port.mk>
