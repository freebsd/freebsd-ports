# New ports collection makefile for:   libunique
# Date created:			22 Feb 2009
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom$
#

PORTNAME=	unique
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.gnome.org/~ebassi/source/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for single instance applications.

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus

USE_XORG=	ice
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gtk20 gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/configure ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
