# Created by: incabulos@mac.com
# $FreeBSD$

PORTNAME=	xrootconsole
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Writes any log live onto the background

USES=		gmake xorg
USE_XORG=	x11

PLIST_FILES=	bin/xrootconsole man/man1/xrootconsole.1.gz
post-patch:
	@${REINPLACE_CMD} -e 's|^CC =|CC ?=|g ; \
		 s|^CFLAGS = -O2|CFLAGS +=|g ; \
		 s|/usr/X11R6|$${LOCALBASE}|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xrootconsole ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrootconsole.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
