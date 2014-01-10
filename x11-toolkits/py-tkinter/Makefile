# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkinter
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	4
CATEGORIES=	x11-toolkits python
MASTER_SITES=	${PYTHON_MASTER_SITES}
MASTER_SITE_SUBDIR=	${PYTHON_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PYTHON_DISTFILE}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings to the Tk widget set

PORTSCOUT=	ignore:1

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_XZ=		yes
USES=		tk

DIST_SUBDIR=	python
DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo
WRKSRC=		${PYTHON_WRKSRC}/Modules

PYDISTUTILS_INSTALLARGS+=	--install-lib ${PYTHON_LIBDIR}/lib-dynload
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

post-extract:
.if ${PYTHON_REL} < 300
	@${SED} -e "s|%%TK_VER%%|${TK_VER}|" ${FILESDIR}/setup.py > ${WRKSRC}/setup.py
.else
	@${SED} -e "s|%%TK_VER%%|${TK_VER}|" ${FILESDIR}/setup3.py > ${WRKSRC}/setup.py
.endif

.include <bsd.port.post.mk>
