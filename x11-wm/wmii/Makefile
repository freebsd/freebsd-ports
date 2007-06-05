# New ports collection makefile for:	Window Manager Improved 2
# Date created:				02 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmii
DISTVERSION=	3.5.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.suckless.org/download/ CENKES

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A dynamic, minimalist window manager for X11

LIB_DEPENDS=	ixp.0:${PORTSDIR}/devel/libixp
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu \
		${LOCALBASE}/9/bin/rc:${PORTSDIR}/devel/9base

CONFLICTS=	wmii-3.5.[2-9]*

MAKE_ARGS=	PREFIX="${PREFIX}" X11LIB="${X11BASE}/lib" \
		X11INC="${X11BASE}/include" CC="${CC}" \
		MANPREFIX="${MANPREFIX}/man"

MAN1=		wmii.1 wmiir.1 wmiiwm.1

post-patch: .SILENT
	${REINPLACE_CMD} -E 's|-Os|${CFLAGS}|; \
		s|(-[LI])\$${PREFIX}|\1${LOCALBASE}|' \
		${WRKSRC}/config.mk
	# Catch up with recent libixp
	${REINPLACE_CMD} -E 's|\.data\.[[:alpha:]]+||g' \
		${WRKSRC}/fs.c

.include <bsd.port.mk>
