# Created by: Matt Lancereau
# $FreeBSD$

PORTNAME=	xfce4-terminal
PORTVERSION=	0.8.7.1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Terminal emulator for the X windowing system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		gettext gmake pkgconfig tar:bzip2 xfce:gtk3
GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 glib20 cairo gdkpixbuf2 intltool vte3 libxml2
USE_XFCE=	libmenu
USE_XORG=	x11
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--without-gnome-default-appsdir

.include <bsd.port.mk>
