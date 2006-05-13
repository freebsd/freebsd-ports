# New ports collection makefile for:	mlterm
# Date created:		9 December 2001
# Whom:			MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	mlterm
PORTVERSION=	2.9.2
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Multilingual X11 terminal emulator

USE_X_PREFIX=	yes
USE_GNOME=	gtk20 lthack
USE_AUTOTOOLS=	libtool:15
LIBTOOLFILES=	configure kiklib/configure mkf/configure
USE_PERL5_BUILD=yes
CONFIGURE_ARGS=	--with-imagelib=gdk-pixbuf --enable-utmp \
		--with-tools="mlclient,mlconfig,mlterm-menu,mlcc,w3mmlconfig"
CONFIGURE_ENV=	LIBS=-L${LOCALBASE}/lib CFLAGS=-I${LOCALBASE}/include

OPTIONS=	FRIBIDI	"Use Fribidi for BiDi rendering" off \
		UIM "uim support" off \
		M17NLIB "m17n library support" off \
		IIIMF "IIIMF support (broken)" off

.include <bsd.port.pre.mk>

.if defined(WITH_FRIBIDI)
CONFIGURE_ARGS+=	--enable-fribidi
LIB_DEPENDS+=	fribidi.0:${PORTSDIR}/converters/fribidi
.endif

.if defined(WITH_UIM)
CONFIGURE_ARGS+=	--enable-uim
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	uim.1:${PORTSDIR}/textproc/uim
PLIST_SUB+=	UIM=""
.else
PLIST_SUB+=	UIM="@comment "
.endif

.if defined(WITH_M17NLIB)
CONFIGURE_ARGS+=	--enable-m17nlib
MAKE_ENV=	LIBS_LOCAL=-L${LOCALBASE}/lib
LIB_DEPENDS+=	m17n.1:${PORTSDIR}/devel/m17n-lib
PLIST_SUB+=	M17NLIB=""
.else
PLIST_SUB+=	M17NLIB="@comment "
.endif

.if defined(WITH_IIIMF)
.if ${OSVERSION} < 500043
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-inputmethod:iiimf:im_iiimf.c
.endif

CONFIGURE_ARGS+=	--enable-iiimf
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" CFLAGS=-I${LOCALBASE}/include
MAKE_ENV=	LIBS_LOCAL="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" CFLAGS_LOCAL="-I${LOCALBASE}/include/iiimf -I${LOCALBASE}/include/iiimf/iiimp"
LIB_DEPENDS+=	iiimcf.2:${PORTSDIR}/textproc/iiimf-client-lib
PLIST_SUB+=	IIIMF=""
.else
PLIST_SUB+=	IIIMF="@comment "
.endif

INSTALLS_SHLIB=	yes

MAN1=	mlterm.1 mlclient.1

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
PKGNAMESUFFIX=	-noaa
.else
CONFIGURE_ARGS+=	--enable-anti-alias
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
.endif

post-configure:
	@${CP} ${LIBTOOL} ${WRKSRC}
	@${REINPLACE_CMD} -e "s,@CGI_BIN@,${PREFIX}/libexec/w3mmlconfig," \
		${WRKSRC}/tool/w3mmlconfig/mlconfig.cgi

post-install:
	(cd ${WRKSRC}/tool/w3mmlconfig; ${MAKE} install)
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/mlterm
	${INSTALL_DATA} ${WRKSRC}/doc/ja/README.ja ${PREFIX}/share/doc/ja/mlterm
.endif

.include <bsd.port.post.mk>
