# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/cinnamon-menus/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	cinnamon-menus
PORTVERSION=	2.2.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Additional UI API for cinnamon

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		xkeyboard-config>=0:${PORTSDIR}/x11/xkeyboard-config \
		libxkbfile>=0:${PORTSDIR}/x11/libxkbfile
RUN_DEPENDS=	xkeyboard-config>=0:${PORTSDIR}/x11/xkeyboard-config \
		libxkbfile>=0:${PORTSDIR}/x11/libxkbfile

USES=		gettext gmake libtool pathfix pkgconfig python tar:xz
USE_GNOME=	gnomehier gnomemenus3 gnomeprefix gtk30 intlhack \
		introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
PATHFIX_MAKEFILEIN=	Makefile.am
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
