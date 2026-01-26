PORTNAME=	wxpython
DISTVERSION=	4.2.4
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

PATCH_SITES=	https://github.com/wxWidgets/Phoenix/commit/
PATCHFILES=	afddb14f78b08a576930babd4dc645d8f3f94701.patch:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GUI toolkit for the Python programming language
WWW=		https://www.wxpython.org

LICENSE=	WXWINDOWS LGPL21+ GPLv2+
LICENSE_COMB=	multi
LICENSE_NAME_WXWINDOWS=	wxWindows Library Licence, Version 3.1
LICENSE_FILE_WXWINDOWS=	${WRKSRC}/license/licence.txt
LICENSE_PERMS_WXWINDOWS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.26.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR} \
		${PY_TYPING_EXTENSIONS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>=0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-forked>=0:devel/py-pytest-forked@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinxcontrib-jquery>=0:textproc/py-sphinxcontrib-jquery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4:www/py-beautifulsoup@${PY_FLAVOR} \
		${PY_TYPING_EXTENSIONS} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0:math/py-numpy@${PY_FLAVOR}

USES=		compiler:c++11-lib localbase pkgconfig pyqt:6 python
USE_WX=		3.2
USE_PYQT=	sip:build sip:test
USE_PYTHON=	autoplist cython pep517 pytest

WRKSRC=		${WRKDIR}/wxPython-${DISTVERSION}

# https://github.com/wxWidgets/Phoenix/issues/2819
PEP517_BUILD_CMD=	${LOCALBASE}/bin/pyproject-build-${PYTHON_VER} --no-isolation --wheel ${PEP517_BUILD_CONFIG_SETTING}

OPTIONS_DEFINE=		NLS

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG:T}|g' ${WRKSRC}/build.py
	@${REINPLACE_CMD} -e 's|sip == 6.12.0|sip >= 6.12.0|' ${WRKSRC}/pyproject.toml

post-install:
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/wx -name "*.so" -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
