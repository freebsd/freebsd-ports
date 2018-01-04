# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pmw
PORTVERSION=	1.3.2
PORTREVISION=	4
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTNAME}.${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	High-level compound graphics widgets for Python

OPTIONS_DEFINE=	DOCS EXAMPLES
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${FLAVOR}
LIB_DEPENDS=	libBLT25.so:x11-toolkits/blt

USES=		python:2.7 shebangfix
USE_PYTHON=	distutils
SHEBANG_FILES=	Pmw/Pmw_1_3/bin/bundlepmw.py

WRKSRC=		${WRKDIR}/${DISTNAME}/src
PMWVERSION=	${DISTNAME:R:S/./_/g}
PLIST_SUB=	PMWVERSION="${PMWVERSION}"

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}/bin; ${PAX} -rw . ${STAGEDIR}${DATADIR})
	@(cd ${WRKSRC}/Pmw/${PMWVERSION}/doc; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.for d in  contrib demos
	@(cd ${WRKSRC}/Pmw/${PMWVERSION};  ${COPYTREE_SHARE} $d ${STAGEDIR}${EXAMPLESDIR})
.endfor

.include <bsd.port.mk>
