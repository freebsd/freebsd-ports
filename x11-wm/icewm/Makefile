# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	icewm
PORTVERSION=	1.9.1
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/ice-wm/icewm/releases/download/${PORTVERSION}/

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Window Manager designed for speed, usability and consistency

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libfribidi.so:converters/fribidi \
		libsndfile.so:audio/libsndfile

USES=		compiler:c++11-lang gmake gnome iconv:translit localbase \
		perl5 pkgconfig shebangfix tar:lz xorg
USE_GNOME=	gdkpixbuf2
USE_PERL5=	build
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xpm xrender
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-icesound=oss \
		--with-cfgdir=${DATADIR} \
		--with-libdir=${DATADIR} \
		--with-docdir=${PREFIX}/share/doc
SHEBANG_FILES=	contrib/icewm-menu-xrandr

OPTIONS_DEFINE=		BEASTIE DOCS NLS XFT XINERAMA XRANDR
OPTIONS_DEFAULT=	BEASTIE XFT XINERAMA XRANDR
OPTIONS_SUB=		yes

BEASTIE_DESC=		Use Beastie'fied startup button
BEASTIE_VARS=		STARTUP_PIXMAP=bsd-daemon.xpm
BEASTIE_VARS_OFF=	STARTUP_PIXMAP=icewm-logo.xpm
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
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

post-patch:
	@${REINPLACE_CMD} -E -e \
		'/^(icewm|icehelp|icewmbg)_LDADD =/s|$$| @LIBICONV@| ; \
		 /@echo/s|^|#| ; \
		 s|@$$\(|$$(|' ${WRKSRC}/src/Makefile.in

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ChangeLog NEWS README TODO doc/*.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
