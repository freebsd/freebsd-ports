# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.4.20
PORTEPOCH=	2
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	TCLTK/tcl8_4 SF/tcl/Tcl/${PORTVERSION}
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical toolkit for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	TKMAN THREADS
OPTIONS_DEFAULT=THREADS
TKMAN_DESC=	Install Tk function manpages

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/unix

ALL_TARGET=	all
INSTALL_TARGET=	install

USES+=		tcl:${SHORT_TK_VER},tea
USE_LDCONFIG=	yes
USE_XORG=	x11
CFLAGS+=	-I${TCL_INCLUDEDIR}/generic
CONFIGURE_ARGS=	--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tk${TK_VER}

CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} TK_LIB_FILE=libtk${SHORT_TK_VER}.so.1

CFLAGS+=	-I${TCL_INCLUDEDIR}

TK_VER=		${PORTVERSION:R}
SHORT_TK_VER=	${TK_VER:S/.//}
MAN_SUFFIX=	${PKGBASE}

MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}

PLIST_SUB=	TK_VER=${TK_VER} \
		SHORT_TK_VER=${SHORT_TK_VER}

SUB_FILES=	pkgIndex.tcl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTKMAN}
INSTALL_TARGET+=install-doc
PLIST_SUB+=	MAN=""
.else
PLIST_SUB+=	MAN="@comment "
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TK_BUILD_LIB_SPEC@|@TK_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_SPEC@|@TK_STUB_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_PATH@|@TK_STUB_LIB_PATH@|; \
	     s|@TK_SRC_DIR@|${PREFIX}/include/tk${TK_VER}|' \
	     ${WRKSRC}/tkConfig.sh.in
	@${REINPLACE_CMD} -e 's|X11/Intrinsic.h|X11/Xlib.h|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@TK_SHARED_BUILD@|#@TK_SHARED_BUILD@|g' ${WRKSRC}/Makefile.in

post-configure:
	${REINPLACE_CMD} -e 's|${WRKDIRPREFIX}${.CURDIR}|$${WRKDIRPREFIX}${TKBASE}|' \
		${WRKSRC}/tkConfig.sh

post-install:
	${INSTALL_DATA} ${WRKDIR}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/tk${TK_VER}/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/wish${TK_VER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libtk${SHORT_TK_VER}.so.1

regression-test:	build
	cd ${WRKSRC}; ${MAKE} test
	${ECHO_CMD} "package require Tk" | tclsh${TK_VER}
	${ECHO_CMD} "load libtk${SHORT_TK_VER}.so" | tclsh${TK_VER}

.include <bsd.port.mk>
