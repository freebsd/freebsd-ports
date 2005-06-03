# New ports collection makefile for:   wmg
# Date created:        27 August 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

PORTNAME=	wmg
PORTVERSION=	0.15.0
PORTREVISION=	1
CATEGORIES=	x11-wm gnome
MASTER_SITES=	http://ductape.net/~reeve/downloads/
DISTNAME=	wmG-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small GTK-based GNOME-compliant window manager

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CFLAGS+=	-fpermissive

.include <bsd.port.mk>
