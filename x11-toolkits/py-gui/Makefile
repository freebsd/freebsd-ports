# Ports collection makefile for:	py-gui
# Date created:			21 June 2004
# Whom:				Hye-Shik Chang
#
# $FreeBSD$

PORTNAME=	gui
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	http://www.cosc.canterbury.ac.nz/~greg/python_gui/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyGUI-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	A cross-platform pythonic GUI API

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Pyrex/Distutils/__init__.py:${PORTSDIR}/devel/pyrex

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_REINPLACE=	yes
USE_GNOME=	pygtk2

DOCSDIR=	share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-extract:
	${RM} -rf ${WRKSRC}/GUI/Mac
	${TOUCH} ${WRKSRC}/GUI/Gtk/__init__.py \
		${WRKSRC}/GUI/Generic/__init__.py

post-patch:
	${REINPLACE_CMD} -e 's/"GUI.Mac",//g' ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCSDIR}
	${TAR} -C ${WRKSRC}/Doc -cf - . | ${TAR} -C ${PREFIX}/${DOCSDIR} -xf -
	${MKDIR} ${PREFIX}/${EXAMPLESDIR}
	${TAR} -C ${WRKSRC}/Demos -cf - . | \
		${TAR} -C ${PREFIX}/${EXAMPLESDIR} -xf -
.endif

.include <bsd.port.mk>
