# New ports collection makefile for:	xnee
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xnee
PORTVERSION=	1.07
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X events recorder and player

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html

USE_X_PREFIX=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		xnee.1
INFO=		xnee xnee_develop

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's| -g | \@CFLAGS\@ |g ; \
		 s|-lpthread|${PTHREAD_LIBS:S/"//g}|g'

post-install:
	${INSTALL_MAN} ${WRKSRC}/xnee/doc/xnee.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
