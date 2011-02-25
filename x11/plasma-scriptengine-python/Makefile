# New ports collection makefile for:	plasma-scriptengine-python
# Date created:		2010-03-14
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	plasma-scriptengine-python
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DISTNAME=	kdebase-workspace-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma scriptengine for Python

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	kdeprefix kdelibs automoc4 pykde4
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build
USE_PYTHON=	2.5+
DISTINFO_FILE=	${PORTSDIR}/x11/kdebase4-workspace/distinfo

CMAKE_SOURCE_PATH=	${WRKSRC}/plasma/generic/scriptengines/python
CMAKE_OUTSOURCE=	yes

pre-configure:
	${REINPLACE_CMD} -e 's,$${PYTHON_SITE_PACKAGES_DIR},${PYTHONPREFIX_SITELIBDIR},g' \
		${CMAKE_SOURCE_PATH}/CMakeLists.txt

.include <bsd.port.mk>
