# New ports collection makefile for:	p5-Tk-DKW
# Date created:		16 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Tk-DKW
PORTVERSION=	0.03
PORTREVISION=	3
CATEGORIES=	x11-toolkits perl5 tk
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Collection of Tk widgets

BUILD_DEPENDS=	p5-Tk>=804:${PORTSDIR}/x11-toolkits/p5-Tk \
		p5-Tk-Contrib>=0.07:${PORTSDIR}/x11-toolkits/p5-Tk-Contrib
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
DKW_MODULES=	CheckBox Columns ComboEntry CornerBox DockFrame IconCanvas\
		Menustrip ProgressIndicator SplitFrame TabFrame TabbedForm\
		TableEdit
MAN3=		${DKW_MODULES:S/^/Tk::/:S/$/.3/}

post-extract:
	@${MV} ${WRKSRC}/Tk/* ${WRKSRC}/
	@${RMDIR} ${WRKSRC}/Tk/

.include <bsd.port.mk>
