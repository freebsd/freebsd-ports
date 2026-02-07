PORTNAME=	unique
DISTVERSION=	1.1.6
PORTREVISION=	9
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DISTNAME=	lib${PORTNAME}-${PORTVERSION}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Library for single instance applications
WWW=		https://live.gnome.org/LibUnique

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		gettext gmake gnome libtool localbase:ldflags pathfix pkgconfig \
		tar:bzip2
USE_GNOME=	gnomeprefix gtk20 introspection:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-maintainer-flags

INSTALL_TARGET=	install-strip

PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} -e 's|G_CONST_RETURN|const|g' \
		${WRKSRC}/unique/uniqueapp.c \
		${WRKSRC}/unique/uniquebackend.[ch] \
		${WRKSRC}/unique/uniqueinternals.h \
		${WRKSRC}/unique/uniquemessage.[ch]

.include <bsd.port.mk>
