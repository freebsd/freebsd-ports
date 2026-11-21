PORTNAME=	kdeplasma-addons
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-toolkits kde kde-plasma6lts

MAINTAINER=	kde@FreeBSD.org
COMMENT=	All kind of add-ons to improve your Plasma experience

LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	auth config coreaddons dbusaddons globalaccel holidays \
		i18n jobwidgets kcmutils kdeclarative kio newstuff \
		notifications runner service sonnet svg unitconversion \
		xmlgui \
		ecm:build \
		itemmodels:run kirigami-addons:run
# KDE Plasma
USE_KDE+=	libplasma
USE_QT=		base declarative webchannel webengine \
		tools:build \
		quick3d:run
USE_XORG=	x11

.include <bsd.port.mk>
