# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	obconf-qt
PORTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Qt port of preferences manager for Openbox

LICENSE=	GPLv2

LIB_DEPENDS=	libobt.so:x11-wm/openbox \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libImlib2.so:graphics/imlib2

USES=		cmake compiler:c++11-lang gettext-runtime localbase qt:5 \
		gnome lxqt pkgconfig tar:xz

USE_QT=		buildtools_build qmake_build core gui linguisttools \
		widgets x11extras

USE_LXQT=	buildtools

USE_GNOME=	glib20 pango librsvg2 gdkpixbuf2 libxml2 cairo

USE_XORG=	ice sm x11 xft

PLIST_FILES=	bin/obconf-qt \
		share/applications/obconf-qt.desktop \
		share/icons/hicolor/48x48/apps/obconf-qt.png

.include <bsd.port.mk>
