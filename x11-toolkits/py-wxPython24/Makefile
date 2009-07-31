# New ports collection makefile for:    wxPython
# Date created:         		September 18, 1999
# Whom:					nectar@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	wxPython
PORTVERSION=	2.4.2.4
PORTREVISION=	9
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wxpython
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}Src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python bindings for the wxWidgets/GTK GUI toolkit

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

WRKSRC=		${WRKDIR}/${DISTNAME}/wxPython
NO_LATEST_LINK=	yes

USE_GMAKE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_BUILDARGS=	WX_CONFIG="${WX_CONFIG}"
PYDISTUTILS_NOEGGINFO=	yes
USE_WX=		2.4
DEMO_DIR=	${PYTHONPREFIX_SITELIBDIR}/wxPython/demo

post-extract:
	@${RM} ${WRKSRC}/demo/dllwidget/test_dll.so

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

CONFIGURE_ARGS+=	--enable-gtk2
PYDISTUTILS_BUILDARGS+=	WXPORT=gtk2
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS} ${PYDISTUTILS_BUILDARGS}

.include <bsd.port.post.mk>
