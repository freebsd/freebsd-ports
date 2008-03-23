# ex:ts=18
# New ports collection makefile for:  numlockx
# Whom:                               Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# Date Created:                       2003-09-09 16:05:29
#
# $FreeBSD$
#

PORTNAME=	numlockx
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://ktown.kde.org/~seli/numlockx/ \
		http://caraldi.com/jbq/numlockx/

MAINTAINER=	jb.quenot@caraldi.com
COMMENT=	This little thingy allows you to start X with NumLock turned on

GNU_CONFIGURE=	yes
USE_XORG=	x11 xext
PLIST_FILES=	bin/numlockx

# Needed for the "configure" program to find XTest and XKB header files
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include"

.include <bsd.port.mk>
