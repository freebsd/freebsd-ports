# New ports collection Makefile for: rxvt
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#
# If possible, please consider updating the simple ports/x11-clocks/rclock
# (and maybe ports/chinese/rxvt) when you upgrade rxvt.  These ports all use
# the same distfile.

PORTNAME=	rxvt
PORTVERSION= 	2.7.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/ \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/terms

PATCH_SITES=	ftp://ftp.rxvt.org/pub/rxvt/
PATCHFILES=	rxvt-2.7.3.patch1.gz
PATCH_DIST_STRIP+=      -p1

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--enable-utmp --enable-wtmp \
		--with-xpm --enable-xpm-background --enable-transparency
USE_BZIP2=	yes
MAN1=		rxvt.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/rxvt

.include <bsd.port.mk>
