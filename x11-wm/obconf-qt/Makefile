PORTNAME=	obconf-qt
PORTVERSION=	0.16.5
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Qt port of preferences manager for Openbox
WWW=		https://github.com/lxqt/obconf-qt

LICENSE=	GPLv2

LIB_DEPENDS=	libobt.so:x11-wm/openbox \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libImlib2.so:graphics/imlib2 \
		libharfbuzz.so:print/harfbuzz

USES=		cmake compiler:c++20-lang gettext-runtime localbase qt:6 \
		gnome lxqt:2 perl5 pkgconfig tar:xz xorg

USE_PERL5=	build

USE_QT=		base:run tools:build
USE_LXQT=	buildtools2

USE_GNOME=	glib20 pango librsvg2 gdkpixbuf libxml2 cairo

USE_XORG=	ice sm x11 xft

.include <bsd.port.mk>
