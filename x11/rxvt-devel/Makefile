# New ports collection Makefile for: rxvt
# Version required:	2.6.1
# Date created:         5th December 1994
# Whom:                 gpalmer@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	rxvt-2.6.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.rxvt.org/pub/rxvt/ \
		ftp://mason.primenet.com.au/pub/rxvt/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/terms

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS=	--enable-utmp --enable-wtmp \
		--with-xpm --enable-xpm-background --enable-transparency
USE_BZIP2=	yes
MAN1=		rxvt.1

.include <bsd.port.mk>
