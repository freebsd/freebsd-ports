# New ports collection makefile for: Prima
# Date created:        27 July 2001
# Whom:                dmitry@karasik.eu.org
#
# $FreeBSD$
#

PORTNAME=	Prima
PORTVERSION=	1.05
CATEGORIES=	x11-toolkits perl5 graphics
MASTER_SITES=	http://www.prima.eu.org/download/
PKGNAMEPREFIX=	p5-

MAINTAINER=	dmitry@karasik.eu.org

LIB_DEPENDS=	ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

PERL_CONFIGURE=	yes

test: build
	cd ${WRKSRC} && make test

post-install:
	strip ${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/auto/Prima/Prima.so

.include <bsd.port.mk>
