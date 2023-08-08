PORTNAME=	xdg-desktop-portal-gtk
DISTVERSION=	1.14.1
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Gtk implementation of xdg-desktop-portal
WWW=		https://github.com/flatpak/xdg-desktop-portal-gtk

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz
RUN_DEPENDS=	xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		autoreconf desktop-file-utils gettext gmake gnome libtool pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30 pango

GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flatpak

.include <bsd.port.mk>
