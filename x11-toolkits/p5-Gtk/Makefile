# New ports collection makefile for:	p5-Gtk
# Version required:	0.3
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.14 1998/09/15 21:31:58 asami Exp $
#

DISTNAME=	Gtk-0.3
PKGNAME=	p5-Gtk-0.3
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk.1:${PORTSDIR}/x11-toolkits/gtk

USE_PERL5=	YES

MAN3=		GtkColorSelectButton.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
