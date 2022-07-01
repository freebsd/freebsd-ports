# Created by: Maxim Sobolev <sobomax@FreeBSD.org>

PORTNAME=	yelp
DISTVERSION=	42.1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Help browser for the GNOME desktop

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		yelp-xsl>=0:textproc/yelp-xsl
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libhandy-1.so:x11-toolkits/libhandy \
		libharfbuzz.so:print/harfbuzz \
		libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-5.0.so:www/webkit2-gtk4
RUN_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl

USES=		compiler:c11 desktop-file-utils gettext gmake gnome libtool \
		pathfix pkgconfig sqlite tar:xz xorg
USE_GNOME=	cairo gtk30 libxml2 libxslt
GLIB_SCHEMAS=	org.gnome.yelp.gschema.xml
USE_LDCONFIG=	yes
USE_XORG=	ice x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-webkit2gtk-4-0
INSTALL_TARGET=	install-strip

PORTSCOUT=	limitw:1,even

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBEXECDIR%%|${PREFIX}/libexec|g' \
		${WRKSRC}/libyelp/yelp-man-parser.c

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/yelp-groff ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
