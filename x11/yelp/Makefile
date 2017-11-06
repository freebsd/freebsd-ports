# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yelp
PORTVERSION=	3.22.0
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Help browser for the GNOME 3 desktop

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl \
		itstool:textproc/itstool
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl

PORTSCOUT=	limitw:1,even

USES=		desktop-file-utils gettext gmake gnome libtool pathfix \
		pkgconfig sqlite tar:xz
USE_XORG=	x11 ice
USE_GNOME=	cairo gtk30 intlhack libxml2 libxslt
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	org.gnome.yelp.gschema.xml
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if !exists(/usr/libdata/pkgconfig/liblzma.pc)
CONFIGURE_ENV+=	YELP_LZMA_CFLAGS="-I/usr/include" \
		YELP_LZMA_LIBS="-L/usr/lib -llzma"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBEXECDIR%%|${PREFIX}/libexec|g' \
		${WRKSRC}/libyelp/yelp-man-parser.c

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/yelp-groff ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
