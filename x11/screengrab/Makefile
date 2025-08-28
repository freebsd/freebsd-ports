PORTNAME=	screengrab
PORTVERSION=	3.0.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	Screen dump utility
WWW=		https://github.com/lxqt/screengrab

LICENSE=	LGPL21+

USES=		cmake compiler:c++20-lang gnome kde:6 localbase:ldflags lxqt:2 \
		perl5 qt:6 tar:xz xorg
USE_LXQT=	buildtools2 qt6xdg
USE_XORG=	x11 xcb sm ice xext
USE_KDE=	layer-shell-qt wayland windowsystem
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_GNOME=	glib20

.include <bsd.port.mk>
