PORTNAME=	antimicrox
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Program to map gamepad keys to keyboard, mouse, scripts and macros
WWW=		https://github.com/AntiMicroX/antimicrox

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		itstool:textproc/itstool \
		msgfmt:devel/gettext-tools

USES=		cmake desktop-file-utils kde:6 pkgconfig qt:6 sdl \
		shared-mime-info xorg
USE_GITHUB=	yes
GH_ACCOUNT=	AntimicroX
USE_KDE=	ecm
USE_QT=		base tools

USE_SDL=	sdl2
USE_XORG=	x11 xi xtst

CMAKE_ARGS=	-DINSTALL_UINPUT_UDEV_RULES:BOOL=FALSE

LDFLAGS+=	-lexecinfo

.include <bsd.port.mk>
