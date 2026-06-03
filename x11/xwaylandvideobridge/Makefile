PORTNAME=	xwaylandvideobridge
DISTVERSION=	0.5.0
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/src/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Utility to allow streaming Wayland windows to X applications
WWW=		https://invent.kde.org/system/xwaylandvideobridge

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/LicenseRef-KDE-Accepted-GPL.txt

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++20-lang gettext-tools gl kde:6 qt:6 \
		tar:xz xorg
USE_GL=		opengl
USE_KDE=	coreaddons crash i18n kpipewire statusnotifieritem \
		windowsystem \
		ecm:build
USE_QT=		base declarative \
		tools:build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
