PORTNAME=	chart
PORTVERSION=	${PYQTCHART_VERSION}
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	${MASTER_SITES_PYQTCHART}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTCHART_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtChart module

LICENSE=	${PYQT5_LICENSE}

LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5

USES=		gl python:3.8+ pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip_build pyqt5
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		charts core declarative gui qmake_build widgets

.include <bsd.port.mk>
