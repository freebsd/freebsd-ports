# New ports collection makefile for:	p5-Gtk
# Version required:	0.2.1
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.5 1998/05/07 16:14:12 vanilla Exp $
#

DISTNAME=	Gtk-0.2.1
PKGNAME=	p5-Gtk-0.2.1
CATEGORIES=	x11 lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPA{}
MASTER_SITE_SUBDIR=	Gtk

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk\\.1\\.1:${PORTSDIR}/x11/gtk

USE_PERL5=	YES

MAN3=		GtkColorSelectButton.3
MANPREFIX=	${PREFIX}/lib/perl5

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
