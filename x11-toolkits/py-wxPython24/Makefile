# New ports collection makefile for:    wxPython
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxPython
PORTVERSION=	2.3.2.1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxpython
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sobomax@FreeBSD.ORG

LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk-devel
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

WX_CONFIG=	${X11BASE}/bin/wx-config

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
MAKE_ENV=	WX_CONFIG="${WX_CONFIG}"
DEMO_DIR=	${PYTHONPREFIX_SITELIBDIR}/wxPython/demo

post-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/demo
.if !defined(DEBUG_FLAGS)
	@find ${WRKSRC} -name "*.so" | xargs strip
.endif

post-install:
	@${MKDIR} ${DEMO_DIR}
.for glob in *.py *.pyc
	@${INSTALL_DATA} ${WRKSRC}/demo/${glob} ${DEMO_DIR}
.endfor
.for dir in bitmaps bmp_source data
	@${MKDIR} ${DEMO_DIR}/${dir}
.for glob in *
	@${INSTALL_DATA} ${WRKSRC}/demo/${dir}/${glob} ${DEMO_DIR}/${dir}
.endfor
.endfor

.include <bsd.port.mk>
