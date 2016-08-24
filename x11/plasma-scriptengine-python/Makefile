# $FreeBSD$

PORTNAME=	plasma-scriptengine-python
PORTVERSION=	${KDE4_WORKSPACE_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/${KDE4_APPLICATIONS_BRANCH}/applications/${KDE4_APPLICATIONS_VERSION}/src
DISTNAME=	kde-workspace-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma scriptengine for Python

USES=		cmake:outsource kde:4 python:2 tar:xz
USE_KDE=	kdelibs pykde4 automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build
DISTINFO_FILE=	${.CURDIR:H:H}/x11/kde4-workspace/distinfo

CMAKE_SOURCE_PATH=	${WRKSRC}/plasma/generic/scriptengines/python

pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

.include <bsd.port.mk>
