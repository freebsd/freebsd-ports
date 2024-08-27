PORTNAME=	watershot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	16
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Wayland-native screenshot tool
WWW=		https://github.com/Kirottu/watershot

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libfontconfig.so:x11-fonts/fontconfig \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/lib/libvulkan.so:graphics/vulkan-loader \
		grim:x11/grim

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Kirottu
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
