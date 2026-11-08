PORTNAME=	roxterm
DISTVERSION=	3.18.2
CATEGORIES=	x11

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	GTK terminal emulator with tabs
WWW=		https://github.com/realh/roxterm

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libpcre2-8.so:devel/pcre2
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		cmake gettext-tools:build gnome pkgconfig tar:xz
USE_CSTD=	c99
USE_GITHUB=	yes
GH_ACCOUNT=	realh
USE_GNOME=	cairo vte3 libxslt:build librsvg2:run

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
