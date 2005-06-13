# New ports collection makefile for:   XScreenSaver.App
# Date created:        26 September 2004
# Whom:                hemi@puresimplicity.net
#
# $FreeBSD$
#

PORTNAME=	XScreenSaver.App
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.asleep.net/download/

MAINTAINER=	hemi@puresimplicity.net
COMMENT=	WindowMaker dockapp to control XScreenSaver

LIB_DEPENDS=	dockapp.2:${PORTSDIR}/x11-wm/libdockapp

PLIST_FILES=	bin/XScreenSaver.App
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${X11BASE}/lib" \
		CPPFLAGS="-I${X11BASE}/include"

MAKE_ARGS=	"LDFLAGS+=-L${X11BASE}/lib"

.include <bsd.port.mk>
