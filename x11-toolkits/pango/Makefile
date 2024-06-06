PORTNAME=	pango
PORTVERSION=	1.52.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Open-source framework for the layout and rendering of i18n text
WWW=		https://www.pango.org/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi
TEST_DEPENDS=	cantarell-fonts>=0:x11-fonts/cantarell-fonts

USES=		cpe gnome meson pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	cairo glib20 introspection:build
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^1\.[^9]

VERSION=	1.8.0
LIBVERSION=	0.5200.2
PLIST_SUB=	LIBVERSION=${LIBVERSION} \
		VERSION=${VERSION}

OPTIONS_DEFINE=	X11 DOCS MANPAGES THAI
OPTIONS_DEFAULT=X11 MANPAGES THAI
OPTIONS_SUB=	yes

THAI_DESC=	Thai language support via libThai

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	gtk_doc

MANPAGES_BUILD_DEPENDS=	help2man:misc/help2man

THAI_LIB_DEPENDS=	libthai.so:devel/libthai
THAI_MESON_ENABLED=	libthai

X11_USES=	xorg
X11_USE=	XORG=x11,xft,xrender
X11_MESON_ENABLED=	xft

TESTING_UNSAFE=	2 out of 24 tests fail

pre-configure:
# .if !exists() evaluates too early before cairo has a chance to be installed
	@if ! pkg-config --exists cairo-gobject; then \
		${ECHO_MSG} "${PKGNAME}: Needs cairo with GLIB (GObject) support enabled."; \
		${FALSE}; \
	fi

.include <bsd.port.mk>
