# New ports collection makefile for:	libxklavier
# Date created:				31 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/libxklavier/Makefile,v 1.32 2007/02/24 21:00:46 mezz Exp $
#

PORTNAME=	libxklavier
PORTVERSION=	3.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gswitchit

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An utility library to make XKB stuff easier

USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gnomehack libxml2 glib20
USE_LDCONFIG=	yes
USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_ARGS=	--disable-doxygen \
		--with-xkb-base=${X11BASE}/lib/X11/xkb \
		--with-xmodmap-base=${LOCALBASE}/share/gnome/xmodmap \
		--disable-gtk-doc \
		--with-html-dir=${GNOME_HTML_DIR}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.mk>
