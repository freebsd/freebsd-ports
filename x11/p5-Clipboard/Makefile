# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Clipboard
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KING
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Access to X11 clipboard from Perl

BUILD_DEPENDS=	p5-Spiffy>=0:devel/p5-Spiffy
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		xclip:x11/xclip

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
