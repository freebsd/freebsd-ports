# New ports collection makefile for:	pwm
# Date created:		02 Oct 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	pwm
PORTVERSION=	2003.06.17
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/pwm/dl/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight window manager with emphasis on usability

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	X11_PREFIX="${X11BASE}" HAS_SYSTEM_ASPRINTF=1

MAN1=		pwm.1x

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
