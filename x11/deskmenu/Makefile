# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	deskmenu
PORTVERSION=	1.3.0
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://matt.peterson.org/FreeBSD/ports/ \
		http://gd.tuwien.ac.at/opsys/linux/gentoo/distfiles/

MAINTAINER=	matt@peterson.org
COMMENT=	X11 application launcher

PLIST_FILES=	bin/deskmenu
USES=		gmake
USE_GNOME=	gtk12
USE_CSTD=	gnu89

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/deskmenu

.include <bsd.port.mk>
