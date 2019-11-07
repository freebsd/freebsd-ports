# $FreeBSD$

PORTNAME=	gtkplatform
DISTVERSION=	0.2.2
PORTREVISION=	3
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK platform backend for Qt 5

LICENSE=	LGPL3 GPLv2+
LICENSE_COMB=	dual

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libinput.so:x11/libinput \
		libmtdev.so:devel/libmtdev \
		libnotify.so:devel/libnotify \
		libudev.so:devel/libudev-devd \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++11-lang gl gnome pkgconfig qmake:outsource qt:5 xorg
USE_GNOME=	gtk30 cairo gdkpixbuf2
USE_QT=		buildtools_build core gui widgets dbus
USE_XORG=	x11 xext xrender
USE_GL=		gl egl

USE_GITHUB=	yes
GH_ACCOUNT=	CrimsonAS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/qt5/plugins/platforms/libqgtk.so

.include <bsd.port.mk>
