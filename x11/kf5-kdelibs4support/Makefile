PORTNAME=	kdelibs4support
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 porting aid from KDELibs4
WWW=		https://api.kde.org/frameworks-api/frameworks5-apidocs/kdelibs4support/html/index.html

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 shebangfix \
		tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons emoticons globalaccel guiaddons \
		i18n iconthemes itemviews jobwidgets kded kio notifications \
		parts service solid sonnet textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui \
		doctools_build ecm_build \
		designerplugin_build designerplugin_run \
		itemmodels_run
USE_QT=		concurrent core dbus designer gui network \
		printsupport svg testlib widgets x11extras xml \
		buildtools_build qmake_build testlib_build
USE_XORG=	ice sm x11 xcb xext

SHEBANG_FILES=	src/kio/fileshareset

.include <bsd.port.mk>
