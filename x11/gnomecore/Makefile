# New ports collection makefile for:   gnomecore
# Version required:    0.28.1
# Date created:        17 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.1.1.1 1998/09/06 06:37:58 vanilla Exp $
#

DISTNAME=	gnome-core-0.28.1
PKGNAME=	gnomecore-0.28.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	Nakai@technologist.com

BUILD_DEPENDS=	${LOCALBASE}/bin/orbit-config:${PORTSDIR}/devel/ORBit
LIB_DEPENDS=	gnome\\.0:${PORTSDIR}/x11/gnomelibs

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include -I../intl \
		-I../../intl" CXXFLAGS="${CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
