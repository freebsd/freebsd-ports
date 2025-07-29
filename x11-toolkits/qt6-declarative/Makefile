PORTNAME=	declarative
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt6-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces

BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++17-lang gl pkgconfig python \
		qt-dist:6
USE_GL=		opengl
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_QT=		base svg \
		languageserver:build shadertools:build

CMAKE_ON=	CMAKE_DISABLE_FIND_PACKAGE_LTTngUST

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH:Marmv?} || ${ARCH} == i386
PLIST_SUB+=	QML_JIT=""
.else
PLIST_SUB+=	QML_JIT="@comment "
.endif

post-install:
# Install symlinks for user-facing tools
	while read line; do \
		source="$$(${ECHO_CMD} $${line} | ${AWK} '{print $$1}')"; \
		target="${STAGEDIR}${PREFIX}/$$(${ECHO_CMD} $${line} | ${AWK} '{print $$2}')"; \
		${RLN} $${source} $${target}; \
	done <${BUILD_WRKSRC}/user_facing_tool_links.txt

.include <bsd.port.mk>
