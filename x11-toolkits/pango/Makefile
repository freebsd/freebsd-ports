PORTNAME=	pango
DISTVERSION=	1.58.2
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

PLIST_SUB=	LIBVERSION=0.5800.2

MESON_ARGS=	-Dbuild-testsuite=false \
		-Dbuild-examples=false

OPTIONS_DEFINE=		DOCS LANG_TH MANPAGES X11
OPTIONS_DEFAULT=	LANG_TH MANPAGES X11
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen \
			rst2html5:textproc/py-docutils
DOCS_MESON_TRUE=	documentation

LANG_TH_LIB_DEPENDS=	libthai.so:devel/libthai
LANG_TH_MESON_ENABLED=	libthai

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_TRUE=	man-pages

X11_USES=		xorg
X11_USE=		XORG=x11,xft,xrender
X11_MESON_ENABLED=	xft

post-patch:
	${REINPLACE_CMD} -e 's|/etc/fonts/fonts.conf|${LOCALBASE}&|' \
		${WRKSRC}/tests/meson.build

pre-test:
# Don't test backup files. Silly Meson.
	@${FIND} ${WRKSRC}/tests/fontsets/ -name "*.orig" -delete
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure -Dbuild-testsuite=true -Dbuild-examples=true"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
