# New ports collection makefile for:	Window Manager Improved 2 (snapshot)
# Date created:				02 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmii
DISTVERSION=	snap${SNAPDATE}
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/wmii/
DISTNAME=	wmii+ixp-${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	A dynamic, minimalist window manager for X11

LIB_DEPENDS=	ixp.1:${PORTSDIR}/devel/libixp
RUN_DEPENDS=	dmenu:${PORTSDIR}/x11/dmenu \
		${LOCALBASE}/9/bin/rc:${PORTSDIR}/devel/9base

SNAPDATE=	20090703
CONFLICTS=	wmii-3.*

USE_ICONV=	yes
USE_XORG=	x11 xext xrandr xrender xinerama xft

MAKE_ARGS=	PREFIX="${PREFIX}" INCLUDE="${LOCALBASE}/include" \
		CC="${CC} -c" LD="${CC}" LIBIXP="-lixp" STATIC="" \
		LIBICONV="-liconv" MAN="${MANPREFIX}/man" \
		VERS="3.6.${SNAPDATE}"

MAN1=		wmii.1 wmiir.1 wimenu.1

post-patch: .SILENT
# Link against system libixp and strip debug build options
	${REINPLACE_CMD} -e '/libixp/d' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,-g,-L${LOCALBASE}/lib, ; /^CFLAGS +=/d' \
		${WRKSRC}/config.mk
# Mute "hg: not found" messages
	${REINPLACE_CMD} -e '/^VERS =/d' ${WRKSRC}/mk/wmii.mk
# Make actual compile/link commands appear in the build log; do not try to
# regenerate manpages
	${REINPLACE_CMD} -E -e 's|^COMPILE=|& noisycc=yes | ; \
		s|^LINK=|& noisycc=yes | ; s|\.man1 ||' ${WRKSRC}/mk/hdr.mk

.include <bsd.port.mk>
