# New ports collection makefile for:    lablgtk
# Date created:         30. June 2002
# Whom:                 Ronald Kuehn <rk@ronald.org>
#
# $FreeBSD$
#

PORTNAME=	lablgtk
PORTVERSION=	1.2.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/ \
		ftp://ftp.inria.fr/lang/caml-light/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
PKGNAMESUFFIX=	${SFXGL}${SFXGNOME}${SFXGLADE}

MAINTAINER=	rk@ronald.org
COMMENT=	An Objective Caml interface to gtk+

BUILD_DEPENDS+=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS+=	ocamlc:${PORTSDIR}/lang/ocaml
.if defined(WITHOUT_GL)
PLIST_SUB+=	GL="@comment "
SFXGL=		-nogl
.else
PLIST_SUB+=	GL=""
BUILD_DEPENDS+=	lablgl:${PORTSDIR}/graphics/ocaml-lablgl
RUN_DEPENDS+=	lablgl:${PORTSDIR}/graphics/ocaml-lablgl
LIB_DEPENDS+=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
CONFIGURE_ENV+=	USE_GL=1
.endif
.if defined(WITHOUT_GNOME)
PLIST_SUB+=	GNOME="@comment "
SFXGNOME=	-nognome
.else
PLIST_SUB+=	GNOME=""
USE_GNOME=	gdkpixbuf
CONFIGURE_ENV+=	USE_GNOME=1
.endif
.if defined(WITHOUT_GLADE)
PLIST_SUB+=	GLADE="@comment "
SFXGLADE=	-noglade
.else
PLIST_SUB+=	GLADE=""
.if defined(WITHOUT_GNOME)
LIB_DEPENDS+=	glade.4:${PORTSDIR}/devel/libglade
BUILD_DEPENDS+=	libglade-config:${PORTSDIR}/devel/libglade
.else
USE_GNOME+=	libglade
.endif
CONFIGURE_ENV+=	USE_GLADE=1
.endif

USE_GMAKE=	yes
USE_GNOME+=	gtk12
ALL_TARGET=	all opt
EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
CONFIGURE_ENV+=	USE_DOTOPT=1 GTK_CONFIG=${GTK_CONFIG}
CONFIGURE_ENV+=	LIBDIR=${PREFIX}/lib/ocaml BINDIR=${PREFIX}/bin
CONFIGURE_ENV+=	INSTALLDIR=${PREFIX}/lib/ocaml/lablgtk

do-configure:
	@(cd ${WRKSRC} && ${GMAKE} configure ${CONFIGURE_ENV})

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.rgb \
		${WRKSRC}/examples/*.ml ${WRKSRC}/examples/*.xpm ${EXAMPLESDIR}
.if !defined(WITHOUT_GL)
	@${MKDIR} ${EXAMPLESDIR}/GL
	@${INSTALL_DATA} ${WRKSRC}/examples/GL/* ${EXAMPLESDIR}/GL
.endif
.if !defined(WITHOUT_GNOME)
	@${MKDIR} ${EXAMPLESDIR}/xmhtml
	@${INSTALL_DATA} ${WRKSRC}/examples/xmhtml/* ${EXAMPLESDIR}/xmhtml
.endif
.if !defined(WITHOUT_GLADE)
	@${MKDIR} ${EXAMPLESDIR}/glade
	@${INSTALL_DATA} ${WRKSRC}/examples/glade/* ${EXAMPLESDIR}/glade
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
