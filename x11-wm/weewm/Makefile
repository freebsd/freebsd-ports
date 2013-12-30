# Created by: Pierre-Paul Lavoie <ppl@nbnet.nb.ca>
# $FreeBSD$

PORTNAME=	weewm
PORTVERSION=	0.0.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://weewm.flashtux.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast and ultra light windowmanager with total keyboard control

PLIST_FILES=	bin/weewm
USE_XORG=	x11

post-patch:
	@${REINPLACE_CMD} -e 's,^CC=,CC?=,' -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/weewm ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
