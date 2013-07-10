# Created by: Cy Schubert <cy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xforward
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://komquats.com/distfiles/ \
		http://people.freebsd.org/~cy/distfiles/
DISTNAME=	${PORTNAME}

WRKSRC=		${WRKDIR}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Provide user-level X forwarding service

LICENSE_FILE=	${WRKSRC}/NOTICE

MAKE_ARGS+=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}
USE_XORG=	x11 xt xaw
USES=		motif
MAN1=		xforward.1
PLIST_FILES=	bin/xforward

.include <bsd.port.mk>
