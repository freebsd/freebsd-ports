# New ports collection makefile for:	Window Manager Improved 2
# Date created:				02 Jun 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmii
DISTVERSION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://wmi.modprobe.de/download/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The next generation of WMI window manager

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

MAKE_ARGS=	PREFIX="${PREFIX}" X11DIR="${X11BASE}" CC="${CC}" \
		MANPREFIX="${PREFIX}/man"

OPTIONS=	CAIRO	"Enable Cairo rendering backend"	off \
		STRL	"Use strlcpy()/strlcat() functions"	off

MAN1=		wmibar.1 wmifs.1 wmii.1 wmiinput.1 wmikeys.1 wmiplumb.1 \
		wmir.1 wmiwarp.1
MAN5=		wmii.rc.5

.include <bsd.port.pre.mk>

# The cairo backend is not recommended in production use, because the cairo
# library is still very buggy and causes crashes often.
.if defined(WITH_CAIRO)
LIB_DEPENDS=	cairo.1:${PORTSDIR}/graphics/cairo
MAKE_ARGS+=	DRAW=cairo
.endif

.if defined(WITH_STRL)
MAKE_ARGS+=	STRLCPY="strlcpy" STRLCAT="strlcat"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|' \
		-e 's|/usr/lib|${LOCALBASE}/lib|' \
		-e 's|-O0 -g -Wall -pedantic|${CFLAGS}|; s|-g||' \
		${WRKSRC}/config.mk
.if defined(WITH_CAIRO)
	@${REINPLACE_CMD} -e 's,^#CAIRO,CAIRO,' ${WRKSRC}/config.mk
.endif

.include <bsd.port.post.mk>
