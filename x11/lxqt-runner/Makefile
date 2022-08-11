PORTNAME=	lxqt-runner
PORTVERSION=	1.1.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

PATCH_SITES=	https://github.com/lxqt/lxqt-runner/commit/
PATCHFILES=     b83c40c5086010eda3ad810e7332aa68799aad65.patch:-p1 \
		060dd76c7917e2e074d17ada1ca8bbb68758026a.patch:-p1

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt tool used to launch programs quickly

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmuparser.so:math/muparser

USES=		cmake compiler:c++14-lang gettext-runtime kde:5 qt:5 \
		gnome localbase lxqt pkgconfig tar:xz xorg
USE_QT=		buildtools_build qmake_build core dbus gui linguisttools \
		script svg widgets x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools globalkeys qtxdg
USE_XORG=	x11
CMAKE_ARGS=	-DRUNNER_VBOX:BOOL=OFF

.include <bsd.port.mk>
