# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	mlterm
PORTVERSION=	3.3.7
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/01release/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Multilingual X11 terminal emulator

USES=		gettext libtool perl5 pkgconfig
USE_XORG=	sm xft
USE_GNOME=	gtk20 vte
USE_LDCONFIG=	yes
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gui=x11 --with-imagelib=gdk-pixbuf2 --enable-utmp \
		--enable-optimize-redrawing \
		--with-tools="mlclient,mlconfig,mlterm-menu,mlcc,w3mmlconfig,mlimgloader" \
		--disable-iiimf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	CAIRO DOCS FRIBIDI IBUS M17NLIB SCIM SIXEL UIM
CAIRO_DESC=	Use Cairo for type engine (experimental)
FRIBIDI_DESC=	Use Fribidi for BiDi rendering
IBUS_DESC=	IBUS support (experimental)
M17NLIB_DESC=	m17n library support (experimental)
SCIM_DESC=	SCIM support (experimental)
SIXEL_DESC=	Sixel graphics support
UIM_DESC=	uim support (experimental)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFRIBIDI}
CONFIGURE_ARGS+=	--enable-fribidi
LIB_DEPENDS+=	libfribidi.so:${PORTSDIR}/converters/fribidi
PLIST_SUB+=	FRIBIDI=""
.else
CONFIGURE_ARGS+=	--disable-fribidi
PLIST_SUB+=	FRIBIDI="@comment "
.endif

.if ${PORT_OPTIONS:MUIM}
CONFIGURE_ARGS+=	--enable-uim
LIB_DEPENDS+=	libuim.so:${PORTSDIR}/textproc/uim
PLIST_SUB+=	UIM=""
.else
CONFIGURE_ARGS+=	--disable-uim
PLIST_SUB+=	UIM="@comment "
.endif

.if ${PORT_OPTIONS:MM17NLIB}
CONFIGURE_ARGS+=	--enable-m17nlib
LIB_DEPENDS+=	libm17n.so:${PORTSDIR}/devel/m17n-lib
PLIST_SUB+=	M17NLIB=""
.else
CONFIGURE_ARGS+=	--disable-m17nlib
PLIST_SUB+=	M17NLIB="@comment "
.endif

.if ${PORT_OPTIONS:MSCIM}
CONFIGURE_ARGS+=	--enable-scim
LIB_DEPENDS+=	libscim-1.0.so:${PORTSDIR}/textproc/scim
PLIST_SUB+=	SCIM=""
.else
CONFIGURE_ARGS+=	--disable-scim
PLIST_SUB+=	SCIM="@comment "
.endif

.if ${PORT_OPTIONS:MIBUS}
CONFIGURE_ARGS+=	--enable-ibus
LIB_DEPENDS+=	libibus-1.0.so:${PORTSDIR}/textproc/ibus
PLIST_SUB+=	IBUS=""
.else
CONFIGURE_ARGS+=	--disable-ibus
PLIST_SUB+=	IBUS="@comment "
.endif

.if ${PORT_OPTIONS:MCAIRO}
CONFIGURE_ARGS+=	--with-type-engines="xcore,xft,cairo"
LIB_DEPENDS+=	libcairo.so:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
CONFIGURE_ARGS+=	--with-type-engines="xcore,xft"
PLIST_SUB+=	CAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MSIXEL}
CONFIGURE_ARGS+=	--enable-sixel
PLIST_SUB+=	SIXEL=""
.else
CONFIGURE_ARGS+=	--disable-sixel
PLIST_SUB+=	SIXEL="@comment "
.endif

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	libutempter.so:${PORTSDIR}/sysutils/libutempter
.endif

post-configure:
	@${REINPLACE_CMD} -e "s,@CGI_BIN@,${PREFIX}/libexec/w3mmlconfig," \
		${WRKSRC}/tool/w3mmlconfig/mlconfig.cgi
.if ${OSVERSION} >= 900004
	@${REINPLACE_CMD} -e 's|kik_utmp_bsd|kik_utmp_utmper|' \
		${WRKSRC}/kiklib/src/Makefile
.endif

post-install:
	(cd ${WRKSRC}/tool/w3mmlconfig && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ja/README.ja ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
