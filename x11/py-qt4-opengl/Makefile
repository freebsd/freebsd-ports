# Created by: Danny Pansters <danny@ricin.com>
# $FreeBSD$

PORTNAME=	opengl
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	x11 devel python

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt4 toolkit, QtOpenGL module

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

CONFIGURE_ARGS=	--enable QtOpenGL
PYQT_DIST=	yes

USES=		python pyqt:4 qt:4
USE_GL=		gl
USE_PYQT=	sip_build core_run gui_run
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		corelib gui opengl moc_build qmake_build

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtOpenGL API for QScintilla2
API_CONFIGURE_ON=	--qsci-api --qsci-api-destdir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt4.so:devel/qscintilla2
DEBUG_CONFIGURE_ON=	--debug --trace

.include <bsd.port.mk>
