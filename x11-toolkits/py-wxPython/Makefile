# New ports collection makefile for:    wxPython
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	py-wxPython
PORTVERSION=	2.3.0
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxpython
DISTNAME=	wxPython-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.ORG

BUILD_DEPENDS=	${PYDISTUTILS}
LIB_DEPENDS=	wx_gtk.2:${PORTSDIR}/x11-toolkits/wxgtk
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

BROKEN=		"requires unstable development version of wxGTK, which isn't here yet"

WX_CONFIG=	${X11BASE}/bin/wx-config

USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_PYTHON=	yes
USE_GTK=	yes
MAKE_ENV=	WX_CONFIG="${WX_CONFIG}"
SETUP_ARGS=	WX_CONFIG="${WX_CONFIG}"
SETUP_CMD=	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup.py \
			${SETUP_ARGS}
DEMO_DIR=	${PYTHON_SITELIBDIR:S/${LOCALBASE}/${PREFIX}/}/wxPython/demo

do-build:
	@${SETUP_CMD} build
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/demo
.if !defined(DEBUG_FLAGS)
	@find ${WRKSRC} -name "*.so" | xargs strip
.endif

do-install:
	@${SETUP_CMD} install
	@${MKDIR} ${DEMO_DIR}
.for glob in *.py *.pyc
	@${INSTALL_DATA} ${WRKSRC}/demo/${glob} ${DEMO_DIR}
.endfor

.include <bsd.port.mk>
