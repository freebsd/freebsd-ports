PORTNAME=	clx
DISTVERSION=	0.7.7
CATEGORIES=	x11 lisp
PKGNAMEPREFIX=	cl-

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	X11 client library for Common Lisp
WWW=		https://www.cliki.net/CLX

LICENSE=	MIT

USES=		cl makeinfo tar:tgz
USE_GITHUB=	yes
GH_ACCOUNT=	sharplispers

INFO=		clx
PLIST_SUB=	ASDF_PATHNAME="${ASDF_PATHNAME:S,^${PREFIX}/,,}" \
		ASDF_REGISTRY="${ASDF_REGISTRY:S,^${PREFIX}/,,}"
PORTDOCS=	CHANGES NEWS README-R5 README.md exclREADME

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC}/manual && makeinfo --no-split clx.texinfo)

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} \
		${STAGEDIR}${ASDF_PATHNAME}/debug \
		${STAGEDIR}${ASDF_PATHNAME}/demo \
		${STAGEDIR}${ASDF_PATHNAME}/extensions \
		${STAGEDIR}${ASDF_PATHNAME}/manual \
		${STAGEDIR}${ASDF_PATHNAME}/tests \
		${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.asd ${WRKSRC}/*.c \
		${WRKSRC}/*.lisp ${WRKSRC}/exclMakefile \
		${STAGEDIR}${ASDF_PATHNAME}
	(cd ${WRKSRC}/debug && ${COPYTREE_SHARE} . \
		${STAGEDIR}${ASDF_PATHNAME}/debug)
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . \
		${STAGEDIR}${ASDF_PATHNAME}/demo)
	(cd ${WRKSRC}/extensions && ${COPYTREE_SHARE} . \
		${STAGEDIR}${ASDF_PATHNAME}/extensions)
	(cd ${WRKSRC}/manual && ${COPYTREE_SHARE} . \
		${STAGEDIR}${ASDF_PATHNAME}/manual "! -name *.info")
	${INSTALL_DATA} ${WRKSRC}/manual/*.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	(cd ${WRKSRC}/tests && ${COPYTREE_SHARE} . \
		${STAGEDIR}${ASDF_PATHNAME}/tests)
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/clx.asd ${STAGEDIR}${ASDF_REGISTRY}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
