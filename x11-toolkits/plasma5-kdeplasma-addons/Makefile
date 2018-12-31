# $FreeBSD$

PORTNAME=	kdeplasma-addons
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11-toolkits kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 addons to improve the Plasma experience

USES=		cmake compiler:c++11-lib cpe gettext \
		kde:5 pkgconfig qt:5 tar:xz
USE_KDE=	activities archive attica auth bookmarks codecs completion \
		config configwidgets coreaddons crash ecm emoticons guiaddons \
		i18n iconthemes init itemmodels itemviews jobwidgets kcmutils \
		kdelibs4support kio kross newstuff notifications package parts\
		plasma-framework plasma-workspace purpose runner service solid \
		sonnet textwidgets unitconversion widgetsaddons windowsystem xmlgui
USE_QT=		core dbus declarative graphicaleffects gui location network \
		printsupport script webchannel webengine widgets x11extras xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
