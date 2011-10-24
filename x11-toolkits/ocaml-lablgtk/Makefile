# New ports collection makefile for:    lablgtk
# Date created:         30. June 2002
# Whom:                 Ronald Kuehn <rk@ronald.org>
#
# $FreeBSD$
#

PORTNAME=	lablgtk
PORTVERSION=	1.2.7
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/ \
		ftp://ftp.inria.fr/lang/caml-light/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
PKGNAMESUFFIX=	${SFXGL}${SFXGNOME}${SFXGLADE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Objective Caml interface to gtk+

USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_OCAML=	yes
ALL_TARGET=	all opt
CONFIGURE_ENV=	USE_DOTOPT=1 GTK_CONFIG=${GTK_CONFIG} \
		LIBDIR=${LOCALBASE}/lib/ocaml BINDIR=${PREFIX}/bin \
		INSTALLDIR=${PREFIX}/lib/ocaml/${PORTNAME} \
		DLLDIR=${PREFIX}/lib/ocaml/stublibs
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	GL	"Enable OpenGL support" on \
		GNOME	"Enable GNOME support" off \
		GLADE	"Enable Glade support" off

EXAMPLESDIR=	${PREFIX}/share/examples/ocaml/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

MASTERPORT=	${PORTSDIR}/devel/ocaml-camlidl
PATTERN=	[[:space:]]*(do|then)?[[:space:]]*)cp([[:space:]]

.include <bsd.port.pre.mk>

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

.if defined(WITH_GNOME)
PLIST_SUB+=	GNOME=""
USE_GNOME=	gdkpixbuf
CONFIGURE_ENV+=	USE_GNOME=1
.else
PLIST_SUB+=	GNOME="@comment "
SFXGNOME=	-nognome
.endif

.if defined(WITH_GLADE)
PLIST_SUB+=	GLADE=""
.if defined(WITH_GNOME)
USE_GNOME+=	libglade
.else
LIB_DEPENDS+=	glade.4:${PORTSDIR}/devel/libglade
BUILD_DEPENDS+=	libglade-config:${PORTSDIR}/devel/libglade
.endif
CONFIGURE_ENV+=	USE_GLADE=1
.else
PLIST_SUB+=	GLADE="@comment "
SFXGLADE=	-noglade
.endif

post-extract:
	@${REINPLACE_CMD} -E \
		-e 's,(${PATTERN}+.*lablgtkto),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,(${PATTERN}+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,(${PATTERN}+.*BINDIR),\1\$${BSD_INSTALL_SCRIPT} \3,' \
		-e 's,(${PATTERN}+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,(${PATTERN}+.*DLLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		${WRKSRC}/src/Makefile

	@${REINPLACE_CMD} -E -e '/^DLLDIR[[:space:]]*=[[:space:]]*.*/d' \
		${WRKSRC}/Makefile

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
.if defined(WITH_GNOME)
	@${MKDIR} ${EXAMPLESDIR}/xmhtml
	@${INSTALL_DATA} ${WRKSRC}/examples/xmhtml/* ${EXAMPLESDIR}/xmhtml
.endif
.if defined(WITH_GLADE)
	@${MKDIR} ${EXAMPLESDIR}/glade
	@${INSTALL_DATA} ${WRKSRC}/examples/glade/* ${EXAMPLESDIR}/glade
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

	@${INSTALL_DATA} ${WRKSRC}/META ${PREFIX}/lib/ocaml/${PORTNAME}

.include <bsd.port.post.mk>
