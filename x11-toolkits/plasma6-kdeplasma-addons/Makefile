PORTNAME=	kdeplasma-addons
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-toolkits kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	All kind of add-ons to improve your Plasma experience

BUILD_DEPENDS=	${LOCALBASE}/share/cmake/Corrosion.cmake:devel/corrosion
LIB_DEPENDS=	libicuuc.so:devel/icu

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_GL=		gl opengl
USE_KDE=	colorscheme completion config configwidgets coreaddons \
		globalaccel holidays i18n itemmodels jobwidgets kcmutils \
		kdeclarative kio kirigami-addons \
		libplasma newstuff notifications package runner \
		service solid sonnet unitconversion widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_QT=		base declarative webchannel webengine \
		quick3d
USE_XORG=	x11

.include <bsd.port.mk>
