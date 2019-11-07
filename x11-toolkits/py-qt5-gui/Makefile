# $FreeBSD$

PORTNAME=	gui
CATEGORIES=	x11-toolkits devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtGui module

BUILD_DEPENDS=	${PY_ENUM34}
RUN_DEPENDS=	${PY_ENUM34}

CONFIGURE_ARGS=	--enable QtGui
PYQT_DIST=	yes

USES=		gl python pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip_build core_run
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core gui qmake_build imageformats_run

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtGui API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api

.include <bsd.port.mk>
