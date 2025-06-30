PORTNAME=	yelp
DISTVERSION=	42.3
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Help browser for the GNOME desktop
WWW=		https://gitlab.gnome.org/GNOME/yelp

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool \
		yelp-xsl>=0:textproc/yelp-xsl \
		bash:shells/bash
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libhandy-1.so:x11-toolkits/libhandy \
		libharfbuzz.so:print/harfbuzz \
		libsoup-3.0.so:devel/libsoup3 \
		libwebkit2gtk-4.1.so:www/webkit2-gtk@41
RUN_DEPENDS=	yelp-xsl>=0:textproc/yelp-xsl

USES=		compiler:c11 desktop-file-utils gettext gnome meson \
		pkgconfig shebangfix sqlite tar:xz xorg
USE_GNOME=	cairo gdkpixbuf gtk30 libxml2 libxslt
USE_XORG=	ice x11
SHEBANG_FILES=	data/domains/gen_yelp_xml.sh \
		src/link-gnome-help.sh
GLIB_SCHEMAS=	org.gnome.yelp.gschema.xml
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBEXECDIR%%|${PREFIX}/libexec|g' \
		${WRKSRC}/libyelp/yelp-man-parser.c

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/yelp-groff ${STAGEDIR}${PREFIX}/libexec

.include <bsd.port.mk>
