# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yelp
PORTVERSION=	3.18.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Help browser for the GNOME 3 desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl \
		itstool:textproc/itstool
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3
RUN_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool pathfix \
		pkgconfig tar:xz
USE_XORG=	x11 ice
USE_GNOME=	gtk30 intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GLIB_SCHEMAS=	org.gnome.yelp.gschema.xml
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if !exists(/usr/libdata/pkgconfig/liblzma.pc)
CONFIGURE_ENV+=	YELP_LZMA_CFLAGS="-I/usr/include" \
		YELP_LZMA_LIBS="-L/usr/lib -llzma"
.endif

.include <bsd.port.mk>
