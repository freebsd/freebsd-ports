# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-runner
PORTVERSION=	0.14.1
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	LXQt tool used to launch programs quickly

LICENSE=	LGPL21+

LIB_DEPENDS=	libmuparser.so:math/muparser

USES=	cmake compiler:c++14-lang gettext-runtime kde:5 qt:5 \
	gnome localbase lxqt pkgconfig tar:xz
USE_QT=	buildtools_build qmake_build core dbus gui linguisttools \
	script svg widgets x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools globalkeys qtxdg

CMAKE_ARGS=	-DRUNNER_VBOX:BOOL=OFF

.include <bsd.port.mk>
