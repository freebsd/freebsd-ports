# New ports collection makefile for:	libxcb
# Date Created:				2006-08-23
# Whom:					Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libxcb
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	wahjava@gmail.com
COMMENT=	The X protocol C-language Binding (XCB) library

BUILD_DEPENDS=	${LIB_PC_DEPENDS} \
		${LOCALBASE}/lib/libcheck.a:${PORTSDIR}/devel/libcheck \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		doxygen:${PORTSDIR}/devel/doxygen \
		dot:${PORTSDIR}/graphics/graphviz
RUN_DEPENDS=	${LIB_PC_DEPENDS}

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig
USE_GMAKE=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-check=${LOCALBASE}
.for f in XPROTO_CFLAGS XPROTO_LIBS XDMCP_CFLAGS XDMCP_LIBS NEEDED_CFLAGS NEEDED_LIBS
CONFIGURE_ARGS+=${f}="${${f}}"
.endfor
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"

LIB_PC_DEPENDS=	${X11BASE}/libdata/pkgconfig/xcb-proto.pc:${PORTSDIR}/x11/xcb-proto \
	${LOCALBASE}/libdata/pkgconfig/pthread-stubs.pc:${PORTSDIR}/devel/libpthread-stubs

PTHREAD_STUBS_LIBS!=	pkg-config --libs pthread-stubs

NEEDED_CFLAGS=	-I${X11BASE}/include
NEEDED_LIBS=	-L${X11BASE}/lib -lXau $(PTHREAD_STUBS_LIBS)

XDMCP_CFLAGS=	-I${X11BASE}/include
XDMCP_LIBS=	-L${X11BASE}/lib -lXdmcp

XPROTO_CFLAGS=	-I${X11BASE}/include
XPROTO_LIBS=	-L${X11BASE}/lib

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__xcb.h \
		${FILESDIR}/extra-patch-src__xcb_auth.c
.endif

post-build:
	DISPLAY= ${GMAKE} -C ${WRKSRC} check

.include <bsd.port.post.mk>
