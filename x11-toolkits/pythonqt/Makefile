PORTNAME=	pythonqt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.2
CATEGORIES=	x11-toolkits devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Python binding for Qt Applications
WWW=		https://mevislab.github.io/pythonqt/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime gl python qmake qt:5
USE_QT=		core declarative gui multimedia network opengl printsupport sql svg webkit widgets xml xmlpatterns \
		buildtools:build
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	MeVisLab

QMAKE_ARGS=	PYTHON_VERSION=${PYTHON_VER} \
		PYTHON_DIR=${LOCALBASE} \
		QMAKE_CFLAGS="${CFLAGS}" \
		QMAKE_CXXFLAGS="${CXXFLAGS}" \
		INSTALL_PREFIX=${PREFIX}

.include <bsd.port.mk>
