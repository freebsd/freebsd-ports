# New ports collection makefile for:    wxPython
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxPython
PORTVERSION=	2.6.0.0
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxpython
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Python bindings for the wxWidgets/GTK GUI toolkit

LIB_DEPENDS=	wx_gtk2_core-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26 \
		wx_gtk2_gizmos-2.6.0:${PORTSDIR}/x11-toolkits/wxgtk26-contrib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

WRKSRC=		${WRKDIR}/${DISTNAME}/wxPython

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_BUILDARGS=	WX_CONFIG="${WX_CONFIG}"
PYDISTUTILS_CONFIGUREARGS+=	WX_CONFIG="${WX_CONFIG}"
DEMO_DIR=	${PYTHONPREFIX_SITELIBDIR}/wxPython/demo

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PYTHON_SITELIBDIR%%/wx-2.6.0-gtk2-ansi/wx/

post-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/demo
.if !defined(DEBUG_FLAGS)
	@${FIND} ${WRKSRC} -name "*.so" | ${XARGS} ${STRIP_CMD}
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

.include <bsd.port.pre.mk>

WX_CONFIG=	${X11BASE}/bin/wxgtk2-2.6-config

CONFIGURE_ARGS+=	--enable-gtk2
PYDISTUTILS_BUILDARGS+=	WXPORT=gtk2
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS} ${PYDISTUTILS_BUILDARGS}

.include <bsd.port.post.mk>
