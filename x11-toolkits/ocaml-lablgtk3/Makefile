PORTNAME=	lablgtk3
PORTVERSION=	3.1.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Objective Caml interface to GTK 3.x
WWW=		https://garrigue.github.io/lablgtk/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dune:devel/ocaml-dune \
		ocaml-cairo>0:graphics/ocaml-cairo
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	ocaml-cairo>0:graphics/ocaml-cairo

USES=		gmake gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_LDCONFIG=	yes

TARGETS=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	garrigue
GH_PROJECT=	lablgtk

PORTSCOUT=	limit:^${PORTVERSION:R:R}

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES GTKSOURCEVIEW3 GTKSPELL
OPTIONS_DEFAULT=	GTKSOURCEVIEW3 GTKSPELL
OPTIONS_SUB=		yes

GTKSOURCEVIEW3_DESC=	GtkSourceView 3 support
GTKSPELL_DESC=		GtkSpell support

GTKSOURCEVIEW3_USE=	GNOME=gtksourceview3
GTKSOURCEVIEW3_VARS=    TARGETS+=lablgtk3-sourceview3 EXAMPLES_SUBDIRS+=sourceview

GTKSPELL_LIB_DEPENDS=	libgtkspell3-3.so:textproc/gtkspell3 \
			libenchant-2.so:textproc/enchant2
GTKSPELL_VARS=		TARGETS+=lablgtk3-gtkspell3

do-build:
	cd ${BUILD_WRKSRC} && dune build --verbose -p ${TARGETS:ts,} -j ${MAKE_JOBS_NUMBER}

do-install:
	cd ${INSTALL_WRKSRC} && dune install --destdir=${STAGEDIR} \
		--libdir=${PREFIX}/${OCAML_SITELIBDIR} ${TARGETS}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \
	"*.ml *.png *.rgb *.xpm text ${EXAMPLES_SUBDIRS}" \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
