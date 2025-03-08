PORTNAME=	pyfltk
PORTVERSION=	1.3.9
PORTREVISION=	2
CATEGORIES=	x11-toolkits python
MASTER_SITES=	PYPI \
		SF/pyfltk/pyfltk/pyFltk-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyFltk-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python interface to FLTK window toolkit
WWW=		https://pyfltk.sourceforge.io/ \
		https://fltk.gitlab.io/fltk/ \
		https://gitlab.com/fltk/fltk

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		python shebangfix xorg
USE_PYTHON=	autoplist concurrent distutils
USE_XORG=	x11

CFLAGS+=	-DFL_LIBRARY
PYDISTUTILS_CONFIGUREARGS=	swig

PORTDOCS=	*
PORTEXAMPLES=	*

SHEBANG_FILES=	fltk/test/tree.py \
		fltk/test/tree_demo.py \
		fltk/test/fltk_threads.py

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/^%include fl_types/,+1 \
		s|Enumerations|Fl_Export|' ${WRKSRC}/swig/fltk.i

post-build:
	${REINPLACE_CMD} -e "s|\.\./docs|${DOCSDIR}/html|g" ${WRKSRC}/fltk/test/help.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html/
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES README.md ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/fltk/docs/ && ${INSTALL_DATA} *.html *.jpg ${STAGEDIR}${DOCSDIR}/html/

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/fltk/test/ && ${INSTALL_DATA} *.py HelpDialog.html ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
