# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.5.16
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_TCLTK} \
		SF/tcl/Tcl/${PORTVERSION}
MASTER_SITE_SUBDIR=tcl8_5
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical toolkit for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES+=		tcl:${SHORT_TK_VER}
USE_XORG=	x11 xft xscrnsaver
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}/unix
GNU_CONFIGURE=	yes
TK_VER=		8.5
SHORT_TK_VER=	85
CONFIGURE_ARGS=	--enable-shared \
		--enable-xss \
		--enable-xft \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--includedir=${PREFIX}/include/tk${TK_VER}

CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} TK_LIB_FILE=libtk${SHORT_TK_VER}.so.1 \
		ac_cv_path_tclsh="${LOCALBASE}/bin/tclsh${TK_VER}"
MAN_SUFFIX=	${LATEST_LINK}

INSTALL_TARGET=	install

MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}
PLIST_SUB=	TK_VER=${TK_VER} SHORT_TK_VER=${SHORT_TK_VER}
NOPRECIOUSMAKEVARS=	yes # Otherwise 'make readmes' is broken
MANCOMPRESSED=	no
DATADIR=	${PREFIX}/share/${PORTNAME}${TK_VER}
SUB_FILES=	pkgIndex.tcl

OPTIONS_DEFINE=	TK85_MAN DEMOS THREADS
OPTIONS_DEFAULT=THREADS
TK85_MAN_DESC=	Install tk 8.5 function manpages
DEMOS_DESC=	Install demos

SUB_LIST+=	TCLPATCHLEVEL="${PORTVERSION}"

.include <bsd.port.pre.mk>

DATADIR=	${PREFIX}/share/${PORTNAME}${TCL_VER}

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

.if ${PORT_OPTIONS:MDEMOS}
INSTALL_TARGET+=	install install-demos
PLIST_SUB+=	DEMOS=""
.else
PLIST_SUB+=	DEMOS="@comment "
.endif

.if ${PORT_OPTIONS:MTK85_MAN}
INSTALL_TARGET+=install-doc
PLIST_SUB+=	MAN=""
.else
PLIST_SUB+=	MAN="@comment "
.endif

TKBASE?=	${PORTSDIR}/${PKGCATEGORY}/${LATEST_LINK}

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TK_BUILD_LIB_SPEC@|@TK_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_SPEC@|@TK_STUB_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_PATH@|@TK_STUB_LIB_PATH@|; \
	     s|@TK_SRC_DIR@|${PREFIX}/include/tk${TK_VER}|' \
	     ${WRKSRC}/tkConfig.sh.in
	@${REINPLACE_CMD} -e 's|X11/Intrinsic.h|X11/Xlib.h|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@TK_SHARED_BUILD@|#@TK_SHARED_BUILD@|g; s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/Makefile.in

post-configure:
	${REINPLACE_CMD} \
		-e 's|${WRKDIRPREFIX}${.CURDIR}|$${WRKDIRPREFIX}${TKBASE}|' \
		${WRKSRC}/tkConfig.sh
	${REINPLACE_CMD} -e 's|-Wl,--rpath -Wl,/usr/local/lib||g' ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${WRKDIR}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/tk${TK_VER}/
	${LN} -fs libtk${SHORT_TK_VER}.so.1.0 \
	    ${STAGEDIR}${PREFIX}/lib/libtk${SHORT_TK_VER}.so.1

regression-test:	build
	cd ${WRKSRC}; ${MAKE} test
	${ECHO_CMD} "package require Tk" | tclsh${TK_VER}
	${ECHO_CMD} "load libtk${SHORT_TK_VER}.so" | tclsh${TK_VER}

.include <bsd.port.post.mk>
