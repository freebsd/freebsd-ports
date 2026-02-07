PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	1.7.0
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Clipboard manager for the Xfce panel
WWW=		https://docs.xfce.org/panel-plugins/xfce4-clipman-plugin/start

LICENSE=	GPLv2

USES=		compiler:c11 gettext-tools gnome meson pkgconfig tar:xz xfce \
		xorg
USE_GNOME=	glib20 gtk30
USE_XFCE=	libmenu panel xfconf
USE_XORG=	ice sm x11 xorgproto xtst

MESON_ARGS=	-Dx11=enabled \
		-Dxtst=enabled

OPTIONS_DEFINE=	NLS QRCODE WAYLAND
OPTIONS_DEFAULT=WAYLAND
OPTIONS_SUB=	yes

QRCODE_DESC=	QR Code support

NLS_USES=	gettext-runtime

QRCODE_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODE_MESON_ENABLED=	qrencode

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_ENABLED=	wayland

post-patch-NLS-off:
	@${REINPLACE_CMD} -e "/^subdir('po')/d" ${WRKSRC}/meson.build

.include <bsd.port.mk>
