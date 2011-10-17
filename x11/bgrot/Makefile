# New ports collection makefile for: bgrot
# Date created:			12 January 1999
# Whom:				Matthew Fuller <fullermd@futuresouth.com>
#
# $FreeBSD$
#

PORTNAME=	bgrot
PORTVERSION=	1.30
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://www.over-yonder.net/~fullermd/projects/bgrot/ \
		http://distfiles.over-yonder.net/bgrot/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	A program to handle your X background to prevent boredom

RUN_DEPENDS=	xv:${PORTSDIR}/graphics/xv

USE_PERL5=	yes

MAN1=		bgrot.1
MANCOMPRESSED=	yes

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
