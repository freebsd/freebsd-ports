# New ports collection makefile for:    9menu
# Version required:     1.5
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.6 1998/11/21 17:18:12 steve Exp $
#

DISTNAME=	9menu-1.5
CATEGORIES=	plan9 misc
MASTER_SITES=	ftp://ftp.mathcs.emory.edu/pub/arnold/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	erich@FreeBSD.org

USE_XLIB=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

MAN1=		9menu.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
