# $FreeBSD$

PORTNAME=	wxPython
PORTVERSION=	3.0.2.0
PORTREVISION=	4
DISTVERSIONPREFIX=	src-
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/wxpython/wxPython/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	30

MAINTAINER=	python@FreeBSD.org
COMMENT=	GUI toolkit for the Python programming language

DIST_SUBDIR=	python

WRKSRC_SUBDIR=	wxPython

USES=		compiler:c++11-lib python:2.7 shebangfix tar:bzip2
SHEBANG_FILES=	wx/tools/Editra/Editra.pyw

.if defined(WITH_WXVERSION_ONLY)

PKGNAMESUFFIX=	-common

USE_PYTHON=	py3kplist flavors

do-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${PYTHON_SITELIBDIR} -f ${WRKSRC}/wxversion
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d ${PYTHON_SITELIBDIR} -f ${WRKSRC}/wxversion

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/wxversion/wxversion.py* ${STAGEDIR}${PYTHON_SITELIBDIR}/
	${TOUCH} ${STAGEDIR}${PYTHON_SITELIBDIR}/wx.pth

.else

WXPORT=		gtk2
WX_PYTHON_DIR=	wx-${WX_VERSION}-${WXPORT}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wxPython-common>0:x11-toolkits/py-wxPython-common@${FLAVOR}

USES+=		gettext pkgconfig
USE_WX=		3.0
WANT_UNICODE=	yes
USE_PYTHON=	distutils autoplist
PYDISTUTILS_BUILDARGS=	WX_CONFIG="${WX_CONFIG}" \
			WXPORT="${WXPORT}" \
			NO_SCRIPTS=1 \
			INSTALL_MULTIVERSION=1
PYDISTUTILS_CONFIGUREARGS+=	${PYDISTUTILS_BUILDARGS}
PYDISTUTILS_INSTALLARGS+=	${PYDISTUTILS_BUILDARGS}

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,distutils\.command\.install\.install\),setuptools.command.install.install),g' \
		-e 's,distutils\.command\.install$$,setuptools.command.install,g' \
		-e 's,distutils\.command\.install\.install\.,setuptools.command.install.install.,g' \
		${WRKSRC}/config.py

post-install:
	@${ECHO_CMD} "@unexec ${REINPLACE_CMD} -i '' -e '\,${WX_PYTHON_DIR}$$,d' ${PYTHON_SITELIBDIR}/wx.pth 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@exec echo ${WX_PYTHON_DIR} >> ${PYTHON_SITELIBDIR}/wx.pth 2>/dev/null || true" >> ${TMPPLIST}

.endif

.include <bsd.port.mk>
