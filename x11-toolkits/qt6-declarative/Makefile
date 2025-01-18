PORTNAME=	declarative
DISTVERSION=	${QT6_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt6-

PATCH_SITES=	https://invent.kde.org/qt/qt/qtdeclarative/-/commit/
PATCHFILES+=	6e6add5406eb5d8daca0992fa3f2362d34b002e5.patch:-p1 # QTBUG-131898
PATCHFILES+=	eff776c676b042bd75604105a3876f999b9808d5.patch:-p1 # QTBUG-132421

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
