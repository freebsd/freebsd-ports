PORTNAME=	xwaylandvideobridge
DISTVERSION=	0.4.0
PORTREVISION=	2
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tool to share specific windows to X11 clients
WWW=		https://invent.kde.org/system/xwaylandvideobridge

DEPRECATED=	Project has been discontinued
EXPIRATION_DATE=	2025-12-31

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/LicenseRef-KDE-Accepted-GPL.txt

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++20-lang gettext-tools gl kde:6 qt:6 \
		tar:xz xorg
USE_GL=		opengl
USE_KDE=	coreaddons i18n kpipewire notifications statusnotifieritem \
		windowsystem \
		ecm:build
USE_QT=		base declarative \
		tools:build
USE_XORG=	x11 xcb

.include <bsd.port.mk>
