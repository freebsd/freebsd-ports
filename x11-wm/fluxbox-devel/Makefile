# New ports collection makefile for:	fluxbox-devel
# Date created:				21 May 2003
# Whom:					hendrik@scholz.net
#
# $FreeBSD$
#

PORTNAME=	fluxbox
PORTVERSION=	0.9.9
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fluxbox
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

PATCH_SITES=	http://fluxbox.org/download/
PATCHFILES=	fluxbox-0.9.9-gcc3.4.patch

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A small and fast window manager based on BlackBox

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	bsetroot:${PORTSDIR}/x11-wm/boxtools

CONFLICTS=	fluxbox-0.1.*

WANT_GNOME=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README TODO
MAN1=		fbrun.1 fbsetbg.1 fluxbox.1 fluxstyle.1 startfluxbox.1
NLSMAKEFILES=	nls nls/C nls/bg_BG nls/da_DK nls/de_DE nls/es_ES nls/et_EE \
		nls/fr_FR nls/it_IT nls/ja_JP nls/lv_LV nls/nl_NL nls/pl_PL \
		nls/pt_BR nls/pt_PT nls/ru_RU nls/sl_SI nls/sv_SE nls/tr_TR

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_DOCHTML)
MASTER_SITES+=		http://fluxbox.org/docbook/en/tarballs/:html
DISTFILES+=		fb-doc-mfhtml.tgz:html
EXTRACT_ONLY+=		fb-doc-mfhtml.tgz
PLIST_SUB+=		DOCHTML:=""
.else
PLIST_SUB+=		DOCHTML:="@comment "
.endif

.if defined(WITH_DOCPDF)
MASTER_SITES+=		http://fluxbox.org/docbook/en/pdf/:pdf
DISTFILES+=		fluxbook.pdf:pdf
PLIST_SUB+=		DOCPDF:=""
.else
PLIST_SUB+=		DOCPDF:="@comment "
.endif

.if defined(WITH_KDE) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-kde
.else
CONFIGURE_ARGS+=	--disable-kde
.endif

.if defined(WITH_XINERAMA) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS:=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS:="@comment "
.endif

.if !defined(WITHOUT_SLIT)
CONFIGURE_ARGS+=	--enable-slit
.else
CONFIGURE_ARGS+=	--disable-slit
.endif

.if !defined(WITHOUT_TOOLBAR)
CONFIGURE_ARGS+=	--enable-toolbar
.else
CONFIGURE_ARGS+=	--disable-toolbar
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mlibgnome}!="" || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Definable build options"
	@${ECHO_CMD} "-----------------------"
.if !defined(WITH_DEBUG)
	@${ECHO_CMD} "WITH_DEBUG=yes		Build with debugging symbols"
.endif
.if !defined(WITH_DOCHTML)
	@${ECHO_CMD} "WITH_DOCHTML=yes	Install the HTML documentation"
.endif
.if !defined(WITH_DOCPDF)
	@${ECHO_CMD} "WITH_DOCPDF=yes		Install the PDF documentation"
.endif
.if !defined(WITH_GNOME)
	@${ECHO_CMD} "WITH_GNOME=yes		Enable GNOME support"
.endif
.if !defined(WITH_KDE)
	@${ECHO_CMD} "WITH_KDE=yes		Enable KDE slit support"
.endif
.if !defined(WITH_XINERAMA)
	@${ECHO_CMD} "WITH_XINERAMA=yes	Enable Xinerama support"
.endif
.if !defined(WITHOUT_NLS)
	@${ECHO_CMD} "WITHOUT_NLS=yes		Disable NLS support"
.endif
.if !defined(WITHOUT_SLIT)
	@${ECHO_CMD} "WITHOUT_SLIT=yes	Disable slit"
.endif
.if !defined(WITHOUT_TOOLBAR)
	@${ECHO_CMD} "WITHOUT_TOOLBAR=yes	Disable toolbar"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g; s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/util/fluxbox-generate_menu.in
.if !defined(WITHOUT_NLS)
.for i in ${NLSMAKEFILES}
	@${REINPLACE_CMD} -e 's|@NLS@|-DNLS|' ${WRKSRC}/${i}/Makefile.in
.endfor
.endif

post-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.if defined(WITH_DOCPDF)
	@${MKDIR} ${DOCSDIR}/pdf
	@${INSTALL_DATA} ${DISTDIR}/fluxbook.pdf ${DOCSDIR}/pdf/
.endif
.if defined(WITH_DOCHTML)
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKDIR}/html/*.css ${DOCSDIR}/html/
	@${INSTALL_DATA} ${WRKDIR}/html/*.html ${DOCSDIR}/html/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
