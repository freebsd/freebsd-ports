# New ports collection makefile for:	x11-toolkits/p5-Tk-Splashscreen
# Date created:				02 December 2004
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-Splashscreen
PORTVERSION=	1.0
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Tk::Splashscreen, display a Splashscreen during program initialization

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Tk::Splashscreen.3 \
	Tk::waitVariableX.3

.include <bsd.port.mk>
