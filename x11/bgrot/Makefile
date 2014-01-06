# Created by: Matthew Fuller <fullermd@futuresouth.com>
# $FreeBSD$

PORTNAME=	bgrot
PORTVERSION=	1.30
PORTREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://www.over-yonder.net/~fullermd/projects/bgrot/ \
		http://distfiles.over-yonder.net/bgrot/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Program to handle your X background to prevent boredom

USE_XORG=	xv
USES=		shebangfix perl5 uidfix
SHEBANG_FILES=	*.pl
MAKE_ARGS=	BINDIR=${STAGEDIR}${PREFIX}/bin \
		MANDIR=${STAGEDIR}${MANPREFIX}/man/ \
		BINOWN="${BINOWN}" \
		BINGRP="${BINGRP}"

.include <bsd.port.mk>
