# New ports collection makefile for:    fbdesk
# Date created: 16 January 2003
# Whom: Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$
#

PORTNAME=	fbdesk
PORTVERSION=	1.1.5
CATEGORIES=	x11-wm
MASTER_SITES=	http://fluxbox.sourceforge.net/download/

MAINTAINER=	hendrik@scholz.net
COMMENT=	A Fluxbox utility to create and manage icons on the desktop

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		Xft.2:${PORTSDIR}/x11-fonts/Xft

PLIST_FILES=	bin/fbdesk
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
USE_REINPLACE=	yes
post-patch:
	${REINPLACE_CMD} -e "s/inttypes\.h/stdint\.h/" \
		${WRKSRC}/src/FbTk/Timer.hh
.endif

.include <bsd.port.post.mk>
