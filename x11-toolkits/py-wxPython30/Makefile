# $FreeBSD$

PORTNAME=	wxPython
PORTVERSION=	3.0.0.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/wxpython/wxPython/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	30
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	GUI toolkit for the Python programming language

DIST_SUBDIR=	python

WRKSRC=		${WRKDIR}/${DISTNAME}/wxPython

USES=		tar:bzip2
USE_PYTHON=	yes

.if defined(WITH_WXVERSION_ONLY)

PKGNAMESUFFIX=	-common

PYTHON_PY3K_PLIST_HACK=	yes

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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wxPython-common>0:${PORTSDIR}/x11-toolkits/py-wxPython-common

USES+=		gettext pkgconfig
USE_WX=	3.0
WANT_UNICODE=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_BUILDARGS=	WX_CONFIG="${WX_CONFIG}" \
			WXPORT="${WXPORT}" \
			NO_HEADERS=1 \
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
