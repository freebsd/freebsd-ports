# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lablgtk2
PORTVERSION=	2.18.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/1479/ \
		LOCAL/bf
PKGNAMEPREFIX=	ocaml-
DISTNAME=	lablgtk-${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Objective Caml interface to GTK+ 2.x

LICENSE=	LGPL21

USES=		gmake pkgconfig
USE_GNOME=	gtk20
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_WASH= 	yes

OPTIONS_DEFINE=		GLADE GNOMECANVAS GNOMEUI GTKGLAREA GTKSOURCEVIEW2 \
			GTKSPELL LIBRSVG2 DOCS EXAMPLES
OPTIONS_DEFAULT=	GLADE GNOMECANVAS GNOMEUI GTKGLAREA GTKSOURCEVIEW2 \
			GTKSPELL LIBRSVG2

GNOMECANVAS_DESC=	GnomeCanvas support
GNOMEUI_DESC=		GNOME 2 UI support
GTKGLAREA_DESC=		GtkGLArea support
GTKSOURCEVIEW2_DESC=	GtkSourceView 2 support
GTKSPELL_DESC=		GtkSpell support
#GNOMEPANEL_DESC=	GNOME Panel support

HAS_CONFIGURE=	yes
ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --with-libdir=${PREFIX}/${OCAML_LIBDIR} \
		--without-gtksourceview
CONFIGURE_ENV=	CAMLP4O="camlp4 pa_o.cmo pa_op.cmo pr_dump.cmo"

PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)cp([[:space:]]

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	COPYING README
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
PORTEXAMPLES=	*
.endif

.if ${PORT_OPTIONS:MGTKGLAREA}
CONFIGURE_ARGS+=	--with-gl
BUILD_DEPENDS+=	lablgl:graphics/ocaml-lablgl
RUN_DEPENDS+=	lablgl:graphics/ocaml-lablgl
LIB_DEPENDS+=	libgtkgl-2.0.so:x11-toolkits/gtkglarea2
EXAMPLES_SUBDIRS+=	GL
.else
CONFIGURE_ARGS+=	--without-gl
.endif

.if ${PORT_OPTIONS:MGLADE}
CONFIGURE_ARGS+=	--with-glade
USE_GNOME+=	libglade2
PLIST_SUB+=	GLADE=""
EXAMPLES_SUBDIRS+=	glade
.else
CONFIGURE_ARGS+=	--without-glade
PLIST_SUB+=	GLADE="@comment "
.endif

.if ${PORT_OPTIONS:MGNOMEUI}
CONFIGURE_ARGS+=	--with-gnomeui
USE_GNOME+=	libgnomeui
.else
CONFIGURE_ARGS+=	--without-gnomeui
.endif

.if ${PORT_OPTIONS:MGNOMECANVAS}
CONFIGURE_ARGS+=	--with-gnomecanvas
USE_GNOME+=	libgnomecanvas
EXAMPLES_SUBDIRS+=	canvas
.else
CONFIGURE_ARGS+=	--without-gnomecanvas
.endif

.if ${PORT_OPTIONS:MLIBRSVG2}
CONFIGURE_ARGS+=	--with-rsvg
USE_GNOME+=	librsvg2
EXAMPLES_SUBDIRS+=	rsvg
.else
CONFIGURE_ARGS+=	--without-rsvg
.endif

#.if ${PORT_OPTIONS:MGNOMEPANEL}
#CONFIGURE_ARGS+=	--with-panel
#USE_GNOME+=	gnomepanel
#EXAMPLES_SUBDIRS+=	panel
#.else
CONFIGURE_ARGS+=	--without-panel
#.endif

.if ${PORT_OPTIONS:MGTKSOURCEVIEW2}
CONFIGURE_ARGS+=	--with-gtksourceview2
USE_GNOME+=	gtksourceview2
EXAMPLES_SUBDIRS+=	sourceview
.else
CONFIGURE_ARGS+=	--without-gtksourceview2
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	libgtkspell.so:textproc/gtkspell
CONFIGURE_ARGS+=	--with-gtkspell
.else
CONFIGURE_ARGS+=	--without-gtkspell
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^(CFLAGS[[:space:]]*\+=[[:space:]]*-O)|\1 ${CFLAGS}|' \
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,(touch)( "\$$\(DESTDIR\)\$$\(OCAMLLDCONF\)"),${TRUE}\2,' \
		-e 's,(-ldconf )("\$$\(DESTDIR\)\$$\(OCAMLLDCONF\)"),\1ignore,' \
		${WRKSRC}/src/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \
	"*.ml *.png *.rgb *.xpm text ${EXAMPLES_SUBDIRS}" \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
