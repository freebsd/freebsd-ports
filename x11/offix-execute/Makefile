# ports collection makefile for:	Execute
# Date created:		28 Jun 1997
# Whom:			Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	offix-execute
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	x11 offix
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX
DISTNAME=	Execute-${PORTVERSION}

MAINTAINER=	ruslan@shevchenko.kiev.ua
COMMENT=	Files executor from OffiX

LIB_DEPENDS=	Dnd.1:${PORTSDIR}/x11/libdnd

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X_PREFIX=	YES
USE_XPM=	YES

.include <bsd.port.mk>
