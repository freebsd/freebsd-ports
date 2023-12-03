PORTNAME=	kdeplasma-addons
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-toolkits kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	All kind of add-ons to improve your Plasma experience

LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme completion config configwidgets coreaddons \
		globalaccel holidays i18n jobwidgets kcmutils kdeclarative kio \
		libplasma newstuff notifications package plasma5support runner \
		service solid sonnet unitconversion widgetsaddons windowsystem \
		xmlgui \
		ecm:build \
		kirigami-addons:run
USE_QT=		5compat base declarative webchannel webengine
USE_XORG= x11

.include <bsd.port.mk>
