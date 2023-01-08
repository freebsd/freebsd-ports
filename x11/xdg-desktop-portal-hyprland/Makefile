PORTNAME=	xdg-desktop-portal-hyprland
PORTVERSION=	s20230108
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	xdg-desktop-portal backend for hyprland
WWW=		https://github.com/hyprwm/xdg-desktop-portal-hyprland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>=1.24:graphics/wayland-protocols
LIB_DEPENDS=	libbasu.so:devel/basu \
		libinih.so:devel/inih \
		libepoll-shim.so:devel/libepoll-shim \
		libdrm.so:graphics/libdrm \
		libwayland-client.so:graphics/wayland \
		libpipewire-0.3.so:multimedia/pipewire
RUN_DEPENDS=	grim:x11/grim \
		hyprland-share-picker:x11/hyprland-share-picker@${FLAVOR}

FLAVORS=	qt5 qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}
qt6_PKGNAMESUFFIX=	-qt6

USES=		compiler:c11 gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		gbm
GH_ACCOUNT=	hyprwm
GH_TAGNAME=	b03b1c2
GH_TUPLE=	hyprwm:hyprland-protocols:b8f55e0:hyprland_protocols/subprojects/hyprland-protocols
MESON_ARGS=	-Dsd-bus-provider=basu
PLIST_FILES=	libexec/${PORTNAME} \
		share/dbus-1/services/org.freedesktop.impl.portal.desktop.hyprland.service \
		share/xdg-desktop-portal/portals/hyprland.portal

OPTIONS_DEFINE=	SLURP
OPTIONS_DEFAULT=SLURP

SLURP_DESC=		Simple output chooser
SLURP_RUN_DEPENDS=	slurp:x11/slurp

.ifdef GH_TUPLE
post-install:
# XXX USES=meson invokes ninja directly, so doesn't support --skip-subprojects
	@${RM} -r ${STAGEDIR}${PREFIX}/share/pkgconfig
	@${RM} -r ${STAGEDIR}${PREFIX}/share/protocols
.endif

.include <bsd.port.mk>
