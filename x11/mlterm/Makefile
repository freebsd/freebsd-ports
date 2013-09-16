# Created by: MANTANI Nobutaka <nobutaka@nobutaka.com>
# $FreeBSD$

PORTNAME=	mlterm
PORTVERSION=	3.1.8
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/01release/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Multilingual X11 terminal emulator

LIB_DEPENDS=	Xft:${PORTSDIR}/x11-fonts/libXft

USE_XORG=	sm
USE_GNOME=	gtk20 lthack vte
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure kiklib/configure mkf/configure
USE_PERL5=	build
USES=		gettext pkgconfig perl5
CONFIGURE_ARGS=	--with-imagelib=gdk-pixbuf2 --enable-utmp \
		--enable-optimize-redrawing \
		--with-tools="mlclient,mlconfig,mlterm-menu,mlcc,w3mmlconfig,mlimgloader" \
		--disable-iiimf
CONFIGURE_ENV=	LIBS="${LIBS} -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl"
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	CAIRO FRIBIDI IBUS M17NLIB SCIM SIXEL UIM
CAIRO_DESC=	"Use Cairo for type engine (experimental)"
FRIBIDI_DESC=	"Use Fribidi for BiDi rendering"
IBUS_DESC=	"IBUS support (experimental)"
M17NLIB_DESC=	"m17n library support (experimental)"
SCIM_DESC=	"SCIM support (experimental)"
SIXEL_DESC=	"Sixel graphics support"
UIM_DESC=	"uim support (experimental)"

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MFRIBIDI}
CONFIGURE_ARGS+=	--enable-fribidi
LIB_DEPENDS+=	fribidi:${PORTSDIR}/converters/fribidi
PLIST_SUB+=	FRIBIDI=""
.else
CONFIGURE_ARGS+=	--disable-fribidi
PLIST_SUB+=	FRIBIDI="@comment "
.endif

.if ${PORT_OPTIONS:MUIM}
CONFIGURE_ARGS+=	--enable-uim
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	uim:${PORTSDIR}/textproc/uim
PLIST_SUB+=	UIM=""
.else
CONFIGURE_ARGS+=	--disable-uim
PLIST_SUB+=	UIM="@comment "
.endif

.if ${PORT_OPTIONS:MM17NLIB}
CONFIGURE_ARGS+=	--enable-m17nlib
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	m17n:${PORTSDIR}/devel/m17n-lib
PLIST_SUB+=	M17NLIB=""
.else
CONFIGURE_ARGS+=	--disable-m17nlib
PLIST_SUB+=	M17NLIB="@comment "
.endif

.if ${PORT_OPTIONS:MSCIM}
CONFIGURE_ARGS+=	--enable-scim
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	scim-1.0:${PORTSDIR}/textproc/scim
PLIST_SUB+=	SCIM=""
.else
CONFIGURE_ARGS+=	--disable-scim
PLIST_SUB+=	SCIM="@comment "
.endif

.if ${PORT_OPTIONS:MIBUS}
CONFIGURE_ARGS+=	--enable-ibus
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	ibus-1.0:${PORTSDIR}/textproc/ibus
PLIST_SUB+=	IBUS=""
.else
CONFIGURE_ARGS+=	--disable-ibus
PLIST_SUB+=	IBUS="@comment "
.endif

.if ${PORT_OPTIONS:MCAIRO}
CONFIGURE_ARGS+=	--with-type-engines="xcore,xft,cairo"
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
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

.if ${OSVERSION} >= 900004
MAKE_ENV=	LIBS_LOCAL=-lutempter
.else
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	utempter:${PORTSDIR}/sysutils/libutempter
.endif

USE_LDCONFIG=	yes

MAN1=	mlterm.1 mlclient.1

post-patch:
	@${REINPLACE_CMD} -e "s,echo aout,echo elf,g" ${WRKSRC}/configure \
		${WRKSRC}/kiklib/configure ${WRKSRC}/mkf/configure

post-configure:
	@${CP} ${LIBTOOL} ${WRKSRC}
	@${REINPLACE_CMD} -e "s,@CGI_BIN@,${PREFIX}/libexec/w3mmlconfig," \
		${WRKSRC}/tool/w3mmlconfig/mlconfig.cgi
.if ${OSVERSION} >= 900004
	@${REINPLACE_CMD} -e 's|kik_utmp_bsd|kik_utmp_utmper|' \
		${WRKSRC}/kiklib/src/Makefile
.endif

post-install:
	(cd ${WRKSRC}/tool/w3mmlconfig; ${MAKE} install)
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ja/README.ja ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
