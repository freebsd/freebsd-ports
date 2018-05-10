# Created by: spn
# $FreeBSD$

PORTNAME=	fluxbox
PORTVERSION=	1.3.7
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	SF
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Small and fast window manager based on BlackBox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xmessage:x11/xmessage
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USE_XORG=	x11 xext xextproto xft xpm xrandr
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

PORTDATA=	*
PORTDOCS=	*

DOCSVERSION=	20060629

OPTIONS_DEFINE=	DOCS DOCHTML PDFDOCS DEBUG IMLIB2 XINERAMA \
		XRENDER NLS SLIT SYSTRAY REMEMBER TOOLBAR
OPTIONS_DEFAULT=	XRENDER SLIT SYSTRAY REMEMBER TOOLBAR XINERAMA
DOCHTML_DESC=	Install html documentation
PDFDOCS_DESC=	Build and install PDF documentation
REMEMBER_DESC=	Enable remember feature
SLIT_DESC=	Enable slit feature
SYSTRAY_DESC=	Enable systray feature
TOOLBAR_DESC=	Enable toolbar feature
XRENDER_DESC=	Enable xrender support

DEBUG_CONFIGURE_ON=	--enable-debug
IMLIB2_CONFIGURE_ENABLE=	imlib2
IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	iconv
NLS_VARS=	CPPFLAGS+="-I${LOCALBASE}/include" LIBS+="-L${LOCALBASE}/lib ${ICONV_LIB}"
NLS_VARS_OFF=	CPPFLAGS+="-I${LOCALBASE}/include" LIBS+="-L${LOCALBASE}/lib"
REMEMBER_CONFIGURE_ENABLE=	remember
SLIT_CONFIGURE_ENABLE=	slit
SYSTRAY_CONFIGURE_ENABLE=	systray
TOOLBAR_CONFIGURE_ENABLE=	toolbar
XINERAMA_CONFIGURE_ENABLE=	xinerama
XINERAMA_USE=	XORG=xinerama
XRENDER_USE=	XORG=xrender
XRENDER_CONFIGURE_ENABLE=	xrender

# http://fluxbox.org/docbook/en/tarballs/
DOCHTML_MASTER_SITES=	LOCAL/mezz:html \
			http://people.freebsd.org/~mezz/distfiles/:html
DOCHTML_DISTFILES=	fb-doc-mfhtml-${DOCSVERSION}.tgz:html
DOCHTML_EXTRACT_ONLY=	fb-doc-mfhtml-${DOCSVERSION}.tgz
# http://fluxbox.org/docbook/en/pdf/
PDFDOCS_MASTER_SITES=	LOCAL/mezz:pdf \
			http://people.freebsd.org/~mezz/distfiles/:pdf
PDFDOCS_DISTFILES=	fluxbook-${DOCSVERSION}.pdf:pdf

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/util/fluxbox-generate_menu.in ${WRKSRC}/util/fbsetbg

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|iconv_works=yes|iconv_works=no|' \
		${WRKSRC}/configure

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog NEWS README TODO" \
		${STAGEDIR}${DOCSDIR})

post-install-PDFDOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	${INSTALL_DATA} ${DISTDIR}/fluxbook-${DOCSVERSION}.pdf \
		${STAGEDIR}${DOCSDIR}/pdf/

post-install-DOCHTML-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
. for h in *.css *.html
	(cd ${WRKDIR}/html && ${INSTALL_DATA} ${h} ${STAGEDIR}${DOCSDIR}/html)
. endfor

.include <bsd.port.mk>
