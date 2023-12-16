PORTNAME=	wxPython
PORTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	42
DIST_SUBDIR=	python

PATCH_SITES=	https://github.com/wxWidgets/Phoenix/commit/
PATCHFILES=	2e9169effa9abf14f34f8436a791b8829eea7774.patch:-p1

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GUI toolkit for the Python programming language
WWW=		https://www.wxpython.org

LICENSE=	WXWINDOWS LGPL21+ GPLv2+
LICENSE_COMB=	multi
LICENSE_NAME_WXWINDOWS=	wxWindows Library Licence, Version 3.1
LICENSE_FILE_WXWINDOWS=	${WRKSRC}/license/licence.txt
LICENSE_PERMS_WXWINDOWS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pathlib2>0:devel/py-pathlib2@${PY_FLAVOR}

USES=		compiler:c++11-lib gl localbase pkgconfig python
USE_GL=		glu
USE_WX=		3.2
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=		NLS

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e "s|WX_CONFIG = 'wx-config'|WX_CONFIG = '${WX_CONFIG}'|" ${WRKSRC}/build.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/wx -name *.so -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
