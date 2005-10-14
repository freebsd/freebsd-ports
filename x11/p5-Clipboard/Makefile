# New ports collection makefile for:	x11/p5-Clipboard
# Date created:				14 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Clipboard
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/K/KI/KING
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Access to X11 clipboard from Perl

BUILD_DEPENDS=	${SITE_PERL}/IO/All.pm:${PORTSDIR}/devel/p5-IO-All \
		${SITE_PERL}/Spiffy.pm:${PORTSDIR}/devel/p5-Spiffy
RUN_DEPENDS=	${BUILD_DEPENDS} \
		xclip:${PORTSDIR}/x11/xclip

PERL_CONFIGURE=	yes

MAN1=	clipaccumulate.1 clipbrowse.1 clipedit.1 clipjoin.1
MAN3=	Clipboard.3

post-patch:
	${PERL} -i -pe 's|/m;$$|/;|' \
		${WRKSRC}/lib/Clipboard/Xclip.pm

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
