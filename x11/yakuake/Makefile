PORTNAME=	yakuake
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	x11 kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Drop-down terminal emulator for KDE
WWW=		https://www.kde.org/applications/system/yakuake

LICENSE=	GPLv2

RUN_DEPENDS=	konsole:x11/konsole

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	archive attica auth codecs completion config configwidgets \
		coreaddons crash dbusaddons globalaccel i18n iconthemes \
		jobwidgets kio newstuff notifications notifyconfig parts \
		service solid sonnet statusnotifieritem textwidgets wayland \
		widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
