# Created by: spn
# $FreeBSD$

PORTNAME=	fluxbox
PORTVERSION=	1.3.7
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Small and fast window manager based on BlackBox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xmessage:x11/xmessage
LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake pkgconfig xorg

USE_XORG=	x11 xext xorgproto xft xpm xrandr
GNU_CONFIGURE=	yes

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS DEBUG IMLIB2 XINERAMA \
		XRENDER NLS SLIT SYSTRAY REMEMBER TOOLBAR
OPTIONS_DEFAULT=	XRENDER SLIT SYSTRAY REMEMBER TOOLBAR XINERAMA
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

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/util/fluxbox-generate_menu.in ${WRKSRC}/util/fbsetbg

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|iconv_works=yes|iconv_works=no|' \
		${WRKSRC}/configure

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "AUTHORS ChangeLog NEWS README TODO" \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
