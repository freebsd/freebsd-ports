# New ports collection makefile for:	Window Manager Improved 2
# Date created:				02 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmii
DISTVERSION=	3.6
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/wmii/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A dynamic, minimalist window manager for X11

LIB_DEPENDS=	ixp.1:${PORTSDIR}/devel/libixp
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu \
		${LOCALBASE}/9/bin/rc:${PORTSDIR}/devel/9base

CONFLICTS=	wmii-s*

USE_ICONV=	yes
USE_XORG=	x11 xextproto xt xext

MAKE_ARGS=	PREFIX="${PREFIX}" INCLUDE="${LOCALBASE}/include" \
		INCX11="-I${LOCALBASE}/include" LIBX11="-L${LOCALBASE}/lib" \
		CC="${CC} -c" LD="${CC}" LIBIXP="-lixp" STATIC="" \
		LIBICONV="-liconv" MAN="${MANPREFIX}/man"

MAN1=		wmii.1 wmiiloop.1 wmiir.1

OPTIONS=	LAYOUT_BOXES "Show layout boxes (some people hate them)" on

.include <bsd.port.options.mk>

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|-lfmt -lutf|$${LIBX11} & -lX11|' \
		${WRKSRC}/cmd/Makefile
# Strip debug build options
	${REINPLACE_CMD} -E 's| -g( -O0)?||' ${WRKSRC}/config.mk
	${REINPLACE_CMD} -e 's|CFLAGS += -DIXPlint|& -DIXP_NEEDAPI=89|' \
		${WRKSRC}/config.mk
# Make actual compile/link commands appear in the build log
	${REINPLACE_CMD} -e 's|^COMPILE=|& noisycc=yes| ; \
		s|^LINK=|& noisycc=yes|' ${WRKSRC}/mk/hdr.mk
.if defined(WITHOUT_LAYOUT_BOXES)
	${REINPLACE_CMD} -e '102,104d' ${WRKSRC}/cmd/wmii/column.c
.endif

.include <bsd.port.mk>
