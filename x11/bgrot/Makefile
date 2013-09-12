# Created by: Matthew Fuller <fullermd@futuresouth.com>
# $FreeBSD$

PORTNAME=	bgrot
PORTVERSION=	1.30
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://www.over-yonder.net/~fullermd/projects/bgrot/ \
		http://distfiles.over-yonder.net/bgrot/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	A program to handle your X background to prevent boredom

RUN_DEPENDS=	xv:${PORTSDIR}/graphics/xv

USES=		shebangfix perl5
SHEBANG_FILES=	*.pl

MAN1=		bgrot.1
MANCOMPRESSED=	yes

post-install:
	@${CAT} pkg-message

.include <bsd.port.mk>
