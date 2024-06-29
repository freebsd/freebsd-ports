PORTNAME=	chart
DISTVERSION=	${PYQTCHART_VERSION}
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	${MASTER_SITES_PYQTCHART}
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	${PYQTCHART_DISTNAME}

PYQT_DIST=	yes

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt6 toolkit, QtChart module
WWW=		https://riverbankcomputing.com/software/pyqtchart

LICENSE=	${PYQT6_LICENSE}

BUILD_DEPENDS=	${PY_SETUPTOOLS}

USES=		gl pyqt:6 python qt:6
USE_GL=		opengl
USE_PYQT=	sip:build pyqt6 qtbuilder
USE_PYTHON=	concurrent flavors
USE_QT=		base charts

PLIST_SUB=	PYQTCHART_VERSION=${DISTVERSION}

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/PyQt6 \
		-name '*.so*' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
