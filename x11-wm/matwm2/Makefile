# Created by: Mattis Michel <sic_zer0@hotmail.com>
# $FreeBSD$

PORTNAME=	matwm2
DISTVERSION=	0.1.2pre3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.squidjam.com/matwm/pub/

MAINTAINER=	sic_zer0@hotmail.com
COMMENT=	Minimalistic, yet functional window manager for X11

LICENSE=	MIT

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc=${CC} --prefix=${PREFIX} --mandir=${MANPREFIX}/man
USE_XORG=	x11 xext xinerama xft

PLIST_FILES=	bin/matwm2
MAN1=		matwm2.1

.include <bsd.port.mk>
