# New ports collection makefile for:	p5-Gtk2-GladeXML
# Date created:		2004-08-03
# Whom:			ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	Glade
PORTVERSION=	1.007
CATEGORIES=	x11-toolkits gnome perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/T/TS/TSCH/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	2
DISTNAME=	Gtk2-GladeXML-${PORTVERSION}

MAINTAINER=	ports@c0decafe.net
COMMENT=	Gtk2-Perl bindings to libglade2

EXTRACT_DEPENDS=${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends
BUILD_DEPENDS=	${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2

USE_GNOME=	libglade2
PERL_CONFIGURE=	yes

MAN3=	Gtk2::GladeXML.3

.include <bsd.port.mk>
