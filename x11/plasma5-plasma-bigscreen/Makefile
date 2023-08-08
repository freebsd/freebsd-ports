PORTNAME=	plasma-bigscreen
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma5 Plasma workspace
WWW=		https://www.kde.org/plasma-desktop

USES=		cmake compiler:c++11-lib cpe desktop-file-utils gettext kde:5 \
		pkgconfig qt:5 tar:xz xorg
USE_KDE=	activities activities-stats auth codecs completion config \
		configwidgets coreaddons ecm i18n jobwidgets kcmutils \
		kdeclarative kio kirigami2 notifications package \
		plasma-framework plasma-workspace service solid wayland \
		widgetsaddons windowsystem
USE_QT=		concurrent core dbus declarative gui network widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11

.include <bsd.port.mk>
