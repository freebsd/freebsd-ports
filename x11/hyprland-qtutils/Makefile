PORTNAME=	hyprland-qtutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
PORTREVISION=	2
CATEGORIES=	x11

PATCH_SITES=	https://github.com/hyprwm/hyprland-qtutils/commit/
PATCHFILES+=	5ffdfc13ed03df1dae5084468d935f0a3f2c9a4c.patch:-p1 # Fix configure with Qt 6.10

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland QT/qml utility apps
WWW=		https://github.com/hyprwm/hyprland-qtutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Superceded by hyprland-guiutils. Use x11/hyprland-guiutils instead.
EXPIRATION_DATE=	2025-12-31

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils
RUN_DEPENDS=	hyprland-qt-support>0:x11-toolkits/hyprland-qt-support

USES=		cmake compiler:c++11-lib pkgconfig qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	hyprwm

USE_QT=		base declarative wayland:build

LDFLAGS+=	-Wl,--as-needed # Qt deps

CONFLICTS_INSTALL=	hyprland-guiutils

PLIST_FILES=	bin/hyprland-dialog \
		bin/hyprland-donate-screen \
		bin/hyprland-update-screen

.include <bsd.port.mk>
