# New ports collection makefile for:	finder
# Date created:				4 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	finder
PORTVERSION= 	0.80.1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://lfh.hkcampus.net/~lfh-lck/programs/finder/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		panel_applet.4:${PORTSDIR}/x11/gnomecore \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_PREFIX=	yes
USE_GMAKE=	yes

ALL_TARGET=	default

.include <bsd.port.mk>
