PORTNAME=	lxqt-runner
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt tool used to launch programs quickly
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmuparser.so:math/muparser

USES=		cmake compiler:c++20-lang gettext-runtime kde:6 lxqt:2 qt:6 \
		gnome localbase perl5 pkgconfig tar:xz xorg
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_KDE=	layer-shell-qt \
		windowsystem \
		ecm:build
USE_GNOME=	glib20
USE_LXQT=	buildtools2 globalkeys qt6xdg
USE_XORG=	x11
CMAKE_ARGS=	-DRUNNER_VBOX:BOOL=OFF

.include <bsd.port.mk>
