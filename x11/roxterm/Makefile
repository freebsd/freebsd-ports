PORTNAME=	roxterm
PORTVERSION=	3.16.2
CATEGORIES=	x11

MAINTAINER=	nc@FreeBSD.org
COMMENT=	GTK terminal emulator with tabs
WWW=		https://github.com/realh/roxterm

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cmake gnome pkgconfig tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	realh
USE_GNOME=	cairo librsvg2:run libxslt:build vte3
USE_CSTD=	c99

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
