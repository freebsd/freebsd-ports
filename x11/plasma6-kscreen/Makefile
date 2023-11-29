PORTNAME=	kscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

COMMENT=	KDE screen management software
MAINTAINER=	kde@FreeBSD.org

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	config dbusaddons globalaccel i18n iconthemes kcmutils \
		layer-shell-qt libkscreen libplasma svg xmlgui \
		ecm:build
USE_QT=		base sensors

.include <bsd.port.mk>
