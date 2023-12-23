PORTNAME=	xdg-desktop-portal-gtk
DISTVERSION=	1.15.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gtk implementation of xdg-desktop-portal
WWW=		https://github.com/flatpak/xdg-desktop-portal-gtk

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		desktop-file-utils gettext gmake gnome libtool meson pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 gnomedesktop3

USE_GITHUB=	yes
GH_ACCOUNT=	flatpak

.include <bsd.port.mk>
