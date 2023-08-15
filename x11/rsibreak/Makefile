PORTNAME=	rsibreak
DISTVERSION=	0.12.15
PORTREVISION=	3
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE RSI prevention tool
WWW=		https://userbase.kde.org/RSIBreak

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth codecs config configwidgets coreaddons crash dbusaddons \
		doctools i18n iconthemes idletime notifications notifyconfig \
		sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		core dbus gui widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
