# New ports collection makefile for:	p5-Tk-Contrib
# Date created:		17 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-Contrib
PORTVERSION=	0.07
PORTREVISION=	3
CATEGORIES=	x11-toolkits perl5 tk
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Contributed Tk widgets

BUILD_DEPENDS=	p5-Tk>=804:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Tk::Axis.3 Tk::Dial.3 Tk::OlWm.3 Tk::TiedListbox.3

.include <bsd.port.mk>
