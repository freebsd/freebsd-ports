# New ports collection makefile for:   keynav
# Date created:        29 June 2007
# Whom:                Wesley Shields <wxs@atarininja.org>
#
# $FreeBSD$
#

PORTNAME=	keynav
PORTVERSION=	20070629
CATEGORIES=	x11
MASTER_SITES=	http://www.semicomplete.com/files/keynav/ \
		http://www.atarininja.org/~wxs/distfiles/

MAINTAINER=	wxs@atarininja.org
COMMENT=	Quickly select a portion of the screen using minimal keystrokes

USE_GNOME=	pkgconfig
USE_XLIB=	yes
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/keynav

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/keynav ${PREFIX}/bin

.include <bsd.port.mk>
