# New ports collection makefile for:    9term
# Date created:		Sun Aug 13 12:36:14 CDT 1995
# Whom:			erich@rrnet.com
#
# $FreeBSD$
#

PORTNAME=	9term
PORTVERSION=	1.6.3
CATEGORIES=	x11 plan9
MASTER_SITES=	ftp://ftp.cs.usyd.edu.au/matty/unicode/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

# needs library and private header, but not during runtime
BUILD_DEPENDS=	/nonexistent:${PORTSDIR}/editors/sam:build

NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes
MAKE_ENV=	SAMDIR=${WRKDIRPREFIX}${.CURDIR}/../../editors/sam/work
MAN1=		9term.1

.include <bsd.port.mk>
