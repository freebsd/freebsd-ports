# Created by: Neil Blakey-Milner
# $FreeBSD$

PORTNAME=	pwm
PORTVERSION=	2007.07.20
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/ \
		http://schot.a-eskwadraat.nl/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	A lightweight window manager with emphasis on usability

USE_XORG=	x11
USES=		gmake
MAKE_ENV=	X11_PREFIX="${LOCALBASE}" HAS_SYSTEM_ASPRINTF=1

MAN1=		pwm.1x

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX=|PREFIX?=|g ; \
		 s|^X11_PREFIX=|X11_PREFIX?=|g ; \
		 s|^CC=|CC?=|g ; \
		 s|^CFLAGS=-g -O2|CFLAGS+=|g ; \
		 s|^LDFLAGS=-g|LDFLAGS=|g ; \
		 s|-pedantic-errors||g' ${WRKSRC}/system.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pwm.1x ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/etc/pwm
	${INSTALL_DATA} ${WRKSRC}/etc/pwm/*.conf ${PREFIX}/etc/pwm
.if !exists(${PREFIX}/etc/pwm/pwm.conf)
	${CP} ${PREFIX}/etc/pwm/sample.conf ${PREFIX}/etc/pwm/pwm.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/config.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
