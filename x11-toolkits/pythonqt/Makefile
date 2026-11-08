PORTNAME=	pythonqt
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.0
CATEGORIES=	x11-toolkits devel python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Python binding for Qt Applications
WWW=		https://mevislab.github.io/pythonqt/ \
		https://github.com/mevislab/PythonQt

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime gl python qmake qt:6
USE_QT=		base declarative multimedia positioning svg webchannel webengine tools:build
USE_GL=		gl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	MeVisLab

QMAKE_ARGS=	PYTHON_VERSION=${PYTHON_VER} \
		PYTHON_DIR=${LOCALBASE} \
		QMAKE_CFLAGS="${CFLAGS}" \
		QMAKE_CXXFLAGS="${CXXFLAGS}" \
		INSTALL_PREFIX=${PREFIX}

pre-configure:
	@${ECHO_MSG} "===>	Building PythonQt generator"
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_ARGS} CONFIG+=generator_only ${WRKSRC}/PythonQt.pro
	@${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}
	@${ECHO_MSG} "===>	Generating Qt ${QT6_VERSION} PythonQt wrappers"
	@cd ${WRKSRC} && ${SETENVI} ${WRK_ENV} ${QMAKE_ENV} QTDIR=${QT_INCDIR} ./generator/pythonqt_generator \
		--output-directory=${WRKSRC} \
		--include-paths=/usr/include/c++/v1:/usr/include

.include <bsd.port.mk>
