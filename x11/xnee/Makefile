# New ports collection makefile for:	xnee
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xnee
PORTVERSION=	0.7.a2
CATEGORIES=	x11
MASTER_SITES=	http://xnee.sourceforge.net/tars/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/alpha_/}
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${PERL} -pi -e 's,^CFLAGS =,CFLAGS +=,' ${WRKSRC}/src/cli/Makefile.in \
		${WRKSRC}/src/lib/Makefile.in

.include <bsd.port.mk>
