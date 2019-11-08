# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	gui
PORTVERSION=	1.7.2
PORTREVISION=	8
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python_gui/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyGUI-${PORTVERSION}-1

MAINTAINER=	python@FreeBSD.org
COMMENT=	Cross-platform pythonic GUI API

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyrex>0:devel/pyrex@${PY_FLAVOR}

OPTIONS_DEFINE=	DOCS EXAMPLES OPENGL

USE_GNOME=	pygtk2
USES=		gnome python:2.7
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
WRKSRC=		${WRKDIR}/PyGUI-${PORTVERSION}

OPENGL_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:x11-toolkits/py-gtkglext@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|"GUI.Cocoa",||g' ${WRKSRC}/setup.py
	@${TOUCH} ${WRKSRC}/GUI/Generic/__init__.py ${WRKSRC}/GUI/Gtk/__init__.py
	@${RM} -r ${WRKSRC}/Demos/BlobEdit/.gdb_history ${WRKSRC}/Demos/BlobEdit/Makefile ${WRKSRC}/GUI/Cocoa

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/Demos/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
