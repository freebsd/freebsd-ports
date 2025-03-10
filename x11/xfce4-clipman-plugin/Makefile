PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	1.6.7
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Clipboard manager for the Xfce panel
WWW=		https://docs.xfce.org/panel-plugins/xfce4-clipman-plugin/start

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce xorg
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30
USE_XFCE=	libmenu panel xfconf
USE_XORG=	ice sm x11 xorgproto xtst

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS QRCODE WAYLAND
OPTIONS_DEFAULT=WAYLAND
OPTIONS_SUB=	yes

QRCODE_DESC=	QR Code support

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

QRCODE_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODE_CONFIGURE_ENABLE=libqrencode

WAYLAND_CATEGORIES=	wayland
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_CONFIGURE_ENABLE=wayland

.include <bsd.port.mk>
