PORTNAME=	wxPython
PORTVERSION=	4.1.1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	41
DIST_SUBDIR=	python

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	GUI toolkit for the Python programming language

LICENSE=	WXWINDOWS LGPL21+ GPLv2+
LICENSE_COMB=	multi
LICENSE_NAME_WXWINDOWS=	wxWindows Library Licence, Version 3.1
LICENSE_FILE_WXWINDOWS=	${WRKSRC}/license/licence.txt
LICENSE_PERMS_WXWINDOWS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pathlib2>0:devel/py-pathlib2@${PY_FLAVOR}

USES=		compiler:c++11-lib gl localbase pkgconfig python:3.6+
USE_GL=		glu
USE_WX=		3.1
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=		NLS

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} -e "s|WX_CONFIG = 'wx-config'|WX_CONFIG = '${WX_CONFIG}'|" ${WRKSRC}/build.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/wx -name *.so -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
