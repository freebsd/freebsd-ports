# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	hotwire-shell
PORTVERSION=	0.721
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hotwire-${DISTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Object-oriented hypershell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:graphics/py-cairo \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:devel/py-gobject \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:x11-toolkits/py-vte
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2
USE_PYTHON=	autoplist distutils
USE_GNOME=	pygnome2 pygtk2 pygtksourceview
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
