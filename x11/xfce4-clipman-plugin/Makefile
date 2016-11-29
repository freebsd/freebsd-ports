# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	1.4.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Clipboard manager for the Xfce panel

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
	libdbus-glib-1.so:devel/dbus-glib

OPTIONS_DEFINE=	QRCODE
QRCODE_DESC=	QR Code support
QRCODE_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODE_CONFIGURE_ENABLE=	libqrencode

GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 intltool intlhack glib20 cairo
USE_XFCE=	panel
USE_XORG=	ice sm x11 xtst xproto
USES=		gettext gmake libtool pkgconfig tar:bzip2 xfce:gtk3
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
