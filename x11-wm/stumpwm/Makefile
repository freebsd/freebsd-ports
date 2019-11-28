# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stumpwm
DISTVERSION=	19.11
CATEGORIES=	x11-wm lisp

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Tiling, keyboard driven Window Manager written in Common Lisp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	cl-alexandria>=0:devel/cl-alexandria \
		cl-alexandria-sbcl>=0:devel/cl-alexandria-sbcl \
		cl-clx>=0:x11/cl-clx \
		cl-clx-sbcl>=0:x11/cl-clx-sbcl \
		cl-ppcre>=0:textproc/cl-ppcre \
		cl-ppcre-sbcl>=0:textproc/cl-ppcre-sbcl \
		texinfo>=0:print/texinfo
RUN_DEPENDS=	cl-alexandria>=0:devel/cl-alexandria \
		cl-alexandria-sbcl>=0:devel/cl-alexandria-sbcl \
		cl-clx>=0:x11/cl-clx \
		cl-clx-sbcl>=0:x11/cl-clx-sbcl \
		cl-ppcre>=0:textproc/cl-ppcre \
		cl-ppcre-sbcl>=0:textproc/cl-ppcre-sbcl

USE_GITHUB=	yes
USE_SBCL=	yes

SUB_FILES=	stumpwm
SUB_LIST=	ASDF_REGISTRY=${ASDF_REGISTRY} \
		SBCL=${SBCL}

INFO=		${PORTNAME}
PLIST_SUB=	ASDF_PATHNAME="${ASDF_PATHNAME:S,^${PREFIX}/,,}" \
		ASDF_REGISTRY="${ASDF_REGISTRY:S,^${PREFIX}/,,}"
PORTDOCS=	AUTHORS COPYING HACKING NEWS README.md
PORTEXAMPLES=	sample-stumpwmrc.lisp

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${CP} ${WRKSRC}/load-stumpwm.lisp.in ${WRKSRC}/load-stumpwm.lisp
	@${REINPLACE_CMD} -e 's|@STUMPWM_ASDF_DIR@|${ASDF_PATHNAME}|' \
		${WRKSRC}/load-stumpwm.lisp
	${CP} ${WRKSRC}/make-image.lisp.in ${WRKSRC}/make-image.lisp
	@${REINPLACE_CMD} -e 's|@MODULE_DIR@|${DATADIR}|' \
		${WRKSRC}/make-image.lisp

do-build:
	(cd ${WRKSRC} && \
		CL_SOURCE_REGISTRY="${WRKSRC}" \
		ASDF_OUTPUT_TRANSLATIONS="/:" \
		${SBCL} \
		--eval "(asdf:oos 'asdf:compile-op :${PORTNAME})" \
		--eval "(load \"load-stumpwm.lisp\")" \
		--eval "(load \"manual.lisp\")" \
		--eval "(stumpwm::generate-manual)" \
		--eval "(sb-ext:quit)" && \
		makeinfo stumpwm.texi)

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} \
		${STAGEDIR}${ASDF_REGISTRY} \
		${STAGEDIR}${ASDF_PATHNAME}/sbclfasl
	${INSTALL_SCRIPT} ${WRKDIR}/stumpwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/.dir-locals.el ${WRKSRC}/${PORTNAME}.asd \
		${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/*.fasl ${STAGEDIR}${ASDF_PATHNAME}/sbclfasl
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${RLN} ${STAGEDIR}${ASDF_PATHNAME}/${PORTNAME}.asd \
		${STAGEDIR}${ASDF_REGISTRY}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${STAGEDIR}/${EXAMPLESDIR}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
