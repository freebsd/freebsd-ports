# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkinter
PORTVERSION=	${PYTHON_PORTVERSION}
PORTREVISION=	5
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYTHON
MASTER_SITE_SUBDIR=	ftp/python/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python bindings to the Tk widget set

LICENSE=	PSFL

PORTSCOUT=	ignore:1

USE_PYTHON=	distutils autoplist
USES=		python tar:xz tk

DIST_SUBDIR=	python
DISTINFO_FILE=	${PORTSDIR}/lang/python${PYTHON_SUFFIX}/distinfo
WRKSRC=		${WRKDIR}/Python-${PORTVERSION}/Modules

PYDISTUTILS_INSTALLARGS+=	--install-lib ${PYTHON_LIBDIR}/lib-dynload

.include <bsd.port.pre.mk>

post-extract:
.if ${PYTHON_REL} < 300
	@${SED} -e "s|%%TK_VER%%|${TK_VER}|" ${FILESDIR}/setup.py > ${WRKSRC}/setup.py
.else
	@${SED} -e "s|%%TK_VER%%|${TK_VER}|" ${FILESDIR}/setup3.py > ${WRKSRC}/setup.py
.endif

.include <bsd.port.post.mk>
