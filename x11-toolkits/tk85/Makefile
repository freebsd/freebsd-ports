# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.5.19
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	TCLTK/tcl8_5 SF/tcl/Tcl/${PORTVERSION}
PKGNAMESUFFIX=	${SHORT_TK_VER}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical toolkit for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

DEPRECATED=	Tcl/Tk 8.5 is nearing EOL, please consider switching to Tcl/Tk 8.6

USES+=		tcl:${SHORT_TK_VER},tea xorg
USE_XORG=	x11 xft xscrnsaver
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}/unix
TK_VER=		${PORTVERSION:R}
SHORT_TK_VER=	${TK_VER:S/.//}
CONFIGURE_ARGS=	--enable-xss \
		--enable-xft \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tk${TK_VER}

CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} TK_LIB_FILE=libtk${SHORT_TK_VER}.so.1 \
		ac_cv_path_tclsh="${LOCALBASE}/bin/tclsh${TK_VER}"
MAN_SUFFIX=	${PKGBASE}

INSTALL_TARGET=	install
TEST_TARGET=	do-test

MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}
PLIST_SUB=	TK_VER=${TK_VER} SHORT_TK_VER=${SHORT_TK_VER}
NOPRECIOUSMAKEVARS=	yes # Otherwise 'make readmes' is broken
DATADIR=	${PREFIX}/share/${PORTNAME}${TK_VER}
SUB_FILES=	pkgIndex.tcl

OPTIONS_DEFINE=	TK85_MAN DEMOS THREADS
OPTIONS_DEFAULT=TK85_MAN THREADS
OPTIONS_SUB=	yes
TK85_MAN_DESC=	Install tk 8.5 function manpages
DEMOS_DESC=	Install demos

SUB_LIST+=	TCLPATCHLEVEL="${PORTVERSION}"

DATADIR=	${PREFIX}/share/${PORTNAME}${TCL_VER}

THREADS_CONFIGURE_ENABLE=	threads
TK85_MAN_VARS=	INSTALL_TARGET+=install-doc
DEMOS_VARS=	INSTALL_TARGET+=install-demos

TKBASE?=	${PORTSDIR}/${PKGCATEGORY}/${PKGBASE}

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TK_BUILD_LIB_SPEC@|@TK_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_SPEC@|@TK_STUB_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_PATH@|@TK_STUB_LIB_PATH@|; \
	     s|@TK_SRC_DIR@|${PREFIX}/include/tk${TK_VER}|' \
	     ${WRKSRC}/tkConfig.sh.in
	${REINPLACE_CMD} -e '/^Requires/s|tcl|tcl${SHORT_TK_VER}|' \
	    ${WRKSRC}/tk.pc.in
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

do-test:
	cd ${WRKSRC} && ${MAKE} test
	${ECHO_CMD} "package require Tk" | tclsh${TK_VER}
	${ECHO_CMD} "load libtk${SHORT_TK_VER}.so" | tclsh${TK_VER}

.include <bsd.port.mk>
