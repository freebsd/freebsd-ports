# New ports collection makefile for: pwm
# Date created:		02 Oct 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	pwm
PORTVERSION=	1.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.students.tut.fi/~tuomov/dl/

MAINTAINER=	nbm@FreeBSD.org

USE_XLIB=	YES
USE_GMAKE=	YES

MAN1=		pwm.1x

post-patch:
	@perl -i -pe 's#^DOCDIR.*$$#DOCDIR=${PREFIX}/share/doc#' ${WRKSRC}/Makefile
	@perl -i -p \
		-e 's#^PREFIX.*$$#PREFIX=${PREFIX}#;' \
		-e 's#^CC=.*$$#CC=${CC}#;' \
		-e 's#^CFLAGS=-g -O2 (.*)$$#CFLAGS=${CFLAGS} \1#;' \
		-e 's#^LDFLAGS=-g (.*)$$#LDFLAGS=${LDFLAGS} \1#;' \
		${WRKSRC}/system.mk

.include <bsd.port.mk>
