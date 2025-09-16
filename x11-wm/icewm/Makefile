PORTNAME=	icewm
PORTVERSION=	3.9.0
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/ice-wm/icewm/releases/download/${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Window manager designed for speed and usability
WWW=		https://ice-wm.org/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libsndfile.so:audio/libsndfile

USES=		compiler:c++11-lang gmake gnome iconv:translit localbase \
		perl5 pkgconfig shebangfix tar:lz xorg
USE_GNOME=	glib20
USE_PERL5=	build
USE_XORG=	ice sm x11 xcomposite xcursor xdamage xext xfixes xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-icesound=oss
SHEBANG_FILES=	contrib/icewm-menu-xrandr

OPTIONS_DEFINE=		BEASTIE DOCS IMLIB2 LIBRSVG2 NLS XFT XINERAMA \
			XRANDR XRES
OPTIONS_DEFAULT=	BEASTIE IMLIB2 XFT XINERAMA XRANDR XRES
OPTIONS_SUB=		yes

BEASTIE_DESC=		Use Beastie'fied startup button
BEASTIE_VARS=		STARTUP_PIXMAP=bsd-daemon.xpm
BEASTIE_VARS_OFF=	STARTUP_PIXMAP=icewm-logo.xpm

IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_DESC=		Use Imlib2 for rendering
IMLIB2_CONFIGURE_OFF=	--disable-imlib2 --enable-gdk-pixbuf
IMLIB2_USE_OFF=		GNOME=gdkpixbuf2xlib

LIBRSVG2_BUILD_DEPENDS_OFF=	${LOCALBASE}/include/nanosvg.h:graphics/nanosvg
LIBRSVG2_USE=		GNOME=librsvg2
LIBRSVG2_CONFIGURE_OFF=	--disable-librsvg --enable-nanosvg

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

XFT_LIB_DEPENDS=	libXft.so:x11-fonts/libXft
XFT_CONFIGURE_OFF=	--enable-corefonts --disable-xfreetype

XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_OFF=	--disable-xinerama

XRANDR_USE=		XORG=xrandr
XRANDR_CONFIGURE_OFF=	--disable-xrandr

XRES_DESC=		X11 XResource extension support
XRES_USE=		XORG=xres
XRES_CONFIGURE_OFF=	--disable-xres

post-extract:
.for dir in taskbar themes/Infadel2/taskbar
	@cd ${WRKSRC}/lib/${dir} && ${MV} start.xpm icewm-logo.xpm
	@${LN} -sf ${FILESDIR}/bsd-daemon.xpm ${WRKSRC}/lib/${dir}
	@${LN} -sf ${STARTUP_PIXMAP} ${WRKSRC}/lib/${dir}/start.xpm
.endfor

post-patch-LIBRSVG2-off:
	@${LN} -sf ${LOCALBASE}/include/nanosvg.h \
		${LOCALBASE}/include/nanosvgrast.h ${WRKSRC}/src

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ChangeLog NEWS README TODO doc/*.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
