# New ports collection makefile for:	p5-Gnome
# Date created:				30 Oct 2000
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	Gnome
PORTVERSION=	0.7009
PORTREVISION=	1
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The main Gnome module of Gtk-Perl

BUILD_DEPENDS=	${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
		${SITE_PERL}/${PERL_ARCH}/Gtk/Gdk/ImlibImage.pm:${PORTSDIR}/x11-toolkits/p5-GdkImlib \
		${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk/Gdk/ImlibImage.pm:${PORTSDIR}/x11-toolkits/p5-GdkImlib \
		${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk

USE_GNOME=	gnomelibs
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAN3=		Gnome.3pm \
		Gnome::reference.3pm

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6.0 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
