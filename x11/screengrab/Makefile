PORTNAME=	screengrab
PORTVERSION=	2.8.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Screen dump utility
WWW=		https://github.com/lxqt/screengrab

LICENSE=	LGPL21+

USES=		cmake compiler:c++17-lang gnome kde:6 lxqt:2 perl5 qt:6 tar:xz xorg
USE_LXQT=	qt6xdg
USE_XORG=	x11 xcb sm ice xext
USE_KDE=	windowsystem
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_GNOME=	glib20

.include <bsd.port.mk>
