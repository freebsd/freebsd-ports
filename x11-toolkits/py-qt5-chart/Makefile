PORTNAME=	chart
DISTVERSION=	${PYQTCHART_VERSION}
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	${MASTER_SITES_PYQTCHART}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTCHART_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtChart module
WWW=		https://riverbankcomputing.com/software/pyqtchart

LICENSE=	${PYQT5_LICENSE}

USES=		gl pyqt:5,dist python qt:5
USE_GL=		gl
USE_PYQT=	pyqt5 qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		charts core declarative gui qmake:build widgets

PLIST_SUB=      PYQT_CHART_VERSION=${DISTVERSION}

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
