PORTNAME=	rsibreak
DISTVERSION=	0.13.0
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE RSI prevention tool
WWW=		https://userbase.kde.org/RSIBreak

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang gettext-tools gl kde:6 qt:6 \
		tar:xz xorg
USE_GL=		opengl
USE_KDE=	colorscheme config configwidgets coreaddons crash \
		dbusaddons doctools guiaddons i18n idletime notifications \
		notifyconfig sonnet statusnotifieritem textwidgets \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

.include <bsd.port.mk>
