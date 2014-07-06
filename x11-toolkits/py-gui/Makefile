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

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Pyrex/Distutils/__init__.py:${PORTSDIR}/devel/pyrex

OPTIONS_DEFINE=	DOCS EXAMPLES OPENGL
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
WRKSRC=		${WRKDIR}/PyGUI-${PORTVERSION}

OPENGL_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext

post-patch:
	@${REINPLACE_CMD} -e 's|"GUI.Cocoa",||g' ${WRKSRC}/setup.py
	@${TOUCH} ${WRKSRC}/GUI/Generic/__init__.py ${WRKSRC}/GUI/Gtk/__init__.py
	@${RM} -fr ${WRKSRC}/Demos/BlobEdit/.gdb_history ${WRKSRC}/Demos/BlobEdit/Makefile ${WRKSRC}/GUI/Cocoa

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/Demos/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
