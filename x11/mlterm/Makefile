# New ports collection makefile for:	mlterm
# Date created:		9 December 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	mlterm
PORTVERSION=	2.9.4
PORTREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	SF/${PORTNAME}/01%20release/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Multilingual X11 terminal emulator

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_XORG=	sm
USE_GNOME=	gtk20 lthack
USE_AUTOTOOLS=	libtool:22
LIBTOOLFILES=	configure kiklib/configure mkf/configure
USE_PERL5_BUILD=yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--with-imagelib=gdk-pixbuf --enable-utmp \
		--with-tools="mlclient,mlconfig,mlterm-menu,mlcc,w3mmlconfig" \
		--with-type-engines="xcore,xft"
CONFIGURE_ENV=	LIBS="${LIBS} -L${LOCALBASE}/lib ${PTHREAD_LIBS} -lintl" CFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/iiim"

OPTIONS=	FRIBIDI	"Use Fribidi for BiDi rendering" off \
		UIM "uim support (experimental)" off \
		M17NLIB "m17n library support (experimental)" off \
		IIIMF "IIIMF support (experimental)" off \
		SCIM "SCIM support (experimental)" off

.include <bsd.port.pre.mk>

.if defined(WITH_FRIBIDI)
CONFIGURE_ARGS+=	--enable-fribidi
LIB_DEPENDS+=	fribidi.3:${PORTSDIR}/converters/fribidi
.else
CONFIGURE_ARGS+=	--disable-fribidi
.endif

.if defined(WITH_UIM)
CONFIGURE_ARGS+=	--enable-uim
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	uim.6:${PORTSDIR}/textproc/uim
PLIST_SUB+=	UIM=""
.else
CONFIGURE_ARGS+=	--disable-uim
PLIST_SUB+=	UIM="@comment "
.endif

.if defined(WITH_M17NLIB)
CONFIGURE_ARGS+=	--enable-m17nlib
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	m17n.4:${PORTSDIR}/devel/m17n-lib
PLIST_SUB+=	M17NLIB=""
.else
CONFIGURE_ARGS+=	--disable-m17nlib
PLIST_SUB+=	M17NLIB="@comment "
.endif

.if defined(WITH_IIIMF)
CONFIGURE_ARGS+=	--enable-iiimf
LIB_DEPENDS+=	iiimcf.3:${PORTSDIR}/textproc/iiimf-client-lib
PLIST_SUB+=	IIIMF=""
.else
CONFIGURE_ARGS+=	--disable-iiimf
PLIST_SUB+=	IIIMF="@comment "
.endif

.if defined(WITH_SCIM)
CONFIGURE_ARGS+=	--enable-scim
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	scim-1.0.10:${PORTSDIR}/textproc/scim
PLIST_SUB+=	SCIM=""
.else
CONFIGURE_ARGS+=	--disable-scim
PLIST_SUB+=	SCIM="@comment "
.endif

.if ${OSVERSION} >= 900004
MAKE_ENV=	LIBS_LOCAL=-lutempter
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
