PORTNAME=	datavis3d
DISTVERSION=	${PYQTDATAVIS3D_VERSION}
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	${MASTER_SITES_PYQTDATAVIS3D}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTDATAVIS3D_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 data visualization library
WWW=		https://riverbankcomputing.com/software/pyqtdatavisualization/

BUILD_DEPENDS=	${PY_SETUPTOOLS}

USES=		gl pyqt:6 python qt:6
USE_GL=		opengl
USE_PYQT=	sip:build pyqt6 qtbuilder:build
USE_PYTHON=	concurrent flavors
USE_QT=		base datavis3d

PLIST_SUB=	PYQTDATAVIS3D_VERSION=${DISTVERSION} \
		PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER} \
		PYTHON_MAJOR_VER_regex=[[:<:]]${PYTHON_MAJOR_VER}[[:>:]]

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
