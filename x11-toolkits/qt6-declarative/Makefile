PORTNAME=	declarative
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces
WWW=		https://qt-project.org

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libdouble-conversion.so:devel/double-conversion \
		libexpat.so:textproc/expat2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgraphite2.so:graphics/graphite2 \
		libharfbuzz.so:print/harfbuzz \
		libicudata.so:devel/icu \
		libpcre.so:devel/pcre \
		libpcre2-16.so:devel/pcre2 \
		libpng16.so:graphics/png \
		libxkbcommon.so:x11/libxkbcommon \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang gettext-runtime gl gnome pkgconfig python xorg \
		qt-dist:6
USE_GL=		opengl
USE_GNOME=	glib20
USE_QT=		base shadertools languageserver
USE_XORG=	x11 xau xcb xdmcp
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

post-patch:
	${REINPLACE_CMD} -e "s#python3#${PYTHON_CMD}#g" ${WRKSRC}/cmake/QtDeclarativeSetup.cmake

# TODO: do this cleaner
post-install:
	${RM} -vr ${STAGEDIR}${PREFIX}/${QT_LIBDIR_REL}/cmake
	# Install symlinks for user-facing tools
	${REINPLACE_CMD} -e "s#^#${STAGEDIR}#" -e "s# # ${STAGEDIR}#" \
		${WRKDIR}/.build/user_facing_tool_links.txt
	while read t; do \
		${RLN} $$t; \
	done <${WRKDIR}/.build/user_facing_tool_links.txt

.include <bsd.port.mk>
