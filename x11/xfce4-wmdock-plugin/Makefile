# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-wmdock-plugin
PORTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	WMdock plugin for Xfce

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce:gtk2 xorg
USE_GNOME=	cairo gtk20 intltool libwnck
USE_XFCE=	libgui panel
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
