# New ports collection makefile for:    9term
# Version required:     1.6.3
# Date created:         Sun Aug 13 12:36:14 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.12 1999/01/11 03:14:09 asami Exp $
#

DISTNAME=       9term.1.6.3
PKGNAME=	9term-1.6.3
CATEGORIES=	x11 plan9
MASTER_SITES=   ftp://ftp.ecf.toronto.edu/pub/plan9/matty/

MAINTAINER=	erich@FreeBSD.org

# needs library and private header, but not during runtime
BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/editors/sam:build

USE_XLIB=	yes
MAN1=		9term.1
MANCOMPRESSED=	yes
MAKE_ENV=	SAMDIR=${WRKDIRPREFIX}${.CURDIR}/../../editors/sam/work
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
