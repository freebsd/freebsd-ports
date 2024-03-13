PORTNAME=	albert
DISTVERSIONPREFIX=v
DISTVERSION=	0.20.5
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Albert a keyboard launcher
WWW=		https://github.com/albertlauncher/albert

LICENSE=	GPLv3

BUILD_DEPENDS=	pybind11>=2.4.3:devel/pybind11
LIB_DEPENDS=	libmuparser.so:math/muparser \
		libqalculate.so:math/libqalculate
RUN_DEPENDS=	play:audio/sox

USES=	cmake compiler:c++20-lang gl localbase:ldflags pkgconfig python qt:6 xorg

USE_GL=	gl opengl
USE_QT=	base declarative scxml svg
USE_XORG=x11 xext sm ice
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	albertlauncher
GH_TUPLE=	albertlauncher:plugins:5a4611e31b41ab3ae638252116c72e2a7050a2cc:plugins/plugins \
		albertlauncher:python:6f734c7586c3889796846618fc9d8edb1a1ea386:python/plugins/python/plugins \
		skycoder42:QHotkey:34330d6ff5d2ca111c376f6d7da66be9d1817430:QHotkey/lib/QHotkey
.include <bsd.port.mk>
