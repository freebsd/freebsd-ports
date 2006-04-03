# New ports collection makefile for:	libxklavier
# Date created:				31 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxklavier
PORTVERSION=	2.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.2
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An utility library to make XKB stuff easier

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gnomehack libxml2
INSTALLS_SHLIB=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_ARGS=	--disable-doxygen \
		--with-xkb-base=${X11BASE}/lib/X11/xkb \
		--with-xmodmap-base=${X11BASE}/share/gnome/xmodmap
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
