# New ports collection makefile for:	lablgtk2
# Date created:		2004-11-02
# Whom:			Rene Ladan
#
# $FreeBSD$

PORTNAME=	lablgtk2
PORTVERSION=	2.4.0
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/olabl/ \
		http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/ \
		ftp://ftp.inria.fr/INRIA/caml-light/bazar-ocaml/ \
		http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	lablgtk-${PORTVERSION}

MAINTAINER=	r.c.ladan@student.tue.nl
COMMENT=	An Objective Caml interface to GTK+ 2.x

BUILD_DEPENDS+=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS+=	ocamlc:${PORTSDIR}/lang/ocaml

USE_GMAKE=	yes
USE_GNOME=	gtk20

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}

HAS_CONFIGURE=	yes
ALL_TARGET=	all opt

CONFIGURE_ARGS=	--prefix=${PREFIX} --with-libdir=${PREFIX}/lib/ocaml

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/lablgl) && exists(${X11BASE}/libdata/pkgconfig/gtkgl-2.0.pc)
CONFIGURE_ARGS+=	--with-gl
BUILD_DEPENDS+=	lablgl:${PORTSDIR}/graphics/ocaml-lablgl
RUN_DEPENDS+=	lablgl:${PORTSDIR}/graphics/ocaml-lablgl
LIB_DEPENDS+=	gtkgl-2.0.1:${PORTSDIR}/x11-toolkits/gtkglarea2
WITH_GL=	yes
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=	--without-gl
PLIST_SUB+=	GL="@comment "
.endif

.if exists(${X11BASE}/libdata/pkgconfig/libglade-2.0.pc)
CONFIGURE_ARGS+=	--with-glade
USE_GNOME+=	libglade2
WITH_GLADE=	yes
PLIST_SUB+=	GLADE=""
.else
CONFIGURE_ARGS+=	--without-glade
PLIST_SUB+=	GLADE="@comment "
.endif

.if exists(${X11BASE}/libdata/pkgconfig/libgnomeui-2.0.pc)
CONFIGURE_ARGS+=	--with-gnomeui
USE_GNOME+=	libgnomeui
WITH_GNOMEUI=	yes
PLIST_SUB+=	GNOMEUI=""
.else
CONFIGURE_ARGS+=	--without-gnomeui
PLIST_SUB+=	GNOMEUI="@comment "
.endif

.if exists(${X11BASE}/libdata/pkgconfig/libgnomecanvas-2.0.pc)
CONFIGURE_ARGS+=	--with-gnomecanvas
USE_GNOME+=	libgnomecanvas
PLIST_SUB+=	GNOMECANVAS=""
WITH_GNOMECANVAS=	yes
.else
CONFIGURE_ARGS+=	--without-gnomecanvas
PLIST_SUB+=	GNOMECANVAS="@comment "
.endif

.if exists(${X11BASE}/libdata/pkgconfig/librsvg-2.0.pc)
CONFIGURE_ARGS+=	--with-rsvg
USE_GNOME+=	librsvg2
WITH_RSVG=	yes
PLIST_SUB+=	RSVG=""
.else
CONFIGURE_ARGS+=	--without-rsvg
PLIST_SUB+=	RSVG="@comment "
.endif

.if exists(${X11BASE}/libdata/pkgconfig/libpanelapplet-2.0.pc)
CONFIGURE_ARGS+=	--with-panel
USE_GNOME+=	gnomepanel
WITH_PANEL=	yes
PLIST_SUB+=	PANEL=""
.else
CONFIGURE_ARGS+=	--without-panel
PLIST_SUB+=	PANEL="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/image256x256.rgb \
		${WRKSRC}/examples/test.xpm \
		${WRKSRC}/examples/*.ml ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/text
	@${INSTALL_DATA} ${WRKSRC}/examples/text/* ${EXAMPLESDIR}/text
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}/COPYING
.endif
.if defined(WITH_GL) && !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}/GL
	@${INSTALL_DATA} ${WRKSRC}/examples/GL/* ${EXAMPLESDIR}/GL
.endif
.if defined(WITH_GNOMECANVAS) && !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}/canvas
	@${INSTALL_DATA} ${WRKSRC}/examples/canvas/* ${EXAMPLESDIR}/canvas
.endif
.if defined(WITH_GLADE) && !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}/glade
	@${INSTALL_DATA} ${WRKSRC}/examples/glade/* ${EXAMPLESDIR}/glade
.endif
.if defined(WITH_PANEL) && !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}/panel
	@${INSTALL_DATA} ${WRKSRC}/examples/panel/* ${EXAMPLESDIR}/panel
.endif
.if defined(WITH_RSVG) && !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}/rsvg
	@${INSTALL_DATA} ${WRKSRC}/examples/rsvg/* ${EXAMPLESDIR}/rsvg
.endif

.include <bsd.port.post.mk>
