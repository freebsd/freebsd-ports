# New ports collection makefile for:   xdotool
# Date created:        29 June 2007
# Whom:                Wesley Shields <wxs@atarininja.org>
#
# $FreeBSD$
#

PORTNAME=	xdotool
PORTVERSION=	20070625
CATEGORIES=	x11
MASTER_SITES=	http://www.semicomplete.com/files/xdotool/ \
		http://www.atarininja.org/~wxs/distfiles/

MAINTAINER=	wxs@atarininja.org
COMMENT=	Programatically simulate keyboard input or mouse activity

USE_GNOME=	pkgconfig
USE_XLIB=	yes
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/xdotool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdotool ${PREFIX}/bin

.include <bsd.port.mk>
