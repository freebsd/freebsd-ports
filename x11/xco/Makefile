# Created by: Satoshi TAOKA
# $FreeBSD$

PORTNAME=	xco
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	x11
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display X11 color names and colors

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		imake
USE_XORG=	x11 xext
DOCDIR=		${PREFIX}/share/doc/xco

post-patch:
		@${REINPLACE_CMD} -e 's/extern char \*malloc();//g' \
			${WRKSRC}/xco.c ${WRKSRC}/xargs.c

post-install:
		@${MKDIR} ${STAGEDIR}${DOCDIR}
		@${INSTALL_DATA} ${FILESDIR}/copyright ${STAGEDIR}${DOCDIR}

.include <bsd.port.mk>
