# Created by: Matt Lancereau <matt@rimasec.net>
# $FreeBSD$

PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	1.2.6
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Clipboard manager for the Xfce panel

LICENSE=	GPLv2

OPTIONS_DEFINE=	QRCODE UNIQUE
QRCODE_DESC=	QR Code support
UNIQUE_DESC=	Unique (single instance) support

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack glib20
USE_XFCE=	configenv libexo libmenu libutil panel xfconf
USE_XORG=	xtst xproto
USES=		gettext gmake libtool pkgconfig tar:bzip2
INSTALLS_ICONS=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUNIQUE}
LIB_DEPENDS+=	libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique
CONFIGURE_ARGS+=	--enable-unique
.else
CONFIGURE_ARGS+=	--disable-unique
.endif

.if ${PORT_OPTIONS:MQRCODE}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
CONFIGURE_ARGS+=	--enable-libqrencode
.else
CONFIGURE_ARGS+=	--disable-libqrencode
.endif

.include <bsd.port.mk>
