# New ports collection makefile for:	p5-Gtk
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	Gtk
PORTVERSION=	0.7008
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer

USE_GNOMENG=	yes
USE_GNOME=	gtk12
PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-guessing --lazy-load

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Gtk.3pm \
		Gtk::CListModel.3pm \
		Gtk::cookbook.3pm \
		Gtk::objects.3pm \
		Gtk::reference.3pm

.include <bsd.port.mk>
