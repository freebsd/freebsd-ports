PORTNAME=	tkinter
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	11
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings to the Tk widget set (Python ${PYTHON_VER})

LICENSE=	PSFL
LICENSE_FILE=	${WRKDIR}/Python-${DISTVERSION}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		compiler:c11 python tar:xz tk:86 xorg
USE_PYTHON=	allflavors autoplist pep517
USE_XORG=	x11

DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_BASESUFFIX}/distinfo
WRKSRC_SUBDIR=	Modules

SUB_LIST+=	DISTVERSION=${DISTVERSION} \
		TK_VER=${TK_VER}
SUB_FILES=	pyproject.toml \
		setup.py
PLIST_FILES=	${PYTHONPREFIX_LIBDIR:S;${PREFIX}/;;}/lib-dynload/_tkinter${PYTHON_SOABI}.so

PORTSCOUT=	ignore:1

pre-configure:
	@${MV} ${WRKDIR}/pyproject.toml ${WRKSRC}
	@${MV} ${WRKDIR}/setup.py ${WRKSRC}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_tkinter${PYTHON_SOABI}.so
	# lib-dynload is the expected location
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_LIBDIR}/lib-dynload
	@(cd ${STAGEDIR}${PYTHONPREFIX_LIBDIR}/lib-dynload && ${LN} -s ../site-packages/_tkinter${PYTHON_SOABI}.so)

do-test:
	@${PYTHON_CMD} -c 'import tkinter' # minimal smoke test

.include <bsd.port.mk>
