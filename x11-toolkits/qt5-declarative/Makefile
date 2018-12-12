# $FreeBSD$

PORTNAME=	declarative
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt declarative framework for dynamic user interfaces

USES=		compiler:c++11-lang gl python:build qmake:norecursive \
		qt-dist:5
USE_GL=		gl
USE_QT=		core gui network sql testlib \
		widgets xmlpatterns buildtools_build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

CONFLICTS=	qt5-declarative-render2d-* qt5-qml qt5-quick

QT_DEFINES=	ACCESSIBILITY
QT_CONFIG=	accessibility accessibility-atspi-bridge

post-patch:
# qtdeclarative.pro wants to run python, replace that with PYTHON_CMD
	${REINPLACE_CMD} '/py_out/s#python#${PYTHON_CMD}#g' \
		${WRKSRC}/qtdeclarative.pro
	${REINPLACE_CMD} 's,python,${PYTHON_CMD},g' \
		${WRKSRC}/src/3rdparty/masm/masm.pri

.include <bsd.port.mk>
