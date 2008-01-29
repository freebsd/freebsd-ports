# New ports collection makefile for:	Window Manager Improved 2
# Date created:				02 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmii
DISTVERSION=	3.6
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.suckless.org/download/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A dynamic, minimalist window manager for X11

LIB_DEPENDS=	ixp.1:${PORTSDIR}/devel/libixp
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu \
		${LOCALBASE}/9/bin/rc:${PORTSDIR}/devel/9base

CONFLICTS=	wmii-3.5.*

USE_ICONV=	yes
USE_XLIB=	yes

MAKE_ARGS=	PREFIX="${PREFIX}" INCLUDE="${LOCALBASE}/include" \
		INCX11="-I${X11BASE}/include" LIBX11="-L${X11BASE}/lib" \
		CC="${CC} -c" LD="${CC}" LIBIXP="-lixp" STATIC="" \
		LIBICONV="-liconv" MAN="${MANPREFIX}/man"

MAN1=		wmii.1 wmiiloop.1 wmiir.1

post-patch: .SILENT
	${REINPLACE_CMD} -e 's|-lfmt -lutf|$${LIBX11} & -lX11|' \
		${WRKSRC}/cmd/Makefile
# Strip debug build options
	${REINPLACE_CMD} -E 's| -g( -O0)?||' ${WRKSRC}/config.mk
# Make actual compile/link command appear in the build log
	${REINPLACE_CMD} -e 's|^COMPILE=|& noisycc=yes | ; \
		s|^LINK=|& noisycc=yes |' ${WRKSRC}/mk/hdr.mk

.include <bsd.port.mk>
