PORTNAME=	quickshell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	x11
MASTER_SITES=	https://git.outfoxxed.me/${PORTNAME}/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Building blocks for your desktop
WWW=		https://quickshell.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/cmake/CLI11/CLI11Config.cmake:devel/cli11 \
		${LOCALBASE}/lib/cmake/SPIRV-Tools/SPIRV-ToolsConfig.cmake:graphics/spirv-tools
LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake:testing display:test gl localbase:ldflags pkgconfig qt:6

USE_GL=		opengl
USE_QT=		5compat base declarative imageformats multimedia svg \
		shadertools:build

CMAKE_ARGS=		-DDISTRIBUTOR:STRING="FreeBSD ports/packages" \
			-DINSTALL_QML_PREFIX:STRING=${QT_QMLDIR_REL} \
			-DGIT_REVISION:STRING=${GIT_COMMIT_HASH}
CMAKE_OFF=		DISTRIBUTOR_DEBUGINFO_AVAILABLE \
			CRASH_REPORTER \
			USE_JEMALLOC
CMAKE_BUILD_TYPE=	RelWithDebInfo

STRIP=		# empty

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS PIPEWIRE WAYLAND X11
OPTIONS_DEFAULT=PIPEWIRE WAYLAND X11
OPTIONS_SUB=	yes

PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	SERVICE_PIPEWIRE
WAYLAND_BUILD_DEPENDS=	wayland-scanner:graphics/wayland \
			wayland-protocols>0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libdrm.so:graphics/libdrm \
			libwayland-client.so:graphics/wayland
WAYLAND_USE=		gl=egl,gbm,gl \
			qt=wayland
WAYLAND_CMAKE_BOOL=	WAYLAND
X11_LIB_DEPENDS=	libdrm.so:graphics/libdrm
X11_USES=		xorg
X11_USE=		gl=egl,gbm,gl \
			xorg=xcb
X11_CMAKE_BOOL=		X11

GIT_COMMIT_HASH=a1a150fab00a93ea983aaca5df55304bc837f51b

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${ARCH} == i386
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-src_wayland_buffer_dmabuf.cpp
.endif

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/qs
	@${RLN} ${STAGEDIR}${PREFIX}/bin/quickshell ${STAGEDIR}${PREFIX}/bin/qs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
