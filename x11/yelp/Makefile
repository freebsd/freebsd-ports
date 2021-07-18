# Created by: Maxim Sobolev <sobomax@FreeBSD.org>

PORTNAME=	yelp
DISTVERSION=	40.2
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Help browser for the GNOME 3 desktop

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl \
		itstool:textproc/itstool
LIB_DEPENDS=	libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libharfbuzz.so:print/harfbuzz \
		libsoup-2.4.so:devel/libsoup
RUN_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gettext gmake gnome \
		libtool pathfix pkgconfig sqlite tar:xz xorg
USE_XORG=	x11 ice
USE_GNOME=	cairo gtk30 libxml2 libxslt
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes
GLIB_SCHEMAS=	org.gnome.yelp.gschema.xml
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBEXECDIR%%|${PREFIX}/libexec|g' \
		${WRKSRC}/libyelp/yelp-man-parser.c

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/yelp-groff ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
