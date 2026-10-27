PORTNAME=	kdeplasma-addons
DISTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	1
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
USE_QT=		base declarative webchannel \
		quick3d
USE_XORG=	x11

OPTIONS_DEFINE=		WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_armv7=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE
OPTIONS_DEFAULT_powerpc64le=	WEBENGINE
OPTIONS_SUB=		yes

WEBENGINE_DESC=		Dictionary and web browser applets (requires QtWebEngine)
WEBENGINE_USE=		QT=webengine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineQuick

.include <bsd.port.mk>
