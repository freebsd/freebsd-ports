PORTNAME=	tkinter
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	7
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${DISTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings to the Tk widget set (Python ${PYTHON_VER})

LICENSE=	PSFL

PORTSCOUT=	ignore:1

USES=		compiler:c11 python:2.7+ tar:xz tk
USE_PYTHON=	distutils autoplist allflavors

DIST_SUBDIR=	python
DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo
WRKSRC_SUBDIR=	Modules

PYDISTUTILS_INSTALLARGS+=	--install-lib ${PYTHON_LIBDIR}/lib-dynload

.include <bsd.port.pre.mk>

post-extract:
.if ${PYTHON_REL} < 30000
	@${SED} -e "s|%%TK_VER%%|${TK_VER}|" ${FILESDIR}/setup.py > ${WRKSRC}/setup.py
.else
	@${SED} -e "s|%%TK_VER%%|${TK_VER}|" ${FILESDIR}/setup3.py > ${WRKSRC}/setup.py
.endif

post-install:
#	${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/lib-dynload/_tkinter.cpython-${PYTHON_SUFFIX}.so
	${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/lib-dynload/_tkinter*.so

.include <bsd.port.post.mk>
