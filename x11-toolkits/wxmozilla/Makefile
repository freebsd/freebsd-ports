# ex:ts=8
# Ports collection makefile for:	wxmozilla
# Date created:			Oct 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wxmozilla
PORTVERSION=	0.5.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embedding Mozilla in wxWindows

BUILD_DEPENDS=	${X11BASE}/lib/firebird/lib/pkgconfig/mozilla-nspr.pc:${PORTSDIR}/www/mozilla-firebird \
		${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython
LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_GNOME=	gnomehack
WXGTK_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PKG_CONFIG_PATH="${X11BASE}/lib/firebird/lib/pkgconfig"
CONFIGURE_ARGS=	--with-wx-config=${WXGTK_CONFIG} --enable-python
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
