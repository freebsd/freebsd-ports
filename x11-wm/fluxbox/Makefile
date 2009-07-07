# New ports collection makefile for:	fluxbox
# Date created:				29 November 2001
# Whom:					spn
#
# $FreeBSD$
#

PORTNAME=	fluxbox
PORTVERSION=	1.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	beat@FreeBSD.org
COMMENT=	A small and fast window manager based on BlackBox

RUN_DEPENDS=	xmessage:${PORTSDIR}/x11/xmessage

USE_XORG=	xextproto xft xpm xrandr
USE_GMAKE=	yes
USE_GNOME=	gnometarget
WANT_GNOME=	yes
GNU_CONFIGURE=	yes

DOCS=		AUTHORS COPYING ChangeLog NEWS README TODO
MAN1=		fbrun.1 fbsetbg.1 fbsetroot.1 fluxbox.1 fluxstyle.1 \
		startfluxbox.1 fluxbox-remote.1
MAN5=		fluxbox-keys.5
DOCSVERSION=	20060629

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_DOCHTML)
# http://fluxbox.org/docbook/en/tarballs/
MASTER_SITES+=		${MASTER_SITE_LOCAL:S,%SUBDIR%,mezz,}:html \
			http://people.freebsd.org/~mezz/distfiles/:html
DISTFILES+=		fb-doc-mfhtml-${DOCSVERSION}.tgz:html
EXTRACT_ONLY+=		fb-doc-mfhtml-${DOCSVERSION}.tgz
PLIST_SUB+=		DOCHTML:=""
.else
PLIST_SUB+=		DOCHTML:="@comment "
.endif

.if defined(WITH_DOCPDF)
# http://fluxbox.org/docbook/en/pdf/
MASTER_SITES+=		${MASTER_SITE_LOCAL:S,%SUBDIR%,mezz,}:pdf \
			http://people.freebsd.org/~mezz/distfiles/:pdf
DISTFILES+=		fluxbook-${DOCSVERSION}.pdf:pdf
PLIST_SUB+=		DOCPDF:=""
.else
PLIST_SUB+=		DOCPDF:="@comment "
.endif

.if !defined(WITHOUT_IMLIB2)
USE_EFL+=		imlib2
CONFIGURE_ARGS+=	--enable-imlib2
.else
CONFIGURE_ARGS+=	--disable-imlib2
.endif

.if defined(WITH_XINERAMA) || defined(PACKAGE_BUILDING)
USE_XORG+=		xinerama
CONFIGURE_ARGS+=	--enable-xinerama
.endif

.if !defined(WITHOUT_NLS)
USE_ICONV=		yes
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
USE_XORG+=		xrender
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
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/util/fluxbox-generate_menu.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/util/fbsetbg
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
	@${INSTALL_DATA} ${DISTDIR}/fluxbook-${DOCSVERSION}.pdf \
		${DOCSDIR}/pdf/
.endif
.if defined(WITH_DOCHTML)
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKDIR}/html/*.css ${DOCSDIR}/html/
	@${INSTALL_DATA} ${WRKDIR}/html/*.html ${DOCSDIR}/html/
.endif

.include <bsd.port.post.mk>
