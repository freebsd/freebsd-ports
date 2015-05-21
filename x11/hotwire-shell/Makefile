# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD: head/x11/hotwire-shell/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	hotwire-shell
PORTVERSION=	0.721
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hotwire-${DISTVERSION}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Hotwire is an object-oriented hypershell

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte \
		${PYXML}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GNOME=	pygnome2 pygtk2 pygtksourceview
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
