# New ports collection makefile for:	p5-Gtk
# Version required:	0.2.2
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.10 1998/08/06 15:06:24 vanilla Exp $
#

DISTNAME=	Gtk-0.2.2
PKGNAME=	p5-Gtk-0.2.2
CATEGORIES=	x11-toolkits lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk\\.1\\.:${PORTSDIR}/x11/gtk

USE_PERL5=	YES

MAN3=		GtkColorSelectButton.3
MANPREFIX=	${PREFIX}/lib/perl5/5.00501

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
