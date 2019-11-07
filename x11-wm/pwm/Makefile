# Created by: Neil Blakey-Milner
# $FreeBSD$

PORTNAME=	pwm
PORTVERSION=	2007.07.20
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/ \
		http://schot.a-eskwadraat.nl/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	lightweight window manager with emphasis on usability

USES=		gmake xorg
USE_XORG=	x11
MAKE_ENV=	X11_PREFIX="${LOCALBASE}" HAS_SYSTEM_ASPRINTF=1

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX=|PREFIX?=|g ; \
		 s|^X11_PREFIX=|X11_PREFIX?=|g ; \
		 s|^CC=|CC?=|g ; \
		 s|^CFLAGS=-g -O2|CFLAGS+=|g ; \
		 s|^LDFLAGS=-g|LDFLAGS=|g ; \
		 s|-pedantic-errors||g' ${WRKSRC}/system.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pwm.1x ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pwm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pwm/*.conf ${STAGEDIR}${PREFIX}/etc/pwm
	${MV} ${STAGEDIR}${PREFIX}/etc/pwm/sample.conf ${STAGEDIR}${PREFIX}/etc/pwm/pwm.conf.sample
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/config.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
