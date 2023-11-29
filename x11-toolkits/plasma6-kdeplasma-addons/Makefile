PORTNAME=	kdeplasma-addons
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-toolkits kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	All kind of add-ons to improve your Plasma experience

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	config coreaddons holidays i18n kcmutils kdeclarative kio \
		libplasma newstuff notifications plasma5support runner service \
		sonnet unitconversion xmlgui \
		ecm:build \
		kirigami-addons:run
USE_QT=		5compat base declarative webengine

.include <bsd.port.mk>
