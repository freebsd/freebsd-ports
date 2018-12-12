# $FreeBSD$

PORTNAME=	kdelibs4support
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 porting aid from KDELibs4

BUILD_DEPENDS=	p5-URI>=0:net/p5-URI

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 qt:5 shebangfix \
		tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools emoticons globalaccel guiaddons \
		i18n iconthemes itemviews jobwidgets kded kio notifications \
		parts service solid sonnet textwidgets unitconversion \
		widgetsaddons windowsystem xmlgui \
		designerplugin_build designerplugin_run \
		itemmodels_run
USE_QT=		buildtools_build core dbus designer gui network \
		printsupport qmake_build svg testlib widgets \
		x11extras xml
USE_XORG=	ice sm x11 xext

SHEBANG_FILES=	src/kio/fileshareset

.include <bsd.port.mk>
