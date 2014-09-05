# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	8.6.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcl/Tcl/${PORTVERSION} \
		${MASTER_SITE_TCLTK}
MASTER_SITE_SUBDIR=tcl8_6
PKGNAMESUFFIX=	${PORTVERSION:R:S/.//}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical toolkit for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=	TKMAN DEMOS THREADS
OPTIONS_DEFAULT=THREADS
TKMAN_DESC=	Install Tk function manpages
DEMOS_DESC=	Install demos
XSS_DESC=	XScrnSaver support

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/unix

ALL_TARGET=	all
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes
USES+=		tcl:${SHORT_TK_VER}
USE_XORG=	x11 xft xscrnsaver
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared \
		--enable-xss \
		--enable-xft \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--with-tcl=${TCL_LIBDIR} \
		--includedir=${PREFIX}/include/tk${TK_VER}

CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}

CFLAGS+=	-I${TCL_INCLUDEDIR} \
		-I${LOCALBASE}/include

TK_VER=		${PORTVERSION:R}
SHORT_TK_VER=	${TK_VER:S/.//}
MAN_SUFFIX=	${LATEST_LINK}

MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}

PLIST_SUB=	TK_VER=${TK_VER} \
		SHORT_TK_VER=${SHORT_TK_VER}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEMOS}
INSTALL_TARGET+=	install-demos
PLIST_SUB+=	DEMOS=""
.else
PLIST_SUB+=	DEMOS="@comment "
.endif

.if ${PORT_OPTIONS:MTKMAN}
INSTALL_TARGET+=install-doc
PLIST_SUB+=	MAN=""
.else
PLIST_SUB+=	MAN="@comment "
.endif

.if ${PORT_OPTIONS:MTHREADS}
CONFIGURE_ARGS+=--enable-threads
.else
CONFIGURE_ARGS+=--disable-threads
.endif

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TK_BUILD_LIB_SPEC@|@TK_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_SPEC@|@TK_STUB_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_PATH@|@TK_STUB_LIB_PATH@|; \
	     s|@TK_SRC_DIR@|${PREFIX}/include/tk${TK_VER}|' \
	     ${WRKSRC}/tkConfig.sh.in

regression-test:	build
	cd ${WRKSRC}; ${MAKE} test
	${ECHO_CMD} "package require Tk" | tclsh${TK_VER}
	${ECHO_CMD} "load libtk${SHORT_TK_VER}.so" | tclsh${TK_VER}

.include <bsd.port.mk>
