# Created by: Vanilla I. Shu <vanilla@MinJe.com.TW>
# $FreeBSD$

PORTNAME=	Gtk
PORTVERSION=	0.7010
PORTREVISION=	1
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-Perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The base module of Gtk-Perl

BUILD_DEPENDS=	p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USE_GNOME=	gtk12
USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	--without-guessing --lazy-load
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
