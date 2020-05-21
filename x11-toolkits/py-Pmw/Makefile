# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Pmw
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fmysh@iijmio-mail.jp
COMMENT=	High-level compound graphics widgets for Python

LIB_DEPENDS=	libBLT25.so:x11-toolkits/blt
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter@${PY_FLAVOR}

USES=		dos2unix python shebangfix
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes
SHEBANG_FILES=	Pmw/Pmw_*/bin/bundlepmw.py

PLIST_SUB=	PMWVERSION=${PMWVERSION}

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3000
PMWVERSION=	Pmw_1_3_3
.else
PMWVERSION=	Pmw_2_0_1
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/Pmw/${PMWVERSION}/bin && ${PAX} -rw . ${STAGEDIR}${DATADIR})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/Pmw/${PMWVERSION}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/Pmw/${PMWVERSION} && ${COPYTREE_SHARE} contrib ${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC}/Pmw/${PMWVERSION} && ${COPYTREE_SHARE} demos ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
