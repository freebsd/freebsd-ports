# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfce4-quicklauncher-plugin
PORTVERSION=	1.9.4
PORTREVISION=	18
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Quicklauncher plugin for Xfce

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext gmake gnome libtool pkgconfig tar:bzip2 xfce
USE_GNOME=	cairo gdkpixbuf2 gtk20 intlhack intltool
USE_XFCE=	libgui panel

SSP_UNSAFE=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
