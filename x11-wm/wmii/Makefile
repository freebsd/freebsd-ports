# New ports collection makefile for:	Window Manager Improved 2
# Date created:				02 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmii
DISTVERSION=	3.6
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/wmii/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A dynamic, minimalist window manager for X11

LIB_DEPENDS=	ixp.1:${PORTSDIR}/devel/libixp
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu

CONFLICTS=	wmii-s[0-9]*

USE_XORG=	x11 xextproto xt xext

MAKE_ARGS=	PREFIX="${PREFIX}" INCLUDE="${LOCALBASE}/include" \
		INCX11="-I${LOCALBASE}/include" LIBX11="-L${LOCALBASE}/lib" \
		CC="${CC} -c" LD="${CC}" LIBIXP="-lixp" STATIC="" \
		MAN="${MANPREFIX}/man"

MAN1=		wmii.1 wmiiloop.1 wmiir.1

OPTIONS=	SLIM_LAYOUT_BOX	"Build with slim layout boxes"		 off \
		UTF8_TEXT	"Work with UTF-8 instead of user locale" on

.include <bsd.port.options.mk>

.if defined(WITH_UTF8_TEXT)
USE_ICONV=	yes
MAKE_ARGS+=	LIBICONV="-liconv"
.else
MAKE_ARGS+=	-DNO_UTF8
.endif

.if defined(WITH_SLIM_LAYOUT_BOX)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-slim-layout-boxes
.endif

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|-lfmt -lutf|$${LIBX11} & -lX11|' \
		${WRKSRC}/cmd/Makefile
	${REINPLACE_CMD} -e '/_XOPEN_SOURCE/d' ${WRKSRC}/cmd/wmii/dat.h
# Strip debug build options
	${REINPLACE_CMD} -E 's| -g( -O0)?||' ${WRKSRC}/config.mk
	${REINPLACE_CMD} -e 's|CFLAGS += -DIXPlint|& -DIXP_NEEDAPI=89|' \
		${WRKSRC}/config.mk
# Make actual compile/link commands appear in the build log
	${REINPLACE_CMD} -e 's|^COMPILE=|& noisycc=yes| ; \
		s|^LINK=|& noisycc=yes|' ${WRKSRC}/mk/hdr.mk

.include <bsd.port.mk>
