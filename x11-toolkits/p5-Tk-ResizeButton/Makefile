# New ports collection makefile for:	p5-Tk-ResizeButton
# Date created:							August 10th 2004
# Whom:									Lubomir Marinov <lubomir_m@abv.bg>
#
# $FreeBSD$
#

PORTNAME=		Tk-ResizeButton
PORTVERSION=	0.01
CATEGORIES=		x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=		Tk
PKGNAMEPREFIX=	p5-

MAINTAINER=		lubomir_m@abv.bg
COMMENT=		A resizeable button to be used in a Tk::HList column header

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=		${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=			Tk::ResizeButton.3

.include <bsd.port.mk>
