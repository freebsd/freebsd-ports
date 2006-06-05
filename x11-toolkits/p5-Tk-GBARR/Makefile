# New ports collection makefile for:	p5-Tk-GBARR
# Date created:				May 28 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Tk-GBARR
PORTVERSION=	2.07
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Tk
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Some collection of Tk Widgets

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Tk.pm:${PORTSDIR}/x11-toolkits/p5-Tk
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Tk::Cloth.3 \
		Tk::FireButton.3 \
		Tk::NumEntry.3 \
		Tk::NumEntryPlain.3 \
		Tk::TFrame.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
