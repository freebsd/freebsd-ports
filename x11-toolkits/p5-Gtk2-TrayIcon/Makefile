# New ports collection makefile for:	Gtk2-TrayIcon
# Date created:				Jan 11 2005
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Gtk2-TrayIcon
PORTVERSION=	0.06
PORTREVISION=	2
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BO/BORUP
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to the EggTrayIcon library

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Cairo.pm:${PORTSDIR}/graphics/p5-Cairo \
		${SITE_PERL}/ExtUtils/Depends.pm:${PORTSDIR}/devel/p5-ExtUtils-Depends	\
		${SITE_PERL}/ExtUtils/PkgConfig.pm:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Gtk2::TrayIcon.3

.include <bsd.port.mk>
