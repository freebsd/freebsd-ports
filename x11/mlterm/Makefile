# New ports collection makefile for:	mlterm
# Date created:		9 December 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	mlterm
PORTVERSION=	3.1.3
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/01release/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Multilingual X11 terminal emulator

LIB_DEPENDS=	Xft:${PORTSDIR}/x11-fonts/libXft

USE_XORG=	sm
USE_GNOME=	gtk20 lthack vte
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure kiklib/configure mkf/configure
USE_PERL5_BUILD=yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--with-imagelib=gdk-pixbuf2 --enable-utmp \
		--enable-optimize-redrawing \
		--with-tools="mlclient,mlconfig,mlterm-menu,mlcc,w3mmlconfig,mlimgloader" \
		--disable-iiimf
CONFIGURE_ENV=	LIBS="${LIBS} -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl"
CFLAGS+=	-I${LOCALBASE}/include
MAKE_JOBS_UNSAFE=	yes
OPTIONS=	FRIBIDI	"Use Fribidi for BiDi rendering" off \
		UIM "uim support (experimental)" off \
		M17NLIB "m17n library support (experimental)" off \
		SCIM "SCIM support (experimental)" off \
		IBUS "IBUS support (experimental)" off \
		CAIRO "Use Cairo for type engine (experimental)" off \
		SIXEL "Sixel graphics support" off

.include <bsd.port.pre.mk>

.if defined(WITH_FRIBIDI)
CONFIGURE_ARGS+=	--enable-fribidi
LIB_DEPENDS+=	fribidi:${PORTSDIR}/converters/fribidi
PLIST_SUB+=	FRIBIDI=""
.else
CONFIGURE_ARGS+=	--disable-fribidi
PLIST_SUB+=	FRIBIDI="@comment "
.endif

.if defined(WITH_UIM)
CONFIGURE_ARGS+=	--enable-uim
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	uim:${PORTSDIR}/textproc/uim
PLIST_SUB+=	UIM=""
.else
CONFIGURE_ARGS+=	--disable-uim
PLIST_SUB+=	UIM="@comment "
.endif

.if defined(WITH_M17NLIB)
CONFIGURE_ARGS+=	--enable-m17nlib
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	m17n:${PORTSDIR}/devel/m17n-lib
PLIST_SUB+=	M17NLIB=""
.else
CONFIGURE_ARGS+=	--disable-m17nlib
PLIST_SUB+=	M17NLIB="@comment "
.endif

.if defined(WITH_SCIM)
CONFIGURE_ARGS+=	--enable-scim
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	scim-1.0:${PORTSDIR}/textproc/scim
PLIST_SUB+=	SCIM=""
.else
CONFIGURE_ARGS+=	--disable-scim
PLIST_SUB+=	SCIM="@comment "
.endif

.if defined(WITH_IBUS)
CONFIGURE_ARGS+=	--enable-ibus
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	ibus-1.0:${PORTSDIR}/textproc/ibus
PLIST_SUB+=	IBUS=""
.else
CONFIGURE_ARGS+=	--disable-ibus
PLIST_SUB+=	IBUS="@comment "
.endif

.if defined(WITH_CAIRO)
CONFIGURE_ARGS+=	--with-type-engines="xcore,xft,cairo"
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	cairo:${PORTSDIR}/graphics/cairo
PLIST_SUB+=	CAIRO=""
.else
CONFIGURE_ARGS+=	--with-type-engines="xcore,xft"
PLIST_SUB+=	CAIRO="@comment "
.endif

.if defined(WITH_SIXEL)
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
USE_GETTEXT=	yes

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/mlterm
	${INSTALL_DATA} ${WRKSRC}/doc/ja/README.ja ${PREFIX}/share/doc/ja/mlterm
.endif

.include <bsd.port.post.mk>
