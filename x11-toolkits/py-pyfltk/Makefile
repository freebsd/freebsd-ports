PORTNAME=	pyfltk
PORTVERSION=	1.4.5.0
CATEGORIES=	x11-toolkits python
MASTER_SITES=	SF/pyfltk/pyfltk/pyfltk-${PORTVERSION:R} PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to FLTK window toolkit
WWW=		https://pyfltk.sourceforge.io/ \
		https://fltk.gitlab.io/fltk/ \
		https://gitlab.com/fltk/fltk

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:devel/swig ${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		python shebangfix xorg
USE_PYTHON=	autoplist concurrent pep517
USE_XORG=	x11

CFLAGS+=	-DFL_LIBRARY
PYDISTUTILS_CONFIGUREARGS=	swig

PORTDOCS=	CHANGES README.md
PORTEXAMPLES=	*.py HelpDialog.html

SHEBANG_FILES=	fltk/test/TextEditor.py fltk/test/editor.py \
		fltk/test/fltk_threads.py fltk/test/tree.py \
		fltk/test/tree_demo.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "/license = /s,'.*',{ text = & }," \
		${WRKSRC}/pyproject.toml

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/fltk/test/,} \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
