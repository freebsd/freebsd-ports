# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/x11-toolkits/unique/Makefile,v 1.12 2012/09/03 16:28:30 mezz Exp $

PORTNAME=	unique
PORTVERSION=	1.1.6
PORTREVISION=	7
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/lib${PORTNAME}/${PORTVERSION:R}/
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Library for single instance applications

PORTSCOUT=	ignore:1

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		gettext gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gtk20 gnomeprefix introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-flags
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|G_CONST_RETURN|const|g' \
		${WRKSRC}/unique/uniqueapp.c \
		${WRKSRC}/unique/uniquebackend.[ch] \
		${WRKSRC}/unique/uniqueinternals.h \
		${WRKSRC}/unique/uniquemessage.[ch]

.include <bsd.port.mk>
