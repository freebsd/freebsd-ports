# $FreeBSD$

PORTNAME=	wshowkeys
PORTVERSION=	s20190925
DISTVERSIONSUFFIX=	-0-ga9bf6bc
CATEGORIES=	x11
MASTER_SITES=	https://git.sr.ht/~sircmpwn/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Display keystrokes for screencasts on wlroots compositors

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libudev.so:devel/libudev-devd \
		libwayland-client.so:graphics/wayland \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 gnome meson pkgconfig
USE_GNOME=	cairo pango
PLIST_FILES=	"@(,,4755) bin/${PORTNAME}"

.include <bsd.port.mk>
