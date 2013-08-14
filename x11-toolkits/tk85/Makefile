# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.5.14
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcl/Tcl/${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical toolkit for Tcl

LICENSE=	BSD

LICENSE_TERMS=	${WRKSRC}/../license.terms

LATEST_LINK=	tk85
USE_XORG=	x11
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}/unix
GNU_CONFIGURE=	yes
TK_VER=		8.5
SHORT_TK_VER=	85
CONFIGURE_ARGS=	--enable-shared --with-tcl=${TCL_LIBDIR} \
		--includedir=${PREFIX}/include/tk${TK_VER} \
		--enable-man-suffix=.${MAN_SUFFIX}
CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} TK_LIB_FILE=libtk${SHORT_TK_VER}.so.1 \
		ac_cv_path_tclsh="${LOCALBASE}/bin/tclsh${TK_VER}"
LATEST_LINK=	${PORTNAME}${SHORT_TK_VER}
MAN_SUFFIX=	${LATEST_LINK}

INSTALL_TARGET=	install

MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}
PLIST_SUB=	TK_VER=${TK_VER} SHORT_TK_VER=${SHORT_TK_VER}
NOPRECIOUSMAKEVARS=	yes # Otherwise 'make readmes' is broken
MANCOMPRESSED=	no
DATADIR=	${PREFIX}/share/${PORTNAME}${TK_VER}
SUB_FILES=	pkgIndex.tcl


USE_TCL=	${SHORT_TK_VER}

OPTIONS_DEFINE=	TK85_MAN XFT DEMOS THREADS
OPTIONS_DEFAULT=	XFT THREADS
TK85_MAN_DESC=	Install tk 8.5 function manpages
XFT_DESC=	Use Xft fonts
DEMOS_DESC=	Install demos

SUB_LIST+=	TCLPATCHLEVEL="${PORTVERSION}"

.include <bsd.port.pre.mk>

DATADIR=	${PREFIX}/share/${PORTNAME}${TCL_VER}

.if ${PORT_OPTIONS:MXFT}
CONFIGURE_ARGS+=	--enable-xft
LIB_DEPENDS+=	Xft:${PORTSDIR}/x11-fonts/libXft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

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
.include "${.CURDIR}/Makefile.man"
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
	${INSTALL_DATA} ${WRKDIR}/pkgIndex.tcl ${PREFIX}/lib/tk${TK_VER}/

regression-test:	build
	cd ${WRKSRC}; ${MAKE} test
	${ECHO_CMD} "package require Tk" | tclsh${TK_VER}
	${ECHO_CMD} "load libtk${SHORT_TK_VER}.so" | tclsh${TK_VER}

.include <bsd.port.post.mk>
