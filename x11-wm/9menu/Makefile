# New ports collection makefile for:    9menu
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	9menu
PORTVERSION=	1.5
CATEGORIES=	x11-wm plan9
MASTER_SITES=	ftp://ftp.comintern.ru/pub/unix/X11/plan9/ \
		ftp://ftp.mathcs.emory.edu/pub/arnold/
		
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

MAN1=		9menu.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
