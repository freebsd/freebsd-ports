# New ports collection makefile for:	fluxbox-devel
# Date created:				21 May 2003
# Whom:					hendrik@scholz.net
#
# $FreeBSD$
#

PORTNAME=	fluxbox
PORTVERSION=	0.9.13
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fluxbox
PKGNAMESUFFIX=	-devel
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A small and fast window manager based on BlackBox

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	bsetroot:${PORTSDIR}/x11-wm/boxtools

CONFLICTS=	fluxbox-0.1.*

USE_GMAKE=	yes
USE_GNOME=	gnometarget
WANT_GNOME=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=15

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README TODO
MAN1=		fbrun.1 fbsetbg.1 fluxbox.1 fluxstyle.1 startfluxbox.1

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

.if defined(WITH_IMLIB2)
LIB_DEPENDS+=		Imlib2.3:${PORTSDIR}/graphics/imlib2
CONFIGURE_ARGS+=	--enable-imlib2
.else
CONFIGURE_ARGS+=	--disable-imlib2
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
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib -liconv"
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=		NLS:=""
.else
CONFIGURE_ENV=		CPPFLAGS="-I${LOCALBASE}/include" \
			LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS:="@comment "
.endif

.if !defined(WITHOUT_REMEMBER)
CONFIGURE_ARGS+=	--enable-remember
.else
CONFIGURE_ARGS+=	--disable-remember
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

.if !defined(WITHOUT_XRENDER)
CONFIGURE_ARGS+=	--enable-xrender
.else
CONFIGURE_ARGS+=	--disable-xrender
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
.if !defined(WITH_IMLIB2)
	@${ECHO_CMD} "WITH_IMLIB2=yes		Enable Imlib2 (pixmap themes) support"
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
.if !defined(WITHOUT_REMEMBER)
	@${ECHO_CMD} "WITHOUT_REMEMBER=yes	Disable remembering attributes support"
.endif
.if !defined(WITHOUT_SLIT)
	@${ECHO_CMD} "WITHOUT_SLIT=yes	Disable slit"
.endif
.if !defined(WITHOUT_TOOLBAR)
	@${ECHO_CMD} "WITHOUT_TOOLBAR=yes	Disable toolbar"
.endif
.if !defined(WITHOUT_XRENDER)
	@${ECHO_CMD} "WITHOUT_XRENDER=yes	Disable Xrender (transparent) support"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g; s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/util/fluxbox-generate_menu.in
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e 's|HAVE_ICONV=yes|HAVE_ICONV=no|g' \
		${WRKSRC}/configure
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
