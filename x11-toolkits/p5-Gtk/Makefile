# New ports collection makefile for:	p5-Gtk
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $FreeBSD$
#

PORTNAME=	p5-Gtk
PORTVERSION= 	0.7000
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/perl/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
DISTNAME=	Gtk-Perl-0.7000

MAINTAINER=	vanilla@FreeBSD.org

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib

USE_PERL5=	YES

MAN3=		Gtk::GtkColorSelectButton.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		--with-gdkimlib --without-gnome

.include <bsd.port.mk>
