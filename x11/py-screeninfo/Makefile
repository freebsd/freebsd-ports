PORTNAME=	screeninfo
DISTVERSION=	0.8.1
CATEGORIES=	x11
MASTER_SITES=	PYPI # no tests on PYPI, but GitHub tarball doesn't bui;d
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fetch location and size of physical screens
WWW=		https://github.com/rr-/screeninfo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

.include <bsd.port.mk>
