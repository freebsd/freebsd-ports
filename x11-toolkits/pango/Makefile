# New ports collection makefile for:   pango
# Date Created:			18 July 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	0.13
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/v1.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/gtk/v1.3/ \
		http://www.ameth.org/gimp/gtk/v1.3/

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	glib-1.3.2:${PORTSDIR}/devel/glib13

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-qt=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
