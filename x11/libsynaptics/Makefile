# New ports collection makefile for:	libsynaptics
# Date created:				Sun Mar 19 21:20:25 CET 2006
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsynaptics
PORTVERSION=	0.14.4d
CATEGORIES=	x11
MASTER_SITES=	http://qsynaptics.sourceforge.net/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Library to access the Xorg/XFree86 Synaptics TouchPad Driver

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
