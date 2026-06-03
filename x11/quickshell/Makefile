PORTNAME=	quickshell
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://git.outfoxxed.me/${PORTNAME}/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Building blocks for your desktop
WWW=		https://quickshell.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/share/cmake/CLI11/CLI11Config.cmake:devel/cli11 \
		${LOCALBASE}/lib/cmake/SPIRV-Tools/SPIRV-ToolsConfig.cmake:graphics/spirv-tools \
		vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake:testing display:test gl localbase:ldflags pkgconfig qt:6

USE_GL=		opengl
USE_QT=		5compat base declarative imageformats multimedia svg \
		shadertools:build

CMAKE_ARGS=	-DDISTRIBUTOR:STRING="FreeBSD ports/packages" \
		-DINSTALL_QML_PREFIX:STRING=${QT_QMLDIR_REL} \
		-DGIT_REVISION:STRING=${GIT_COMMIT_HASH}
CMAKE_OFF=	CRASH_HANDLER

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=	DOCS MPRIS PAM PIPEWIRE POLKIT STATUS_NOTIFIER WAYLAND X11
OPTIONS_DEFAULT=MPRIS PAM PIPEWIRE POLKIT STATUS_NOTIFIER WAYLAND X11
OPTIONS_SUB=	yes

MPRIS_DESC=		MPRIS compatible media players support
POLKIT_DESC=		PolicyKit framework agents support
STATUS_NOTIFIER_DESC=	System tray support

MPRIS_CMAKE_BOOL=	SERVICE_MPRIS
PAM_CMAKE_BOOL=		SERVICE_PAM
PIPEWIRE_LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire
PIPEWIRE_CMAKE_BOOL=	SERVICE_PIPEWIRE
POLKIT_LIB_DEPENDS=	libpolkit-agent-1.so:sysutils/polkit
POLKIT_USES=		gnome
POLKIT_USE=		gnome=glib20
POLKIT_CMAKE_BOOL=	SERVICE_POLKIT
STATUS_NOTIFIER_CMAKE_BOOL=	SERVICE_STATUS_NOTIFIER
WAYLAND_BUILD_DEPENDS=	wayland-scanner:graphics/wayland \
			wayland-protocols>=1.41:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_USE=		gl=egl,gbm,gl \
			qt=wayland
WAYLAND_CMAKE_BOOL=	WAYLAND
X11_USES=		xorg
X11_USE=		gl=egl,gbm,gl \
			xorg=xcb
X11_CMAKE_BOOL=		X11

GIT_COMMIT_HASH=	59e9c47b0eb48a9e4bcf9631fa062ee939bd2e83

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
