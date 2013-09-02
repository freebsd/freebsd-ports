# New ports collection makefile for:	p5-Tk-FontDialog
# Date created:		16 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-FontDialog
PORTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	x11-toolkits perl5 tk
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Font dialog widget

BUILD_DEPENDS=	p5-Tk>=804:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
MAN3=		${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
