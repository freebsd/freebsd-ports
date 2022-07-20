PORTNAME=	tk
DISTVERSION=	${TK_VERSION}${TK_RC}
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcl/Tcl/${TK_VERSION} \
		TCLTK/tcl8_7
PKGNAMESUFFIX=	${SHORT_TK_VER}
DISTNAME=	${PORTNAME}${DISTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical toolkit for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig
BUILD_DEPENDS=	zip:archivers/zip

OPTIONS_DEFINE=	TKMAN DEMOS
OPTIONS_SUB=	yes
TKMAN_DESC=	Install Tk function manpages
DEMOS_DESC=	Install demos

PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}${TK_VERSION}
WRKSRC=		${PATCH_WRKSRC}/unix

ALL_TARGET=	all
INSTALL_TARGET=	install-strip install-libraries

USES+=		tcl:${SHORT_TK_VER},tea xorg
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xft xrender xscrnsaver
CONFIGURE_ARGS=	--enable-xss \
		--enable-xft \
		--enable-shared \
		--enable-threads \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tk${TK_VER}

CFLAGS+=	-I${TCL_INCLUDEDIR} \
		-I${LOCALBASE}/include

TK_VERSION=	8.7a5
TK_VER=		8.7
TK_RC=
SHORT_TK_VER=	${TK_VER:S/.//}
MAN_SUFFIX=	${PKGBASE}

MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}

PLIST_SUB=	TK_VER=${TK_VER} \
		PKGNAMESUFFIX=${PKGNAMESUFFIX}

DEMOS_INSTALL_TARGET=	install-demos
TKMAN_INSTALL_TARGET=	install-doc

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TK_BUILD_LIB_SPEC@|@TK_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_SPEC@|@TK_STUB_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_PATH@|@TK_STUB_LIB_PATH@|; \
	     s|@TK_SRC_DIR@|${PREFIX}/include/tk${TK_VER}|' \
	     ${WRKSRC}/tkConfig.sh.in

post-install:
	# Make sure users of USES=tk:87 are able to look up the library
	${LN} -fs libtk${TK_VER}.so ${STAGEDIR}${PREFIX}/lib/libtk${PKGNAMESUFFIX}.so
	${LN} -fs libtk${PKGNAMESUFFIX}.so ${STAGEDIR}${PREFIX}/lib/libtk${PKGNAMESUFFIX}.so.1

test:
	cd ${WRKSRC}; ${MAKE} test
	${ECHO_CMD} "package require Tk" | tclsh${TK_VER}
	${ECHO_CMD} "load libtk${SHORT_TK_VER}.so" | tclsh${TK_VER}

.include <bsd.port.mk>
