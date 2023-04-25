PORTNAME=	pythonqt
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0-27
DISTVERSIONSUFFIX=	-gf52ff96
PORTREVISION=	1
CATEGORIES=	x11-toolkits devel python

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	f9149ea9fefdcd0e9ece092ad44fb4bd0c1b4da9.patch:-p1 # fix install paths by adding INSTALL_PREFIX, https://github.com/MeVisLab/pythonqt/pull/92

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dynamic Python binding for Qt Applications
WWW=		https://mevislab.github.io/pythonqt/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext-runtime gl python:3.6+ qmake qt:5
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
