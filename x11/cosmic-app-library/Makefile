PORTNAME=	cosmic-app-library
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	epoch-
CATEGORIES=	x11 wayland

# I submitted this patch to fix building for FreeBSD.
# It was merged upstream but I have to apply it manually
# until the next COSMIC version is released.
PATCH_SITES=	https://github.com/pop-os/iced/commit/
PATCHFILES=	e03ca50ed8838d3ec8392e32a68ce59634517945.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	jo.sh@tutanota.com
COMMENT=	Modern application launcher for COSMIC
WWW=		https://github.com/pop-os/cosmic-app-library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	cosmic-icons>=${PORTVERSION}:x11-themes/cosmic-icons

USES=		cargo desktop-file-utils gl pkgconfig
USE_GL=		egl
USE_GITHUB=	yes
GH_ACCOUNT=	pop-os
GH_TUPLE=	pop-os:iced:39d3c99d1315e9a3db76fa8b32aa91e439c38b32:iced/../${WRKSRC_crate_build_helpers:T}/iced

PATCH_WRKSRC=	${WRKSRC_crate_build_helpers}/iced

# My upstream patch renames linux.rs to unix.rs to better fit what it does.
# Unfortunately, patch doesn't apply the rename so we must do it manually.
post-patch:
	@${MV} \
		${WRKSRC_crate_build_helpers}/iced/core/src/window/settings/linux.rs \
		${WRKSRC_crate_build_helpers}/iced/core/src/window/settings/unix.rs

PLIST_FILES=	bin/cosmic-app-library \
		share/applications/com.system76.CosmicAppLibrary.desktop \
		share/metainfo/com.system76.CosmicAppLibrary.metainfo.xml \
		share/icons/hicolor/scalable/apps/com.system76.CosmicAppLibrary.svg

post-install:
	@${MKDIR} \
		${STAGEDIR}${PREFIX}/share/applications \
		${STAGEDIR}${PREFIX}/share/metainfo \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} \
		${WRKSRC}/target/xdgen/com.system76.CosmicAppLibrary.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} \
		${WRKSRC}/target/xdgen/com.system76.CosmicAppLibrary.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} \
		${WRKSRC}/data/icons/com.system76.CosmicAppLibrary.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps

.include <bsd.port.mk>
