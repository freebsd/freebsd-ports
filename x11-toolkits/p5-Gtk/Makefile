# New ports collection makefile for:	p5-Gtk
# Version required:	0.2.0
# Date created:		28 Oct 1997
# Whom:	      		Vanilla I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.4 1998/05/06 07:20:45 vanilla Exp $
#

DISTNAME=	Gtk-0.2.0
PKGNAME=	p5-Gtk-0.2.0
CATEGORIES=	x11 lang perl5
MASTER_SITES=	ftp://ftp.gimp.org/pub/gtk/perl/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	gtk\\.1\\.1:${PORTSDIR}/x11/gtk

USE_PERL5=	YES

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include <bsd.port.mk>
