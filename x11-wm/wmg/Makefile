# New ports collection makefile for:   wmg
# Date created:        27 August 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

PORTNAME=	wmg
PORTVERSION=	0.15.0
PORTREVISION=	6
CATEGORIES=	x11-wm gnome
MASTER_SITES=	http://ductape.net/~reeve/downloads/
DISTNAME=	wmG-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small GTK-based GNOME-compliant window manager

USE_XORG=	xpm
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

CFLAGS+=	-fpermissive

.include <bsd.port.mk>
