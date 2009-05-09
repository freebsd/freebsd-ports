# New ports collection makefile for:	i3
# Date created:		2009-04-19
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i3
DISTVERSION=	3.a-bf2
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3.zekjur.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	An improved dynamic tiling window manager

LIB_DEPENDS=	xcb.2:${PORTSDIR}/x11/libxcb \
		xcb-event.1:${PORTSDIR}/x11/xcb-util

USE_XORG=	x11
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/i3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
