# New ports collection makefile for:	p5-Gtk2-PodViewer
# Date created:				2004-08-20
# Whom:					ports@c0decafe.net
#
# $FreeBSD$
#

PORTNAME=	Gtk2-PodViewer
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	x11-toolkits perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GB/GBROWN/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@c0decafe.net
COMMENT=	Gtk2-Perl widget and program for displaying POD

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		podviewer.1
MAN3=		Gtk2::PodViewer.3 Gtk2::PodViewer::Parser.3

.include <bsd.port.mk>
