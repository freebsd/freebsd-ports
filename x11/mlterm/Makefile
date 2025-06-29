PORTNAME=	mlterm
PORTVERSION=	3.9.4
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Multilingual X11 terminal emulator
WWW=		https://mlterm.sourceforge.net/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz

USES=		cpe desktop-file-utils gettext gnome libtool perl5 pkgconfig xorg
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30 vte3
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XORG=	sm x11 xft
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-gui=x11 --with-imagelib=gdk-pixbuf2 --enable-utmp \
		--enable-optimize-redrawing --disable-iiimf --with-gtk=3.0 \
		--disable-ssh2
EXTERNAL_TOOLS=	mlclient,mlconfig,mlterm-menu,mlcc,w3mmlconfig,mlimgloader
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl -Wl,--undefined-version
MAKE_JOBS_UNSAFE=	yes

GH_ACCOUNT=	arakiken

OPTIONS_DEFINE=	CAIRO DOCS FRIBIDI IBUS M17NLIB REGIS SCIM SIXEL UIM
OPTIONS_SUB=	yes
OPTIONS_RADIO=	FCITX
OPTIONS_RADIO_FCITX=	FCITX4 FCITX5
CAIRO_DESC=	Use Cairo for type engine
FCITX_DESC=	Fcitx support
FCITX4_DESC=	Fcitx4 support
FCITX5_DESC=	Fcitx5 support
FRIBIDI_DESC=	Use Fribidi for BiDi rendering
IBUS_DESC=	IBUS support
M17NLIB_DESC=	m17n library support
REGIS_DESC=	ReGIS graphics support
SCIM_DESC=	SCIM support
SIXEL_DESC=	Sixel graphics support
UIM_DESC=	uim support

FCITX4_CONFIGURE_ON=	--enable-fcitx
FCITX4_LIB_DEPENDS=	libfcitx-gclient.so:chinese/fcitx
FCITX5_CONFIGURE_ON=	--enable-fcitx
FCITX5_LIB_DEPENDS=	libFcitx5GClient.so:textproc/fcitx5-gtk

FRIBIDI_CONFIGURE_ENABLE=	fribidi
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi

UIM_CONFIGURE_ENABLE=	uim
UIM_LIB_DEPENDS=	libuim.so:textproc/uim

M17NLIB_CONFIGURE_ENABLE=	m17nlib
M17NLIB_LIB_DEPENDS=	libm17n.so:devel/m17n-lib

SCIM_CONFIGURE_ENABLE=	scim
SCIM_LIB_DEPENDS=	libscim-1.0.so:textproc/scim

IBUS_CONFIGURE_ENABLE=	ibus
IBUS_LIB_DEPENDS=	libibus-1.0.so:textproc/ibus

CAIRO_LIB_DEPENDS=	libcairo.so:graphics/cairo
CAIRO_CONFIGURE_ON=	--with-type-engines="xcore,xft,cairo"
CAIRO_CONFIGURE_OFF=	--with-type-engines="xcore,xft"

SIXEL_CONFIGURE_ENABLE=	sixel

REGIS_USES=		sdl
REGIS_USE=		SDL=ttf

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREGIS}
EXTERNAL_TOOLS+=,registobmp
.endif

CONFIGURE_ARGS+=--with-tools="${EXTERNAL_TOOLS}"

post-configure:
	@${REINPLACE_CMD} -e "s,@CGI_BIN@,${PREFIX}/libexec/w3mmlconfig," \
		-e "s,@PERL @,${PERL}," \
		${WRKSRC}/tool/w3mmlconfig/mlconfig.cgi

post-install:
	(cd ${WRKSRC}/tool/w3mmlconfig && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ja/README.ja ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${FILESDIR}/mlterm.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
