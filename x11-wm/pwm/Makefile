# New ports collection makefile for:	pwm
# Date created:		02 Oct 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	pwm
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	nbm@FreeBSD.org
COMMENT=	A lightweight window manager with emphasis on usability

USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes

MAN1=		pwm.1x

post-patch:
	@${PERL} -pi \
		-e 's#^PREFIX.*$$#PREFIX=${PREFIX}#;' \
		-e 's#^X11_PREFIX.*$$#X11_PREFIX=${X11BASE}#;' \
		-e 's#^CC=.*$$#CC=${CC}#;' \
		-e 's#^CFLAGS=-g -O2 (.*)$$#CFLAGS=${CFLAGS} \1#;' \
		-e 's#^LDFLAGS=-g (.*)$$#LDFLAGS=${LDFLAGS} \1#;' \
		${WRKSRC}/system.mk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pwm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pwm.1x ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/etc/pwm
	${INSTALL_DATA} ${WRKSRC}/etc/pwm/*.conf ${PREFIX}/etc/pwm
.if !exists(${PREFIX}/etc/pwm/pwm.conf)
	${CP} ${PREFIX}/etc/pwm/sample.conf ${PREFIX}/etc/pwm/pwm.conf
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/pwm
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/pwm
	${INSTALL_DATA} ${WRKSRC}/config.txt ${PREFIX}/share/doc/pwm
.endif

.include <bsd.port.mk>
