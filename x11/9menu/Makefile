# New ports collection makefile for:    9menu
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	9menu
PORTVERSION=	1.6
CATEGORIES=	x11-wm plan9
MASTER_SITES=	ftp://quenix.dyndns.org/freebsd/ \
		http://mitglied.lycos.de/buran/linux/soft/9menu/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple menu patterened after plan9

USE_XLIB=		yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh
MAKEFILE=		Makefile.noimake
ALL_TARGET=		9menu

MAN1=		9menu.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
