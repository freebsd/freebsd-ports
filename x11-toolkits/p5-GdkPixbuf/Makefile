# New ports collection makefile for:	p5-GdkPixbuf
# Date created:				30 Oct 2000
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	GdkPixbuf
PORTVERSION=	0.7008
CATEGORIES=	x11-toolkits lang perl5 gnome
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAN3PREFIX=     ${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=		Gtk::Gdk::Pixbuf::reference.3pm

.include <bsd.port.mk>
