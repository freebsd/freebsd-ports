# New ports collection makefile for:	p5-Gtk
# Version required:	0.4
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.20 1998/11/17 15:24:47 vanilla Exp $
#

DISTNAME=	Gtk-0.4
PKGNAME=	p5-Gtk-0.4
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	ftp://ftp.gtk.org/pub/gtk/perl/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11 \
		gdk_imlib.2:${PORTSDIR}/graphics/imlib

USE_PERL5=	YES

MAN3=		GtkColorSelectButton.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		--with-gdkimlib

.include <bsd.port.mk>
