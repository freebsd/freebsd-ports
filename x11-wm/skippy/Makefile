# New ports collection makefile for:	skippy
# Date created:		2004-05-15
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	skippy
PORTVERSION=	0.4.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://thegraveyard.org/files/

MAINTAINER=	ahze@ahze.net
COMMENT=	A full-screen X11 task-switcher like Apple's Expose

LIB_DEPENDS=	Imlib2.2:${PORTSDIR}/graphics/imlib2 \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_XLIB=	yes
USE_BZIP2=	yes
USE_GNOME=	pkgconfig
USE_REINPLACE=	yes
PLIST_FILES=	bin/skippy

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${X11BASE}|; \
		s|/usr/local|${LOCALBASE}|; s|gcc|${CC}|' \
			${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/skippy ${PREFIX}/bin

.include <bsd.port.mk>
