# New ports collection makefile for:	p5-Gtk
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	Gtk
PORTVERSION=	0.7005
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org

USE_GTK=	yes
PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-guessing --lazy-load

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		cookbook.3pm

.include <bsd.port.mk>
