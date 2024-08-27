PORTNAME=	wl-kbptr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Control the mouse pointer with the keyboard on Wayland
WWW=		https://github.com/moverest/wl-kbptr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon

FLAVORS=	default opencv
default_CONFLICTS_INSTALL=	${PORTNAME}-opencv
opencv_PKGNAMESUFFIX=	-opencv
opencv_CONFLICTS_INSTALL=	${PORTNAME}
opencv_OPTIONS_SLAVE=	OPENCV

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo
GH_ACCOUNT=	moverest
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop

OPTIONS_DEFINE=	OPENCV
OPTIONS_SLAVE=	${${FLAVOR}_OPTIONS_SLAVE}

OPENCV_LIB_DEPENDS=	libopencv_imgproc.so:graphics/opencv
OPENCV_USES=		xorg
OPENCV_USE=		XORG=pixman
OPENCV_MESON_ENABLED=	opencv

.include <bsd.port.mk>
