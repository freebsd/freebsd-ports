# $FreeBSD$

PORTNAME=	plasma-scriptengine-python
PORTVERSION=	${KDE4_WORKSPACE_VERSION}
PORTREVISION=	4
CATEGORIES=	x11 kde kde-applications
DISTNAME=	kde-workspace-${PORTVERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma scriptengine for Python

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

NO_ARCH=	yes
USES=		cmake kde:4 python:2.7 qt:4 tar:xz
USE_KDE=	kdelibs pykde4 automoc4
USE_QT=		qmake_build moc_build uic_build rcc_build
DISTINFO_FILE=	${.CURDIR:H:H}/x11/kde-workspace-kde4/distinfo

KDE_APPLICATIONS_VERSION=	15.08.0

CMAKE_SOURCE_PATH=	${WRKSRC}/plasma/generic/scriptengines/python

pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

.include <bsd.port.mk>
