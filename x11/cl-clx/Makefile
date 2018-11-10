# $FreeBSD$

PORTNAME=	clx
DISTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	x11 lisp
PKGNAMEPREFIX=	cl-

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	X11 client library for Common Lisp

LICENSE=	MIT

USES=		tar:tgz

USES+=		makeinfo
USE_ASDF=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	sharplispers

INFO=		clx
PLIST_SUB=	ASDF_PATHNAME="${ASDF_PATHNAME:S,^${PREFIX}/,,}" \
		ASDF_REGISTRY="${ASDF_REGISTRY:S,^${PREFIX}/,,}"
PORTDOCS=	CHANGES NEWS README-R5 README.md exclMakefile exclREADME

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC}/manual && makeinfo --no-split clx.texinfo)

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} \
		${STAGEDIR}${ASDF_PATHNAME}/debug \
		${STAGEDIR}${ASDF_PATHNAME}/demo \
		${STAGEDIR}${ASDF_PATHNAME}/extensions \
		${STAGEDIR}${ASDF_PATHNAME}/manual \
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
	${RLN} ${STAGEDIR}${ASDF_PATHNAME}/clx.asd ${STAGEDIR}${ASDF_REGISTRY}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
