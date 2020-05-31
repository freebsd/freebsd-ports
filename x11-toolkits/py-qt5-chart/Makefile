# $FreeBSD$

PORTNAME=	chart
PORTVERSION=	${PYQT5_VERSION}
CATEGORIES=	x11-toolkits devel python
MASTER_SITES=	RIVERBANK/PyQtChart/${PYQT5_VERSION}/
PKGNAMEPREFIX=	${PYQT_PY_RELNAME}-
DISTNAME=	PyQtChart-${PYQT5_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Python bindings for the Qt5 toolkit, QtChart module

LICENSE=	${PYQT5_LICENSE}

BUILD_DEPENDS=	${PY_ENUM34}
RUN_DEPENDS=	${PY_ENUM34}

USES=		gl python pyqt:5 qt:5
USE_GL=		gl
USE_PYQT=	sip_build core gui widgets
USE_PYTHON=	concurrent flavors py3kplist
USE_QT=		charts core declarative gui qmake_build widgets

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --verbose --no-dist-info \
		-d ${PYTHONPREFIX_SITELIBDIR}/PyQt5 \
		-q ${QMAKE} \
		--sip ${SIP} \
		--pyqt-sipdir=${PYQT_SIPDIR} \
		--qtchart-sipdir=${PYQT_SIPDIR}
DESTDIRNAME=	INSTALL_ROOT

OPTIONS_DEFINE=	API DEBUG
OPTIONS_DEFAULT=API
OPTIONS_SUB=	yes

API_DESC=		Install QtCharts API for QScintilla2
API_CONFIGURE_ON=	--apidir=${PYQT_APIDIR}
API_CONFIGURE_OFF=	--no-qsci-api
API_LIB_DEPENDS=	libqscintilla2_qt5.so:devel/qscintilla2-qt5
DEBUG_CONFIGURE_ON=	--debug --trace

.if !target(do-configure)
do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${PYTHON_CMD} configure.py ${CONFIGURE_ARGS}
.endif  # !target(do-configure)

.include <bsd.port.mk>
