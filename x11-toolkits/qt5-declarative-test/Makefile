PORTNAME=	declarative-test
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interface (testing)

USES=		compiler:c++11-lang gl python:build qmake:norecursive \
		qt-dist:5,declarative
USE_GL=		gl
USE_QT=		core declarative gui network sql testlib widgets \
		buildtools_build

CONFLICTS=	qt5-declarative-render2d-* qt5-qml qt5-quick

BINARY_ALIAS=	python=${PYTHON_CMD}

QT_BINARIES=	yes
TOOLS=		qmltestrunner

post-patch:
# qtdeclarative.pro wants to run python, replace that with PYTHON_CMD
	${REINPLACE_CMD} '/py_out/s#python#${PYTHON_CMD}#g' \
		${WRKSRC}/qtdeclarative.pro
	${REINPLACE_CMD} 's,python,${PYTHON_CMD},g' \
		${WRKSRC}/src/3rdparty/masm/masm.pri

.include <bsd.port.mk>
