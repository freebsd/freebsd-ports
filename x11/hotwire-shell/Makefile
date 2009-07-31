# New ports collection makefile for:	hotwire-shell
# Date created:		2008-06-25
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hotwire-shell
PORTVERSION=	0.721
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	hotwire-${DISTVERSION}

MAINTAINER=	wahjava@gmail.com
COMMENT=	Hotwire is an object-oriented hypershell

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus \
		${LOCALBASE}/libdata/pkgconfig/pycairo.pc:${PORTSDIR}/graphics/py-cairo \
		${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_SITELIBDIR}/gtk-2.0/vtemodule.so:${PORTSDIR}/x11-toolkits/py-vte \
		${PYXML}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
USE_GNOME=	pygnome2 pygtk2 pygtksourceview
INSTALLS_ICONS=	yes

PYDISTUTILS_PKGNAME=	hotwire

.include <bsd.port.mk>
