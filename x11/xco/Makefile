# Created by: Satoshi TAOKA
# $FreeBSD$

PORTNAME=	xco
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	x11
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display X11 color names and colors

USES=		imake
USE_XORG=	x11 xext
MAN1=		xco.1
MANCOMPRESSED=	yes
DOCDIR=		${PREFIX}/share/doc/xco

post-patch:
		@${REINPLACE_CMD} -e 's/extern char \*malloc();//g' \
			${WRKSRC}/xco.c ${WRKSRC}/xargs.c

post-install:
		@${MKDIR} ${DOCDIR}
		@${INSTALL_DATA} ${FILESDIR}/copyright ${DOCDIR}

.include <bsd.port.mk>
