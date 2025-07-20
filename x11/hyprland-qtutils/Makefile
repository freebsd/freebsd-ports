PORTNAME=	hyprland-qtutils
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Hyprland QT/qml utility apps
WWW=		https://github.com/hyprwm/hyprland-qtutils

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprutils.so:devel/hyprutils
RUN_DEPENDS=	hyprland-qt-support>0:x11-toolkits/hyprland-qt-support

USES=		cmake compiler:c++11-lib pkgconfig qt:6
USE_GITHUB=	yes
USE_QT=		base declarative wayland:build
GH_ACCOUNT=	hyprwm
LDFLAGS+=	-Wl,--as-needed # Qt deps
PLIST_FILES=	bin/hyprland-dialog \
		bin/hyprland-donate-screen \
		bin/hyprland-update-screen

.include <bsd.port.mk>
