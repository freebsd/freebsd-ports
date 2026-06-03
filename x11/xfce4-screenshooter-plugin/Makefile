PORTNAME=	xfce4-screenshooter-plugin
PORTVERSION=	1.11.3
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/apps
DISTNAME=	xfce4-screenshooter-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application and panel plugin to take screenshots
WWW=		https://goodies.xfce.org/projects/applications/xfce4-screenshooter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce \
		xorg
USE_CSTD=	c99
USE_GNOME=	glib20 gtk30
USE_XFCE=	libexo libmenu panel xfconf
USE_XORG=	ice sm x11 xext xfixes

MESON_ARGS=	-Dx11=enabled \
		-Dxfixes=enabled

OPTIONS_DEFINE=		NLS WAYLAND
OPTIONS_DEFAULT=	WAYLAND
OPTIONS_SUB=		yes

NLS_USES=	gettext-runtime

WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
WAYLAND_MESON_ENABLED=	wayland

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
