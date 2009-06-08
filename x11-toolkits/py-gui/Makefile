# Ports collection makefile for:	py-gui
# Date created:			21 June 2004
# Whom:				Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	gui
PORTVERSION=	1.7.2
PORTREVISION=	3
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python_gui/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyGUI-${PORTVERSION}-1

MAINTAINER=	python@FreeBSD.org
COMMENT=	A cross-platform pythonic GUI API

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Pyrex/Distutils/__init__.py:${PORTSDIR}/devel/pyrex

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_GNOME=	pygtk2

PYDISTUTILS_PKGNAME=	PyGUI

DOCSDIR=	share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	share/examples/${PKGNAMEPREFIX}${PORTNAME}

# A workaround for the problem that "make config" doesn't work
# because _OPTIONSFILE is defined before bsd.python.mk is included.
LATEST_LINK=	py-${PORTNAME}

WRKSRC=		${WRKDIR}/PyGUI-${PORTVERSION}

OPTIONS=	GL "Enable GL support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gdkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext
.endif

post-extract:
	${RM} -rf ${WRKSRC}/GUI/Cocoa
	${TOUCH} ${WRKSRC}/GUI/Gtk/__init__.py \
		${WRKSRC}/GUI/Generic/__init__.py

post-patch:
	${REINPLACE_CMD} -e 's/"GUI.Cocoa",//g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCSDIR}
	${TAR} -C ${WRKSRC}/Doc -cf - . | ${TAR} -C ${PREFIX}/${DOCSDIR} -xf -
	${MKDIR} ${PREFIX}/${EXAMPLESDIR}
	${RM} -f ${WRKSRC}/Demos/BlobEdit/.gdb_history \
		 ${WRKSRC}/Demos/BlobEdit/Makefile
	${TAR} -C ${WRKSRC}/Demos -cf - . | \
		${TAR} -C ${PREFIX}/${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.post.mk>
