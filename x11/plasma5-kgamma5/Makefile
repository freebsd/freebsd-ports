PORTNAME=	kgamma5
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 display gamma settings

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash emoticons guiaddons i18n iconthemes init \
		itemmodels itemviews jobwidgets kio notifications parts \
		service solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui \
		doctools_build ecm_build
USE_QT=		core dbus gui network printsupport widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xext xxf86vm

.include <bsd.port.mk>
