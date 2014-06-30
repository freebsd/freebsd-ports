# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	gui
PORTVERSION=	1.7.2
PORTREVISION=	7
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python_gui/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyGUI-${PORTVERSION}-1

MAINTAINER=	python@FreeBSD.org
COMMENT=	Cross-platform pythonic GUI API

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Pyrex/Distutils/__init__.py:${PORTSDIR}/devel/pyrex

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_GNOME=	pygtk2

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

# A workaround for the problem that "make config" doesn't work
# because _OPTIONSFILE is defined before bsd.python.mk is included.
LATEST_LINK=	py-${PORTNAME}

WRKSRC=		${WRKDIR}/PyGUI-${PORTVERSION}

OPTIONS_DEFINE=	OPENGL DOCS
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext
.endif

post-extract:
	${RM} -rf ${WRKSRC}/GUI/Cocoa
	${TOUCH} ${WRKSRC}/GUI/Gtk/__init__.py \
		${WRKSRC}/GUI/Generic/__init__.py

post-patch:
	${REINPLACE_CMD} -e 's/"GUI.Cocoa",//g' ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/Doc -cf - . | ${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${RM} -f ${WRKSRC}/Demos/BlobEdit/.gdb_history \
		 ${WRKSRC}/Demos/BlobEdit/Makefile
	${TAR} -C ${WRKSRC}/Demos -cf - . | \
		${TAR} -C ${STAGEDIR}${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.mk>
