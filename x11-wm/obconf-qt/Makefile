PORTNAME=	obconf-qt
PORTVERSION=	0.16.4
PORTREVISION=	1
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

USES=		cmake compiler:c++11-lang gettext-runtime localbase qt:5 \
		gnome lxqt:1 perl5 pkgconfig tar:xz xorg

USE_PERL5=	build

USE_QT=		buildtools:build qmake:build core gui linguisttools \
		widgets x11extras

USE_LXQT=	buildtools

USE_GNOME=	glib20 pango librsvg2 gdkpixbuf2 libxml2 cairo

USE_XORG=	ice sm x11 xft

.include <bsd.port.mk>
