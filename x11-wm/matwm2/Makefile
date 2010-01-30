# New ports collection makefile for:   matwm2
# Date created:        09 September 2009
# Whom:                Mattis Michel <sic_zer0@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	matwm2
PORTVERSION=	0.1.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.squidjam.com/matwm/pub/

MAINTAINER=	sic_zer0@hotmail.com
COMMENT=	A minimalistic, yet functional window manager for x11

USE_XORG=	x11 xext xinerama xft

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc=${CC} --prefix=${PREFIX} --mandir=${MANPREFIX}/man

PLIST_FILES=	bin/matwm2
MAN1=	matwm2.1

.include <bsd.port.mk>
