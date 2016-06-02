# $FreeBSD$

PORTNAME=	plasma-scriptengine-python
PORTVERSION=	${KDE4_WORKSPACE_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${KDE4_VERSION}/src
DISTNAME=	kde-workspace-${PORTVERSION}
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma scriptengine for Python

USE_KDE4=	kdelibs pykde4 automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build
DISTINFO_FILE=	${PORTSDIR}/x11/kde4-workspace/distinfo
USES=		cmake:outsource python:2 tar:xz

CMAKE_SOURCE_PATH=	${WRKSRC}/plasma/generic/scriptengines/python

pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

.include <bsd.port.mk>
