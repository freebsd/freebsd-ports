# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tk
DISTVERSION=	${TK_VERSION}${TK_RC}
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/tcl/Tcl/${TK_VERSION}
PKGNAMESUFFIX=	${SHORT_TK_VER}
DISTNAME=	${PORTNAME}${PORTVERSION}-src

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Graphical toolkit for Tcl

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

OPTIONS_DEFINE=	TKMAN DEMOS THREADS
OPTIONS_DEFAULT=TKMAN THREADS
OPTIONS_SUB=	yes
TKMAN_DESC=	Install Tk function manpages
DEMOS_DESC=	Install demos

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}/unix

ALL_TARGET=	all
INSTALL_TARGET=	install-strip
TEST_TARGET=	test

USES+=		tcl:${SHORT_TK_VER},tea xorg
USE_LDCONFIG=	yes
USE_XORG=	x11 xext xft xrender xscrnsaver
CONFIGURE_ARGS=	--enable-xss \
		--enable-xft \
		--enable-man-suffix=.${MAN_SUFFIX} \
		--includedir=${PREFIX}/include/tk${TK_VER}

CONFIGURE_ENV=	PORTSDIR=${PORTSDIR}

CFLAGS+=	-I${TCL_INCLUDEDIR} \
		-I${LOCALBASE}/include

TK_VERSION=	8.6.9
TK_VER=		${TK_VERSION:R}
TK_RC=		# Nothin
SHORT_TK_VER=	${TK_VER:S/.//}
MAN_SUFFIX=	${PKGBASE}

MAKE_ENV=	SHORT_TK_VER=${SHORT_TK_VER}

PLIST_SUB=	TK_VER=${TK_VER} \
		SHORT_TK_VER=${SHORT_TK_VER}

DEMOS_INSTALL_TARGET=	install-demos
TKMAN_INSTALL_TARGET=	install-doc
THREADS_CONFIGURE_ENABLE=	threads

post-patch:
	${REINPLACE_CMD} -e \
	    's|@TK_BUILD_LIB_SPEC@|@TK_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_SPEC@|@TK_STUB_LIB_SPEC@|; \
	     s|@TK_BUILD_STUB_LIB_PATH@|@TK_STUB_LIB_PATH@|; \
	     s|@TK_SRC_DIR@|${PREFIX}/include/tk${TK_VER}|' \
	     ${WRKSRC}/tkConfig.sh.in
	${REINPLACE_CMD} -e '/^Requires/s|tcl|tcl${SHORT_TK_VER}|' \
	    ${WRKSRC}/tk.pc.in

post-test:
	${ECHO_CMD} "package require Tk" | tclsh${TK_VER}
	${ECHO_CMD} "load libtk${SHORT_TK_VER}.so" | tclsh${TK_VER}

.include <bsd.port.mk>
