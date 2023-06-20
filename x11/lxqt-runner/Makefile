PORTNAME=	lxqt-runner
PORTVERSION=	1.3.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt tool used to launch programs quickly
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmuparser.so:math/muparser

USES=		cmake compiler:c++14-lang gettext-runtime kde:5 qt:5 \
		gnome localbase lxqt perl5 pkgconfig tar:xz xorg
USE_PERL5=	build
USE_QT=		buildtools:build qmake:build core dbus gui linguisttools \
		script svg widgets x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools globalkeys qtxdg
USE_XORG=	x11
CMAKE_ARGS=	-DRUNNER_VBOX:BOOL=OFF

.include <bsd.port.mk>
