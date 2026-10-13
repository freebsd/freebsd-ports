PORTNAME=	xdg-desktop-portal-cosmic
PORTVERSION=	1.8.0
DISTVERSIONPREFIX=	epoch-
CATEGORIES=	x11

# I submitted this patch to fix building for FreeBSD.
# It was merged upstream but I have to apply it manually
# until I bump COSMIC to 1.9.0+.
PATCH_SITES=	https://github.com/pop-os/iced/commit/
PATCHFILES=	e03ca50ed8838d3ec8392e32a68ce59634517945.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	jo.sh@tutanota.com
COMMENT=	XDG desktop portal backend for COSMIC
WWW=		https://github.com/pop-os/xdg-desktop-portal-cosmic

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	cosmic-icons>=${PORTVERSION}:x11-themes/cosmic-icons \
		xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		cargo gl gnome llvm:build pkgconfig
USE_GL=		egl gbm
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	pop-os
GH_TUPLE=	pop-os:iced:39d3c99d1315e9a3db76fa8b32aa91e439c38b32:iced/../${WRKSRC_crate_libcosmic:T}/iced

CARGO_FEATURES=	--no-default-features wgpu

PATCH_WRKSRC=	${WRKSRC_crate_libcosmic}/iced

# My upstream patch renames linux.rs to unix.rs to better fit what it does.
# Unfortunately, patch doesn't apply the rename so we must do it manually.
#
# pipewire-rs also needs to be patched here. This process will be naturally
# cleaned up by the next version bump.
post-patch:
	@${MV} \
		${WRKSRC_crate_libcosmic}/iced/core/src/window/settings/linux.rs \
		${WRKSRC_crate_libcosmic}/iced/core/src/window/settings/unix.rs

	@cd ${WRKSRC_crate_pipewire} && \
		${PATCH} < ${FILESDIR}/manual-patch-pipewire-rs

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/services
	${SED} -e '/^SystemdService=/d' \
		-e 's|@libexecdir@|${PREFIX}/libexec|' \
		${WRKSRC}/data/dbus-1/org.freedesktop.impl.portal.desktop.cosmic.service.in \
		> ${STAGEDIR}${PREFIX}/share/dbus-1/services/org.freedesktop.impl.portal.desktop.cosmic.service
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals
	${INSTALL_DATA} ${WRKSRC}/data/cosmic.portal \
		${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/portals/cosmic.portal
	${INSTALL_DATA} ${WRKSRC}/data/cosmic-portals.conf \
		${STAGEDIR}${PREFIX}/share/xdg-desktop-portal/cosmic-portals.conf
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/actions
.for icon in screenshot-screen-symbolic.svg screenshot-selection-symbolic.svg screenshot-window-symbolic.svg
	${INSTALL_DATA} ${WRKSRC}/data/icons/scalable/actions/${icon} \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/actions/${icon}
.endfor

.include <bsd.port.mk>
