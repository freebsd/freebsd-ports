PORTNAME=	graphs
DISTVERSION=	${PYQTGRAPHS_VERSION}
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	${MASTER_SITES_PYQTGRAPHS}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTGRAPHS_DISTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtGraphs module
WWW=		https://riverbankcomputing.com/software/pyqtgraphs

LICENSE=	${PYQT6_LICENSE}

USES=		gl pyqt:6,dist python qt:6
USE_GL=		opengl
USE_PYQT=	pyqt6 qtbuilder:build sip:build
USE_PYTHON=	concurrent flavors
USE_QT=		base declarative graphs quick3d shadertools

PLIST_SUB=	PYQTGRAPHS_VERSION=${DISTVERSION} \
		PYTHON_MAJOR_VER=${PYTHON_MAJOR_VER} \
		PYTHON_MAJOR_VER_regex=[[:<:]]${PYTHON_MAJOR_VER}[[:>:]]

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
