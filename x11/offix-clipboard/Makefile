# ports collection makefile for: Clipboard
# Date created:      28 Jun 1997
# Whom:              Ruslan Shevchenko <ruslan@shevchenko.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	offix-clipboard
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	desktop_managers/OffiX
DISTNAME=	Clipboard-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X clipboard with support of DND protocol

DEPRECATED=	development ceased in 1996
EXPIRATION_DATE=2006-11-05

LIB_DEPENDS=	Dnd.1:${PORTSDIR}/x11/libdnd

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X_PREFIX=	YES
MAN1=		clipboard.1
PLIST_FILES=	bin/clipboard

.include <bsd.port.mk>
