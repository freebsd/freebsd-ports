# $FreeBSD$

PORTNAME=	quickwidgets
CATEGORIES=	x11-toolkits devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtQuickWidgets module

BUILD_DEPENDS=	${PY_ENUM34}
RUN_DEPENDS=	${PY_ENUM34}

USES=		gl python pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip_build core_run gui_run
PYQT_DIST=	yes
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		core declarative gui network widgets \
		qmake_build

CONFIGURE_ARGS=	--enable QtQuickWidgets

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=	API
OPTIONS_SUB=	yes

API_DESC=		Install QtQuick API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.mk>
