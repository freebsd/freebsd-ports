# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-tk
PORTVERSION=	0.5
CATEGORIES=	x11-toolkits
MASTER_SITES=	https://bitbucket.org/purelang/pure-lang/downloads/
DIST_SUBDIR=	pure

MAINTAINER=	lichray@gmail.com
COMMENT=	Basic interface between Pure and Tcl/Tk

LICENSE=	BSD3CLAUSE

USES=		pkgconfig pure tk:86+

#MAKE_ARGS+=	tclvers=${TCL_VER}

PLIST_FILES=	lib/pure/gnocl.pure \
		lib/pure/tk.so \
		lib/pure/tk.pure

PORTDOCS=	README
PORTEXAMPLES=	*
OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${REINPLACE_CMD} \
		-e "s|pkg-config tcl|pkg-config tk|" \
		-e "s|-ltcl\$$(tclvers)|-ltcl${TCL_SHLIB_VER}|" \
		-e "s|-ltk\$$(tclvers)|-ltk${TK_SHLIB_VER}|" \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
