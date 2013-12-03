# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/unique/Makefile,v 1.12 2012/09/03 16:28:30 mezz Exp $

PORTNAME=	unique
PORTVERSION=	1.1.6
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/lib${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for single instance applications

PORTSCOUT=	ignore:1

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

USE_XORG=	ice
USE_BZIP2=	yes
USES=		gettext gmake pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gtk20 gnomeprefix introspection:build ltverhack:2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-flags
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/configure ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|G_CONST_RETURN|const|g' \
		${WRKSRC}/unique/uniqueapp.c \
		${WRKSRC}/unique/uniquebackend.[ch] \
		${WRKSRC}/unique/uniqueinternals.h \
		${WRKSRC}/unique/uniquemessage.[ch]

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libunique-1.0.so.2

.include <bsd.port.mk>
