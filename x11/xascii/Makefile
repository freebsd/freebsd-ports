# New ports collection makefile for:	xascii
# Date created:			10 April 2012
# Whom:				Cy Schubert <cy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xascii
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/

WRKSRC=		${WRKDIR}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Display an ASCII table in decimal, octal, and hexadecimal.

MAKE_ARGS+=	PREFIX=${PREFIX}
USE_IMAKE=	YES
USE_XORG=	x11 xt xaw
MAN1=		xascii.1
PLIST_FILES=	bin/xascii

.include <bsd.port.mk>
