# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-quicklauncher-plugin
PORTVERSION=	1.9.4
PORTREVISION=	19
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Quicklauncher plugin for Xfce

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		compiler:c11 gettext gmake gnome libtool pkgconfig tar:bzip2 \
		xfce:gtk2
USE_GNOME=	cairo gdkpixbuf2 gtk20 intltool
USE_XFCE=	libgui panel

SSP_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
