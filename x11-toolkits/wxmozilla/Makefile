# ex:ts=8
# Ports collection makefile for:	wxmozilla
# Date created:			Oct 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wxmozilla
PORTVERSION=	0.5.3
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Embedding Mozilla in wxWidgets

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/mozilla-nspr.pc:${PORTSDIR}/www/mozilla \
		${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24
LIB_DEPENDS=	wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_GNOME=	gnomehack gnometarget
WXGTK_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-wx-config=${WXGTK_CONFIG} --enable-python
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	"Does not build on 4.X"
.endif

.include <bsd.port.post.mk>
