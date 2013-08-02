# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tk-Contrib
PORTVERSION=	0.07
PORTREVISION=	4
CATEGORIES=	x11-toolkits perl5 tk
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Contributed Tk widgets

BUILD_DEPENDS=	p5-Tk>=804:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
MAN3=		Tk::Axis.3 Tk::Dial.3 Tk::OlWm.3 Tk::TiedListbox.3

.include <bsd.port.mk>
