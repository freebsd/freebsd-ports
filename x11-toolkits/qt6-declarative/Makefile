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
USE_QT=		base languageserver shadertools:build svg
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

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
