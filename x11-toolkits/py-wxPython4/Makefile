PORTNAME=	wxPython
PORTVERSION=	4.2.3
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	42
DIST_SUBDIR=	python

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GUI toolkit for the Python programming language
WWW=		https://www.wxpython.org

LICENSE=	WXWINDOWS LGPL21+ GPLv2+
LICENSE_COMB=	multi
LICENSE_NAME_WXWINDOWS=	wxWindows Library Licence, Version 3.1
LICENSE_FILE_WXWINDOWS=	${WRKSRC}/license/licence.txt
LICENSE_PERMS_WXWINDOWS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pathlib2>0:devel/py-pathlib2@${PY_FLAVOR} \
								${PKGNAMEPREFIX}requests>=2.28.1:www/py-requests@${PY_FLAVOR} \
								${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
								${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=		${PKGNAMEPREFIX}requests>=2.28.1:www/py-requests@${PY_FLAVOR}

USES=		compiler:c++11-lib gl localbase pkgconfig python
USE_GL=		glu
USE_WX=		3.2
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		NLS

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e "s|WX_CONFIG = 'wx-config'|WX_CONFIG = '${WX_CONFIG}'|" ${WRKSRC}/build.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/wx -name *.so -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
