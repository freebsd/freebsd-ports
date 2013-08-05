# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Clipboard
PORTVERSION=	0.13
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KING
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Access to X11 clipboard from Perl

BUILD_DEPENDS=	p5-Spiffy>=0:${PORTSDIR}/devel/p5-Spiffy
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		xclip:${PORTSDIR}/x11/xclip

USES=		perl5
USE_PERL5=	configure

MAN1=	clipaccumulate.1 clipbrowse.1 clipedit.1 clipfilter.1 clipjoin.1
MAN3=	Clipboard.3

.include <bsd.port.mk>
