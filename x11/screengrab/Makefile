PORTNAME=	screengrab
PORTVERSION=	2.3.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Screen dump utility

LICENSE=	LGPL21+

USES=		cmake compiler:c++11-lang gnome kde:5 lxqt qt:5 tar:xz xorg
USE_LXQT=	qtxdg
USE_XORG=	x11 xcb sm ice xext
USE_KDE=	windowsystem
USE_QT=		buildtools qmake core dbus xml svg widgets gui x11extras network
USE_GNOME=	glib20

.include <bsd.port.mk>
