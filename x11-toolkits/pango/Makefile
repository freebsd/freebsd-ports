PORTNAME=	pango
PORTVERSION=	1.56.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Open-source framework for the layout and rendering of i18n text
WWW=		https://www.gtk.org/docs/architecture/pango

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libfontconfig.so:x11-fonts/fontconfig \
		libfribidi.so:converters/fribidi
TEST_DEPENDS=	cantarell-fonts>=0:x11-fonts/cantarell-fonts

USES=		compiler:c11 cpe gnome meson pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	cairo glib20 introspection:build
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^1\.[^9]

PLIST_SUB=	LIBVERSION=0.${PORTVERSION:R:E}00.${PORTVERSION:E}

TESTING_UNSAFE=	ERROR:../tests/test-font-data.c:153:test_boxes_font_metrics: assertion failed (metrics->approximate_char_width == boxes_unhinted_metrics.approximate_char_width): (46201 == 49273)

OPTIONS_DEFINE=		DOCS LANG_TH MANPAGES X11
OPTIONS_DEFAULT=	LANG_TH MANPAGES X11
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen \
			rst2man:textproc/py-docutils
DOCS_MESON_TRUE=	documentation

LANG_TH_LIB_DEPENDS=	libthai.so:devel/libthai
LANG_TH_MESON_ENABLED=	libthai

MANPAGES_MESON_TRUE=	man-pages
MANPAGES_IMPLIES=	DOCS

X11_USES=		xorg
X11_USE=		XORG=x11,xft,xrender
X11_MESON_ENABLED=	xft

pre-test:
# Don't test backup files. Silly Meson.
	@${FIND} ${WRKSRC}/tests/fontsets/ -name "*.orig" -delete

.include <bsd.port.mk>
