PORTNAME=	datavis3d
DISTVERSION=	${PYQTDATAVIS3D_VERSION}
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	${MASTER_SITES_PYQTDATAVIS3D}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTDATAVIS3D_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, DataVisualization module
WWW=		https://www.riverbankcomputing.com/software/pyqtdatavisualization/

LICENSE=	${PYQT5_LICENSE}

USES=		gl python pyqt:5,dist qt:5
USE_GL=		gl
USE_PYQT=	pyqt5 qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		core datavis3d declarative gui widgets \
		qmake:build

PLIST_SUB=      PYQT_DATAVIS3D_VERSION=${DISTVERSION} \
		PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER} \
		PYTHON_MAJOR_VER_regex=[[:<:]]${PYTHON_MAJOR_VER}[[:>:]]

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
