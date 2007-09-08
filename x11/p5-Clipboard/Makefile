# New ports collection makefile for:	x11/p5-Clipboard
# Date created:				14 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Clipboard
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/K/KI/KING
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Access to X11 clipboard from Perl

BUILD_DEPENDS=	${SITE_PERL}/Spiffy.pm:${PORTSDIR}/devel/p5-Spiffy
RUN_DEPENDS=	${BUILD_DEPENDS} \
		xclip:${PORTSDIR}/x11/xclip

PERL_CONFIGURE=	yes

MAN1=	clipaccumulate.1 clipbrowse.1 clipedit.1 clipfilter.1 clipjoin.1
MAN3=	Clipboard.3

.include <bsd.port.mk>
