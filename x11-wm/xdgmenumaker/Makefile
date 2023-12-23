PORTNAME=	xdgmenumaker
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	x11-wm python

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Generates XDG menus for several window managers
WWW=		https://github.com/gapan/xdgmenumaker

LICENSE=	GPLv3

BUILD_DEPENDS=	txt2tags:textproc/txt2tags
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR}

USES=		gnome python:run shebangfix
USE_GNOME=	gtk30 pygobject3
USE_GITHUB=	yes
GH_ACCOUNT=	gapan
SHEBANG_FILES=	src/xdgmenumaker

ALL_TARGET=	man

.include <bsd.port.mk>
