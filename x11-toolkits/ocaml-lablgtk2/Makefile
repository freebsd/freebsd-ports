PORTNAME=	lablgtk2
PORTVERSION=	2.18.13
PORTREVISION=	4
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Objective Caml interface to GTK 2.x
WWW=		https://garrigue.github.io/lablgtk/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome ocaml:camlp4,findlib,ldconfig,wash pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk20

HAS_CONFIGURE=	yes
ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	garrigue
GH_PROJECT=	lablgtk

PORTSCOUT=	limit:^${PORTVERSION:R:R}

CONFIGURE_ARGS=	--prefix=${PREFIX} --with-libdir=${PREFIX}/${OCAML_LIBDIR} \
		--without-gtksourceview --without-gnomeui \
		--without-panel --without-gnomecanvas
CONFIGURE_ENV=	CAMLP4O="camlp4 pa_o.cmo pa_op.cmo pr_dump.cmo"

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	COPYING README
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES GLADE GTKGLAREA GTKSOURCEVIEW2 GTKSPELL LIBRSVG2
OPTIONS_DEFAULT=	GLADE GTKGLAREA GTKSOURCEVIEW2 GTKSPELL LIBRSVG2
OPTIONS_SUB=	yes

GTKGLAREA_DESC=	GtkGLArea support
GTKSOURCEVIEW2_DESC=	GtkSourceView 2 support
GTKSPELL_DESC=	GtkSpell support

GLADE_CONFIGURE_WITH=glade
GLADE_USE=	GNOME=libglade2
GLADE_VARS=	EXAMPLES_SUBDIRS+=glade

GTKGLAREA_BUILD_DEPENDS=lablgl:graphics/ocaml-lablgl
GTKGLAREA_LIB_DEPENDS=	libgtkgl-2.0.so:x11-toolkits/gtkglarea2
GTKGLAREA_RUN_DEPENDS=	lablgl:graphics/ocaml-lablgl
GTKGLAREA_CONFIGURE_WITH=gl
GTKGLAREA_CONFIGURE_ENV=LABLGLDIR=+site-lib/lablGL
GTKGLAREA_VARS=		EXAMPLES_SUBDIRS+=GL

GTKSOURCEVIEW2_CONFIGURE_WITH=gtksourceview2
GTKSOURCEVIEW2_USE=	GNOME=gtksourceview2
GTKSOURCEVIEW2_VARS=	EXAMPLES_SUBDIRS+=sourceview

GTKSPELL_LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell
GTKSPELL_CONFIGURE_WITH=gtkspell

LIBRSVG2_CONFIGURE_WITH=rsvg
LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_VARS=		EXAMPLES_SUBDIRS+=rsvg

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \
	"*.ml *.png *.rgb *.xpm text ${EXAMPLES_SUBDIRS}" \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
