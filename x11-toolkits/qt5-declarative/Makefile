PORTNAME=	declarative
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces
WWW=		https://qt-project.org

USES=		compiler:c++11-lang gl perl5 python:build qmake:norecursive \
		qt-dist:5
USE_GL=		gl
USE_PERL5=	build
USE_QT=		core gui network sql widgets \
		buildtools:build

CONFLICTS=	qt5-declarative-render2d-* qt5-qml qt5-quick

BINARY_ALIAS=	python=${PYTHON_CMD}

QT_BINARIES=	yes
QT_DEFINES=	ACCESSIBILITY
QT_CONFIG=	accessibility accessibility-atspi-bridge

OPTIONS_DEFINE= QML_DEBUG
OPTIONS_SUB=	yes
QML_DEBUG_DESC=	qml debugging

TOOLS=		qml qmlcachegen qmleasing qmlformat qmlimportscanner qmllint qmlmin \
		qmlplugindump qmlpreview qmlprofiler qmlscene qmltyperegistrar

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MQML_DEBUG}
QMAKE_CONFIGURE_ARGS+=	-no-qml-debug
.endif

post-patch:
# qtdeclarative.pro wants to run python, replace that with PYTHON_CMD
	${REINPLACE_CMD} '/py_out/s#python#${PYTHON_CMD}#g' \
		${WRKSRC}/qtdeclarative.pro
	${REINPLACE_CMD} 's,python,${PYTHON_CMD},g' \
		${WRKSRC}/src/3rdparty/masm/masm.pri

.include <bsd.port.post.mk>
