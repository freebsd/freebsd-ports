# New ports collection makefile for:	ecore
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	ecore
PORTVERSION=	0.9.9.023
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	http://enlightenment.freedesktop.org/files/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	A core event abstraction library

LIB_DEPENDS=	evas.1:${PORTSDIR}/graphics/evas

.if !exists(/usr/include/getopt.h)
USE_GETOPT_LONG=	yes
.endif

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
USE_ICONV=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--enable-pthreads --with-iconv-link=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.include <bsd.port.mk>
