PORTNAME=	tk
DISTVERSION=	9.1.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcl/Tcl/${DISTVERSION}
DISTNAME=	${PORTNAME}${DISTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical toolkit for Tcl
WWW=		https://www.tcl.tk/

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libcups.so:print/cups

OPTIONS_DEFINE=	TKMAN DEMOS
OPTIONS_SUB=	yes
TKMAN_DESC=	Install Tk function manpages
DEMOS_DESC=	Install demos

WRKSRC=		${WRKDIR}/${PORTNAME}${DISTVERSION}
WRKSRC_SUBDIR=	unix

ALL_TARGET=	all
INSTALL_TARGET=	install-libraries
TEST_TARGET=	test

TK_VER=		${DISTVERSION:R}
USES+=		tcl:${TK_VER:S/.//},tea pkgconfig xorg
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xft xrender xscrnsaver
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-xss \
		--enable-xft \
		--enable-shared \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tk${TK_VER}
PLIST_SUB=	TK_VER=${TK_VER}

CFLAGS+=	-I${TCL_INCLUDEDIR} \
		-I${LOCALBASE}/include

MAN_SUFFIX=	${PORTNAME}

DEMOS_INSTALL_TARGET=	install-demos
TKMAN_INSTALL_TARGET=	install-doc

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-symbols
INSTALL_TARGET+=install
.else
INSTALL_TARGET+=install-strip
.endif

post-patch:
	${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	${REINPLACE_CMD} -e \
	    's|@TK_BUILD_LIB_SPEC@|@TK_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_SPEC@|@TK_STUB_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_PATH@|@TK_STUB_LIB_PATH@|; \
	     s|@TK_SRC_DIR@|${PREFIX}/lib/tk${TK_VER}|' \
	     ${WRKSRC}/tkConfig.sh.in
	${REINPLACE_CMD} \
		-e '/^CONFIG_INSTALL_DIR/s|= .*$$|= $${SCRIPT_INSTALL_DIR}|' \
		-e 's|$$(LIB_INSTALL_DIR)/pkgconfig|${STAGEDIR}${PREFIX}/libdata/pkgconfig|g' \
		-e 's|strip -x|strip --strip-unneeded|' \
		-e 's|TCL_BUILD_LIB_SPEC|TCL_LIB_SPEC|' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} \
		-e '/Target=/s|.$$Section$$Suffix|$$Suffix.$$Section|' \
		${WRKSRC}/installManPage

post-install:
	# Make sure users of USES=tk:90 are able to look up the library
	${LN} -fs lib${TCL_PKG_LIB_PREFIX}tk${TK_VER}.so ${STAGEDIR}${PREFIX}/lib/libtk${TK_VER}.so

do-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>
