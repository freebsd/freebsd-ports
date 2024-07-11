PORTNAME=	chart
PORTVERSION=	${PYQTCHART_VERSION}
PORTREVISION=	3
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	${MASTER_SITES_PYQTCHART}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTCHART_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtChart module
WWW=		https://riverbankcomputing.com/software/pyqtchart

LICENSE=	${PYQT5_LICENSE}

BUILD_DEPENDS=	${PY_SETUPTOOLS}
LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

USES=		gl python pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip:build pyqt5
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		charts core declarative gui qmake:build widgets

PLIST_SUB=      PYQT_CHART_VERSION=${DISTVERSION}

.include <bsd.port.mk>
