# New ports collection makefile for:	p5-Gnome
# Date created:				30 Oct 2000
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Gnome
PORTVERSION=	0.7009
PORTREVISION=	5
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The main Gnome module of Gtk-Perl

BUILD_DEPENDS=	${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
		${SITE_PERL}/${PERL_ARCH}/Gtk/Gdk/ImlibImage.pm:${PORTSDIR}/x11-toolkits/p5-GdkImlib \
		${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk/Gdk/ImlibImage.pm:${PORTSDIR}/x11-toolkits/p5-GdkImlib \
		${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk

BROKEN=		fails to install
DEPRECATED=	Has been broken for more than 6 months
EXPIRATION_DATE=2008-09-19

USE_GNOME=	gnomelibs
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAN3=		Gnome.3pm \
		Gnome::reference.3pm

.include <bsd.port.mk>
