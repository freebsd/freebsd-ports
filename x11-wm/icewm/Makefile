# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>

PORTNAME=	icewm
PORTVERSION=	2.5.0
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/ice-wm/icewm/releases/download/${PORTVERSION}/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Window manager designed for speed and usability

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
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xpm xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-icesound=oss
SHEBANG_FILES=	contrib/icewm-menu-xrandr

OPTIONS_DEFINE=		BEASTIE DOCS IMLIB2 NLS SVG XFT XINERAMA XRANDR
OPTIONS_DEFAULT=	BEASTIE IMLIB2 XFT XINERAMA XRANDR
OPTIONS_SUB=		yes

BEASTIE_DESC=		Use Beastie'fied startup button
BEASTIE_VARS=		STARTUP_PIXMAP=bsd-daemon.xpm
BEASTIE_VARS_OFF=	STARTUP_PIXMAP=icewm-logo.xpm

IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_DESC=		Use Imlib2 for rendering
IMLIB2_CONFIGURE_OFF=	--disable-imlib2 --enable-gdk-pixbuf
IMLIB2_USE_OFF=		GNOME=gdkpixbuf2

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

SVG_USE=		GNOME=librsvg2
SVG_CONFIGURE_OFF=	--disable-rsvg

XFT_LIB_DEPENDS=	libXft.so:x11-fonts/libXft
XFT_CONFIGURE_OFF=	--enable-corefonts --disable-xfreetype

XINERAMA_USE=		XORG=xinerama
XINERAMA_CONFIGURE_ENABLE=	xinerama

XRANDR_USE=		XORG=xrandr
XRANDR_CONFIGURE_ENABLE=	xrandr

post-extract:
.for dir in taskbar themes/Infadel2/taskbar
	@cd ${WRKSRC}/lib/${dir} && ${MV} start.xpm icewm-logo.xpm
	@${LN} -sf ${FILESDIR}/bsd-daemon.xpm ${WRKSRC}/lib/${dir}
	@${LN} -sf ${STARTUP_PIXMAP} ${WRKSRC}/lib/${dir}/start.xpm
.endfor

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ChangeLog NEWS README TODO doc/*.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
