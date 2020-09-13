# $FreeBSD$

PORTNAME=	gtkplatform
DISTVERSION=	0.2.4-11
DISTVERSIONSUFFIX=	-g1149f4f
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK platform backend for Qt 5

LICENSE=	LGPL3 GPLv2+
LICENSE_COMB=	dual

DEPRECATED=	Archived upstream
EXPIRATION_DATE=	2021-04-15

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

pre-configure:
	cd ${WRKSRC} && syncqt.pl -module QtGtkExtras -version 0.2.4

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/qt5/plugins/platforms/libqgtk.so

.include <bsd.port.mk>
