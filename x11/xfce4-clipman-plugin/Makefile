# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	1.2.6
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Clipboard manager for the Xfce panel

LICENSE=	GPLv2

OPTIONS_DEFINE=	QRCODE UNIQUE
OPTIONS_DEFAULT=	UNIQUE
QRCODE_DESC=	QR Code support
UNIQUE_DESC=	Unique (single instance) support
QRCODE_LIB_DEPENDS=	libqrencode.so:graphics/libqrencode
QRCODE_CONFIGURE_ENABLE=	libqrencode
UNIQUE_LIB_DEPENDS=	libunique-1.0.so:x11-toolkits/unique
UNIQUE_CONFIGURE_ENABLE=	unique

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack glib20
USE_XFCE=	panel
USE_XORG=	xtst xproto
USES=		gettext gmake libtool pkgconfig xfce tar:bzip2
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
