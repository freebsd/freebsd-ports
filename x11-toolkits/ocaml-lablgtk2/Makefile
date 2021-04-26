# Created by: Rene Ladan <rene@FreeBSD.org>

PORTNAME=	lablgtk2
PORTVERSION=	2.18.11
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Objective Caml interface to GTK+ 2.x

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome pkgconfig
USE_GNOME=	gtk20
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_WASH=		yes

OPTIONS_DEFINE=		LIBRSVG2 DOCS EXAMPLES
OPTIONS_DEFAULT=	LIBRSVG2

HAS_CONFIGURE=	yes
ALL_TARGET=	all opt
MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	garrigue
GH_PROJECT=	lablgtk

CONFIGURE_ARGS=	--prefix=${PREFIX} --with-libdir=${PREFIX}/${OCAML_LIBDIR} \
		--without-gtksourceview --without-gnomeui \
		--without-panel --without-gtkspell --without-gl \
		--without-gtksourceview2 --without-glade --without-gnomecanvas
CONFIGURE_ENV=	CAMLP4O="camlp4 pa_o.cmo pa_op.cmo pr_dump.cmo"

PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)cp([[:space:]]

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	COPYING README
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
PORTEXAMPLES=	*

LIBRSVG2_CONFIGURE_WITH=rsvg
LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_VARS=		EXAMPLES_SUBDIRS+=rsvg

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^(CFLAGS[[:space:]]*\+=[[:space:]]*-O)|\1 ${CFLAGS}|' \
		-e 's,^(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,^(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,^(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,(touch)( "\$$\(DESTDIR\)\$$\(OCAMLLDCONF\)"),${TRUE}\2,' \
		-e 's,(-ldconf )("\$$\(DESTDIR\)\$$\(OCAMLLDCONF\)"),\1ignore,' \
		${WRKSRC}/src/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \
	"*.ml *.png *.rgb *.xpm text ${EXAMPLES_SUBDIRS}" \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
