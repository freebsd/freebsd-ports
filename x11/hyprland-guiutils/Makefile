PORTNAME=	hyprland-guiutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland GUI utilities
WWW=		https://github.com/hyprwm/hyprland-guiutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprlang.so:devel/hyprlang \
		libhyprutils.so:devel/hyprutils \
		libdrm.so:graphics/libdrm \
		libhyprtoolkit.so:x11-toolkits/hyprtoolkit \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lib pkgconfig xorg

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_XORG=	pixman

LDFLAGS+=	-Wl,--as-needed

CONFLICTS_INSTALL=	hyprland-qtutils

PLIST_FILES=	bin/hyprland-dialog \
		bin/hyprland-donate-screen \
		bin/hyprland-run \
		bin/hyprland-update-screen \
		bin/hyprland-welcome

.include <bsd.port.mk>
