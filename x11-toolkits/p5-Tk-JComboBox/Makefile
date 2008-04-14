# New ports collection makefile for:	p5-Tk-JComboBox
# Date created:		31 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-JComboBox
PORTVERSION=	1.14
PORTREVISION=	2
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Contains a Label or Entry, a Button, and a Listbox

BUILD_DEPENDS=	p5-Tk>=804.027:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	${PORTNAME:S/-/::/g}.3 Tk::CWidget.3 Tk::JComboBox::tutorial.3

.include <bsd.port.mk>
