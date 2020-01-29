# $FreeBSD$

PORTNAME=	albert
DISTVERSIONPREFIX=v
DISTVERSION=	0.16.1
CATEGORIES=	x11

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	Albert a keyboard launcher

LICENSE=	GPLv3

LIB_DEPENDS=	libmuparser.so:math/muparser
BUILD_DEPENDS=	pybind11>=2.4.3:devel/pybind11

USES=	cmake localbase pkgconfig xorg qt:5 python:3.7+ compiler:c++14-lang

USE_QT=	buildtools qmake core x11extras charts network sql gui widgets concurrent dbus \
	declarative svg

USE_XORG=x11 xext sm ice
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_TUPLE=	albertlauncher:albert:v0.16.1 \
		albertlauncher:plugins:029bd8ccb58c4452bd82ab42be8739f1639e42d4:albert/plugins

.include <bsd.port.mk>
